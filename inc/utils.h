
#pragma once

#include <Windows.h>

#include <SoftPub.h>
#include <WinTrust.h>

#include <string>

namespace Pt
{

std::size_t base64_encode(void *dst, void const *src, std::size_t len);
std::size_t base64_decode(void *dst, char const *src, std::size_t len);

std::string utf8_encode(const std::wstring &);
std::wstring utf8_decode(const std::string &);

bool VerifySignature(LPCWSTR, const char *);

bool VerifyFileHash(LPCWSTR, const char *);

} // namespace Pt
