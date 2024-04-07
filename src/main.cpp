
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Tooltip.H>
#include <FL/fl_ask.H>
#include <FL/Fl.H>

#include <Windows.h>
#include <WinTrust.h>
#include <SoftPub.h>
#include <VersionHelpers.h>

#include <cassert>
#include <random>
#include <ctime>

#include "toolkit.h"
#include "../res/version.h"

#define IDI_ICON 1001

static_assert(_MSC_VER >= 1929);
static_assert(sizeof(void *) == 4);

bool VerifySignature(LPCWSTR);

void window_callback(Fl_Widget *w, void *)
{
    // Press Esc to not exit, but to restore the default window size
    if (Fl::event() == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    {
        if (Fl::screen_scale(((Fl_Double_Window *)w)->screen_num()) != 1.0f)
            Fl::screen_scale(((Fl_Double_Window *)w)->screen_num(), 1.0f);
        return;
    }

    ((Pt::Toolkit *)w)->close_all_sub_window();
    ((Pt::Toolkit *)w)->hide();
}

void callback_pvz_check(void *w)
{
    // Check the status of the game process regularly
    bool on = ((Pt::Toolkit *)w)->pvz->GameOn();
    double t = on ? 0.4 : 0.2;
    Fl::repeat_timeout(t, callback_pvz_check, w);

    if (IsDebuggerPresent())
        exit(-42);
}

/// main ///

Fl_Font ui_font = FL_FREE_FONT + 1; // Main interface
Fl_Font ls_font = FL_FREE_FONT + 2; // Formation code
Fl_Font tt_font = FL_FREE_FONT + 3; // Prompt message

int main(int argc, char **argv)
{
#ifdef _DEBUG
    system("chcp 65001"); // Debug output Chinese
#endif

#ifdef _DEBUG
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
#endif

    if (argc == 0)
        return -0;

    if (argc == 4)
    {
        std::string m = argv[1];
        std::string file = argv[2];
        std::string dir = argv[3];

        Pt::PAK pak;
        if (m == "/U")
            return pak.Unpack(file, dir);
        else if (m == "/P")
            return pak.Pack(dir, file);
        else
            return 0xF7;
    }

    // Interface background color
    Fl::background(243, 243, 243);

    // Interface font
    Fl::set_font(ui_font, "Arial");
    Fl::set_font(ls_font, "Courier New");
    Fl::set_font(tt_font, "Segoe UI");

    // Set dialog box properties
    fl_message_font(ui_font, 13);
    fl_message_hotspot(1);

	//fl_cancel= "Cancel";
	//fl_close= "Close";
	//fl_no = "No";
	//fl_ok = "OK";
	//fl_yes = "Yes";

    // Set the style of the tooltip
    Fl_Tooltip::delay(0.1f);
    Fl_Tooltip::hoverdelay(0.1f);
    Fl_Tooltip::hidedelay(5.0f);
    Fl_Tooltip::color(FL_WHITE);
    Fl_Tooltip::textcolor(FL_BLACK);
    Fl_Tooltip::font(tt_font);
    Fl_Tooltip::size(12);
    Fl_Tooltip::margin_width(5);
    Fl_Tooltip::margin_height(5);
    Fl_Tooltip::wrap_width(400);

    // Initialize random number seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Enable the thread lock mechanism on the first call
    Fl::lock();

    // Startup screen

    Fl_Window splash(400 + 2, 225 + 2, "");
    splash.begin();
    Fl_Box box(1, 1, 400, 225, nullptr);
    splash.end();

    box.labelsize(42);
    box.labelcolor(FL_GRAY);
    splash.color(FL_GRAY);
    splash.border(false);
    splash.set_non_modal();

    Fl_JPEG_Image img_jpeg("splash.jpg");
    Fl_PNG_Image img_png("splash.png");
    Fl_BMP_Image img_bmp("splash.bmp");

    if (img_jpeg.fail() == 0)
        box.image(img_jpeg);
    else if (img_png.fail() == 0)
        box.image(img_png);
    else if (img_bmp.fail() == 0)
        box.image(img_bmp);
    else
        box.label("PvZ Toolkit");

    if (box.image())
    {
        int w = box.image()->w();
        int h = box.image()->h();
        box.size(w, h);
        splash.size(w + 2, h + 2);
    }

    // Set the title bar icon before the first window is displayed
    extern HINSTANCE fl_display;
    splash.icon((const void *)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));

    splash.position((Fl::w() - splash.w()) / 2, (Fl::h() - splash.h()) / 2);
    splash.show();
    splash.wait_for_expose();

    splash.color(box.image() ? FL_GREEN : FL_DARK_GREEN);

    clock_t start = clock(); // start the timer

    // System requirements

    if (!IsWindowsVistaOrGreater())
    {
        fl_message_title("PvZ Toolkit");
        fl_alert("The operating system being used is not supported! \n"
                 "Requires Windows Vista or higher to run.");
        return -10;
    }

    // The beta version expires after 2023-12-31 23:59:59
    if (!RELEASE_VERSION && (std::time(nullptr) > std::time_t(1704038399)))
    {
        fl_message_title("Test version expiration reminder");
        if (fl_choice("This was a beta version a long time ago. Do you want to download the new official version now?", //
                      "No", "Yes", 0) == 1)
            ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", //
                          nullptr, nullptr, SW_SHOWNORMAL);
        return -1;
    }

    // Tamper-proof detection
    if (SIGNATURE_CHECK)
    {
        wchar_t exePath[MAX_PATH] = {0};
        GetModuleFileNameW(NULL, exePath, MAX_PATH);
        if (!VerifySignature(exePath))
        {
            fl_message_title("PvZ Toolkit Tamper Detection");
            if (fl_choice("This program may have been infected with a virus, please download it again from official channels!", //
                          "No", "Yes", 0) == 1)
                ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", //
                              nullptr, nullptr, SW_SHOWNORMAL);
            return -2;
        }
    }

    // Run only a single instance
    HANDLE m = CreateMutexW(nullptr, true, L"PvZ Toolkit");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return -3;

    // Main window
    Pt::Toolkit pvztoolkit(0, 0, "");
    pvztoolkit.callback(window_callback);

#ifdef _DEBUG
    std::wcout << L"Startup time (milliseconds): " << (clock() - start) << std::endl;
    // pvztoolkit.input_sun->value(clock() - start);
#endif

    // Hide the startup screen

    double dt = 0.017; // Minimum display time
    while ((clock() - start) / (double)CLOCKS_PER_SEC < dt)
        Fl::check();
    splash.hide();
    Fl::check();

    // Show main window

    pvztoolkit.show(1, argv); // argc -> 1
    pvztoolkit.wait_for_expose();
    pvztoolkit.pvz->FindPvZ();
    SetForegroundWindow(fl_xid(&pvztoolkit));

#ifdef _DEBUG
    // Avoid frequent output during debugging
#else
    Fl::add_timeout(0.01, callback_pvz_check, &pvztoolkit);
#endif

    int ret = Fl::run();

    // Release after the main cycle is over
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
        char snCheck[] = "\x21\x13\x67\x0f\x3b\x6c\x60\xaf\x42\x50\x7f\x07\xd3\x97\xbc\xd6";
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
