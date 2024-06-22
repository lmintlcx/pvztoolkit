
#include "vc141_nt5.h"

extern "C" PVOID WINAPI
fake_DecodePointer(PVOID Ptr)
{
    return Ptr;
}

extern "C" PVOID WINAPI
fake_EncodePointer(PVOID Ptr)
{
    return Ptr;
}

extern "C" BOOL WINAPI
fake_GetModuleHandleExW(DWORD dwFlags, LPCWSTR lpModuleName, HMODULE *phModule)
{
    UNREFERENCED_PARAMETER(dwFlags);
    UNREFERENCED_PARAMETER(lpModuleName);
    UNREFERENCED_PARAMETER(phModule);

    return FALSE;
}

extern "C" void WINAPI
fake_InitializeSListHead(PSLIST_HEADER ListHead)
{
    ListHead->Alignment = 0;
}
