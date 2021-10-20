
#include <cassert>
#include <codecvt>

#include "window.h"

#include <Windows.h>
#include <ShellAPI.h>

#include <WinTrust.h>
#include <SoftPub.h>

bool VerifySignature(LPCWSTR);

void window_callback(Fl_Widget *w, void *)
{
    // 按 Esc 不退出, 而是还原默认窗口大小
    if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    {
        if (Fl::screen_scale(((Fl_Double_Window *)w)->screen_num()) != 1.0f)
            Fl::screen_scale(((Fl_Double_Window *)w)->screen_num(), 1.0f);
        return;
    }

    if (((Pt::Window *)w)->window_spawn->shown() == 1)
        ((Pt::Window *)w)->window_spawn->hide();
    ((Pt::Window *)w)->hide();
}

void callback_pvz_check(void *w)
{
    // 定期检查游戏进程状态
    bool on = ((Pt::Window *)w)->pvz->GameOn();
    double t = on ? 0.4 : 0.2;
    Fl::repeat_timeout(t, callback_pvz_check, w);
}

static_assert(_MSC_VER >= 1916);
static_assert(sizeof(void *) == 4);

/// main ///

int main(int argc, char **argv)
{
    // 初始化随机数种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

#ifdef _DEBUG
    // 调试输出中文
    // 我也不知道为什么加这些就有用
    // It just works!
    system("chcp 65001");
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
    std::wcout.imbue(loc);
#endif

    // 测试版在 2022-12-31 之后失效
    if (TEST_VERSION && (std::time(nullptr) > std::time_t(1672502399)))
    {
        if (MessageBoxW(nullptr, L"这是很久以前的测试版哦，现在去下载新的正式版吗？", //
                        L"测试版过期提示", MB_OKCANCEL) == IDOK)
            ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", //
                          nullptr, nullptr, SW_SHOWNORMAL);
        return -1;
    }

#ifndef _DEBUG
    wchar_t exePath[MAX_PATH] = {0};
    GetModuleFileNameW(NULL, exePath, MAX_PATH);
    if (!VerifySignature(exePath))
    {
        if (MessageBoxW(nullptr, L"本程序可能已经感染病毒，请在官方渠道重新下载！", //
                        L"PvZ Toolkit 防篡改检测", MB_OKCANCEL) == IDOK)
            ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", //
                          nullptr, nullptr, SW_SHOWNORMAL);
        return -2;
    }
#endif

    // 只运行单个实例
    HANDLE m = CreateMutexW(nullptr, true, L"PvZ Toolkit");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return -3;

    // 第一次调用时启用线程锁机制
    Fl::lock();

    // 主窗口
    Pt::Window window(0, 0, "");
    window.callback(window_callback);
    window.show(argc, argv);
    window.pvz->FindPvZ();

#ifndef _DEBUG // 避免调试的时候频繁输出
    Fl::add_timeout(0.01, callback_pvz_check, &window);
#endif

    int ret = Fl::run();

    // 结束主循环后再释放
    ReleaseMutex(m);
    CloseHandle(m);

    return ret;
}

bool VerifySignature(LPCWSTR pwszSourceFile)
{
    bool isGoodSignature = false;

    WINTRUST_FILE_INFO FileData;
    memset(&FileData, 0, sizeof(FileData));
    FileData.cbStruct = sizeof(WINTRUST_FILE_INFO);
    FileData.pcwszFilePath = pwszSourceFile;
    FileData.hFile = NULL;
    FileData.pgKnownSubject = NULL;

    GUID WVTPolicyGUID = WINTRUST_ACTION_GENERIC_VERIFY_V2;
    WINTRUST_DATA WinTrustData;
    memset(&WinTrustData, 0, sizeof(WinTrustData));
    WinTrustData.cbStruct = sizeof(WinTrustData);
    WinTrustData.pPolicyCallbackData = NULL;
    WinTrustData.pSIPClientData = NULL;
    WinTrustData.dwUIChoice = WTD_UI_NONE;
    WinTrustData.fdwRevocationChecks = WTD_REVOKE_NONE;
    WinTrustData.dwUnionChoice = WTD_CHOICE_FILE;
    WinTrustData.dwStateAction = WTD_STATEACTION_VERIFY;
    WinTrustData.hWVTStateData = NULL;
    WinTrustData.pwszURLReference = NULL;
    WinTrustData.dwUIContext = 0;
    WinTrustData.pFile = &FileData;

    LONG lStatus = WinVerifyTrust(NULL, &WVTPolicyGUID, &WinTrustData);
    // wprintf_s(L"WinVerifyTrust lStatus is: 0x%x.\n", lStatus);

    // isGoodSignature = (lStatus == ERROR_SUCCESS || lStatus == CERT_E_CHAINING || lStatus == TRUST_E_COUNTER_SIGNER);
    isGoodSignature = (lStatus != TRUST_E_NOSIGNATURE && lStatus != TRUST_E_BAD_DIGEST);

    WinTrustData.dwStateAction = WTD_STATEACTION_CLOSE;
    lStatus = WinVerifyTrust(NULL, &WVTPolicyGUID, &WinTrustData);

    if (!isGoodSignature)
        return false;

    HCERTSTORE hStore = NULL;
    HCRYPTMSG hMsg = NULL;
    CryptQueryObject(CERT_QUERY_OBJECT_FILE, pwszSourceFile,     //
                     CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED, //
                     CERT_QUERY_FORMAT_FLAG_BINARY,              //
                     0, NULL, NULL, NULL, &hStore, &hMsg, NULL);

    DWORD dwSignerInfo = 0;
    CryptMsgGetParam(hMsg, CMSG_SIGNER_INFO_PARAM, 0, NULL, &dwSignerInfo);
    PCMSG_SIGNER_INFO pSignerInfo = (PCMSG_SIGNER_INFO)LocalAlloc(LPTR, dwSignerInfo);
    CryptMsgGetParam(hMsg, CMSG_SIGNER_INFO_PARAM, 0, (PVOID)pSignerInfo, &dwSignerInfo);

    CERT_INFO CertInfo;
    memset(&CertInfo, 0, sizeof(CertInfo));
    CertInfo.Issuer = pSignerInfo->Issuer;
    CertInfo.SerialNumber = pSignerInfo->SerialNumber;
    PCCERT_CONTEXT pCertContext =                                                   //
        CertFindCertificateInStore(hStore, X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, //
                                   0, CERT_FIND_SUBJECT_CERT, (PVOID)&CertInfo, NULL);

    const DWORD size = 16;
    if (pCertContext->pCertInfo->SerialNumber.cbData == size)
    {
        char snRead[size + 1];
        for (DWORD i = 0; i < size; i++)
            snRead[i] = pCertContext->pCertInfo->SerialNumber.pbData[size - (i + 1)];
        snRead[size] = 0;
        char snCheck[] = "\x67\x4e\x6f\xa6\xf6\xc0\x13\x97\x47\xa4\xa9\x54\x3e\xfd\x7f\x30";
        isGoodSignature = strcmp(snRead, snCheck) == 0;
    }
    else
    {
        isGoodSignature = false;
    }

    CertFreeCertificateContext(pCertContext);
    CertCloseStore(hStore, 0);
    CryptMsgClose(hMsg);
    LocalFree(pSignerInfo);

    return isGoodSignature;
}
