
#ifndef UNICODE_HPP
#define UNICODE_HPP

#include <stdint.h>
#include <stddef.h>

#include "stlfwd.hpp"

#ifndef __size_t__
#error "__size_t__ is not defined!"
#endif

#ifdef __cplusplus

std::vector<uint16_t> utf8ToUcs2(const std::string &);
std::string ucs2ToUtf8(const std::vector<uint16_t> &);

extern "C" {
#endif

uint32_t utf8ToCodePoint(const std::string &utf8, size_t &position);

void codePointToUtf8(uint32_t codePoint, std::string &utf8);

#ifdef __cplusplus
}
#endif

#endif
