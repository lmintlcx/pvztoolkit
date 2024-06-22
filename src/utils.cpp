
#include "../inc/utils.h"

namespace Pt
{

std::size_t base64_encode(void *dst, void const *src, std::size_t len)
{
    static char tab[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ" //
        "abcdefghijklmnopqrstuvwxyz" //
        "0123456789"                 //
        "+/"                         // -_
    };

    char *out = static_cast<char *>(dst);
    char const *in = static_cast<char const *>(src);

    for (auto n = len / 3; n--;)
    {
        *out++ = tab[(in[0] & 0xfc) >> 2];
        *out++ = tab[((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4)];
        *out++ = tab[((in[2] & 0xc0) >> 6) + ((in[1] & 0x0f) << 2)];
        *out++ = tab[in[2] & 0x3f];
        in += 3;
    }

    switch (len % 3)
    {
    case 2:
        *out++ = tab[(in[0] & 0xfc) >> 2];
        *out++ = tab[((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4)];
        *out++ = tab[(in[1] & 0x0f) << 2];
        *out++ = '=';
        break;

    case 1:
        *out++ = tab[(in[0] & 0xfc) >> 2];
        *out++ = tab[((in[0] & 0x03) << 4)];
        *out++ = '=';
        *out++ = '=';
        break;

    case 0:
        break;
    }

    return out - static_cast<char *>(dst);
}

std::size_t base64_decode(void *dst, char const *src, std::size_t len)
{
    static signed char inverse[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //   0-15
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //  16-31
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, 62, -1, 63, //  32-47
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, //  48-63
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,           //  64-79
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, 63, //  80-95
        -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, //  96-111
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, // 112-127
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 128-143
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 144-159
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 160-175
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 176-191
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 192-207
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 208-223
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 224-239
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1  // 240-255
    };

    char *out = static_cast<char *>(dst);
    auto in = reinterpret_cast<unsigned char const *>(src);

    unsigned char c3[3], c4[4] = {0, 0, 0, 0};
    int i = 0;
    int j = 0;

    while (len-- && *in != '=')
    {
        auto const v = inverse[*in];
        if (v == -1)
            break;
        ++in;
        c4[i] = v;
        if (++i == 4)
        {
            c3[0] = (c4[0] << 2) + ((c4[1] & 0x30) >> 4);
            c3[1] = ((c4[1] & 0xf) << 4) + ((c4[2] & 0x3c) >> 2);
            c3[2] = ((c4[2] & 0x3) << 6) + c4[3];

            for (i = 0; i < 3; i++)
                *out++ = c3[i];
            i = 0;
        }
    }

    if (i)
    {
        c3[0] = (c4[0] << 2) + ((c4[1] & 0x30) >> 4);
        c3[1] = ((c4[1] & 0xf) << 4) + ((c4[2] & 0x3c) >> 2);
        c3[2] = ((c4[2] & 0x3) << 6) + c4[3];

        for (j = 0; j < i - 1; j++)
            *out++ = c3[j];
    }

    return out - static_cast<char *>(dst);
}

std::string utf8_encode(const std::wstring &wstr)
{
    if (wstr.empty())
        return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), nullptr, 0, nullptr, nullptr);
    std::string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, nullptr, nullptr);
    return str;
}

std::wstring utf8_decode(const std::string &str)
{
    if (str.empty())
        return std::wstring();
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), nullptr, 0);
    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
    return wstr;
}

bool VerifySignature(LPCWSTR pwszSourceFile, const char *snCheck)
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

    [[maybe_unused]] bool sig_good = (lStatus == ERROR_SUCCESS || lStatus == CERT_E_CHAINING || lStatus == TRUST_E_COUNTER_SIGNER);
    [[maybe_unused]] bool sig_not_bad = (lStatus != TRUST_E_NOSIGNATURE && lStatus != TRUST_E_BAD_DIGEST);
    isGoodSignature = sig_not_bad; // TODO

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

// https://learn.microsoft.com/zh-cn/windows/win32/seccrypto/example-c-program--creating-an-md-5-hash-from-file-content
bool VerifyFileHash(LPCWSTR file_name, const char *file_md5)
{
    const int BUFSIZE = 1024;
    const int MD5LEN = 16;

    BOOL bResult = FALSE;
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HANDLE hFile = NULL;
    BYTE rgbFile[BUFSIZE];
    DWORD cbRead = 0;
    BYTE rgbHash[MD5LEN];
    DWORD cbHash = 0;
    CHAR rgbDigits[] = "0123456789abcdef";

    hFile = CreateFile(file_name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return false;

    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
    {
        CloseHandle(hFile);
        return false;
    }

    if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
    {
        CloseHandle(hFile);
        CryptReleaseContext(hProv, 0);
        return false;
    }

    while (bResult = ReadFile(hFile, rgbFile, BUFSIZE, &cbRead, NULL))
    {
        if (0 == cbRead)
            break;
        if (!CryptHashData(hHash, rgbFile, cbRead, 0))
        {
            CryptReleaseContext(hProv, 0);
            CryptDestroyHash(hHash);
            CloseHandle(hFile);
            return false;
        }
    }

    if (!bResult)
    {
        CryptReleaseContext(hProv, 0);
        CryptDestroyHash(hHash);
        CloseHandle(hFile);
        return false;
    }

    cbHash = MD5LEN;
    if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
    {
        std::string md5_hash;
        for (DWORD i = 0; i < cbHash; i++)
        {
            md5_hash += rgbDigits[rgbHash[i] >> 4];
            md5_hash += rgbDigits[rgbHash[i] & 0xf];
        }
        // std::cout << md5_hash << std::endl;
        return md5_hash == file_md5;
    }

    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
    CloseHandle(hFile);

    return false;
}

} // namespace Pt
