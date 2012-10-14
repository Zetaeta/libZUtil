
#ifndef UNICODE_HPP
#define UNICODE_HPP

#include <stdint.h>
#include <stddef.h>

#include "stlfwd.hpp"

namespace Util {

std::vector<uint16_t> utf8ToUcs2(const std::string &);
std::string ucs2ToUtf8(const std::vector<uint16_t> &);

uint32_t utf8ToCodePoint(const std::string &utf8, size_t &position);

void codePointToUtf8(uint32_t codePoint, std::string &utf8);

}

#endif

