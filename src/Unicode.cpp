
#include <bitset>
#include <vector>
#include <iostream>

#include "Unicode.h"

using std::string;
using std::vector;
using std::cerr;

namespace MCServer {

vector<uint16_t> utf8ToUcs2(const string &utf8) {
    vector<uint16_t> result;
    result.reserve(utf8.size());
    size_t position;
    for (position = 0; position < utf8.size();) {
        uint32_t codePoint = utf8ToCodePoint(utf8, position);
        result.push_back(static_cast<uint16_t>(codePoint));
    }
    return result;
}

string ucs2ToUtf8(const vector<uint16_t> &ucs2) {
    string result;
    size_t position;
    for (position = 0; position < ucs2.size(); ++position) {
        uint32_t codePoint = ucs2[position];
        codePointToUtf8(codePoint, result);
    }
    return result;
}

uint32_t utf8ToCodePoint(const string &utf8, size_t &pos) {
    unsigned char ch = utf8[pos++];
    unsigned int length;
    if ((ch & 0x80) == 0) {
        length = 1;
    }
    else if ((ch & (0x80 | 0x40 | 0x20)) == (0x80 | 0x40)) {
        length = 2;
    }
    else if ((ch & (0x80 | 0x40 | 0x20 | 0x10)) == (0x80 | 0x40 | 0x20)) {
        length = 3;
    }
    else if ((ch & (0x80 | 0x40 | 0x20 | 0x10 | 0x08)) == (0x80 | 0x40 | 0x20)) {
        length = 4;
    }
    else {
        cerr << "Invalid character while converting UTF-8: " << ch << ", bits = " << std::bitset<8>(ch) << ", pos = " << pos << '\n';
        return -1;
    }
    switch (length) {
    case 1:
        return ch;
        break;
    case 2: {
        unsigned char ch2 = utf8[pos++];
        if ((ch2 & (0x80 | 0x40)) != 0x80) {
            cerr << "Invalid UTF-8 trailing character: " << ch2 << '\n';
            return -1;
        }
        return (ch & ~(0x80 | 0x40)) << 6 | (ch2 & ~0x80);
    }
    case 3: {
        unsigned char ch2 = utf8[pos++];
        unsigned char ch3 = utf8[pos++];
        if ((ch2 & (0x80 | 0x40)) != 0x80) {
            cerr << "Invalid UTF-8 trailing character: " << ch2 << '\n';
            return -1;
        }
        if ((ch3 & (0x80 | 0x40)) != 0x80) {
            cerr << "Invalid UTF-8 trailing character: " << ch3 << '\n';
            return -1;
        }
        uint32_t u1 = (ch & ~(0x80 | 0x40 | 0x20));
        uint32_t u2 = (ch2 & ~0x80);
        uint32_t u3 = (ch3 & ~0x80);
        return u1 << 12 | u2 << 6 | u3;
    }
    case 4: {
        unsigned char ch2 = utf8[pos++];
        unsigned char ch3 = utf8[pos++];
        unsigned char ch4 = utf8[pos++]; 
        if ((ch2 & (0x80 | 0x40)) != 0x80) {
            cerr << "Invalid UTF-8 trailing character: " << ch2 << '\n';
            return -1;
        }
        if ((ch3 & (0x80 | 0x40)) != 0x80) {
            cerr << "Invalid UTF-8 trailing character: " << ch3 << '\n';
            return -1;
        }
        if ((ch4 & (0x80 | 0x40)) != 0x80) {
            cerr << "Invalid UTF-8 trailing character: " << ch4 << '\n';
            return -1;
        }
        return (ch & ~(0x80 | 0x40 | 0x20 | 0x10)) << 18 | (ch2 & ~0x80) << 12 | (ch3 & ~0x80);
    }
    default:
        cerr << "Invalid UTF-8 character length: " << length << '\n';
        return -1;
    }
}

void codePointToUtf8(uint32_t codePoint, std::string &utf8) {
    int length = 0;
    if (codePoint >= 0x200000) {
        cerr << "Invalid UTF-8 code point: " << codePoint << '\n';
        return;
    }
    if (codePoint >= 0x10000) {
        length = 4;
    }
    else if (codePoint >= 0x800) {
        length = 3;
    }
    else if (codePoint >= 0x80) {
        length = 2;
    }
    else {
        length = 1;
    }
//    log << "length = " << length << '\n';
    switch (length) {
    case 1:
        utf8 += static_cast<unsigned char>(codePoint);
        break;
    case 2: {
        unsigned char ch1 = ((codePoint >> 6) & ~0x20) | (0x80 | 0x40); 
        unsigned char ch2 = (codePoint & ~0x40) | 0x80;
        utf8 += ch1;
        utf8 += ch2;
        break;
    }
    case 3: {
        unsigned char ch1 = ((codePoint >> 12) & ~0x10) | (0x80 | 0x40 | 0x20); 
        unsigned char ch2 = ((codePoint >> 6) & ~0x40) | 0x80;
        unsigned char ch3 = (codePoint & ~0x40) | 0x80;
        utf8 += ch1;
        utf8 += ch2;
        utf8 += ch3;
        break;
    }
    case 4: {
        unsigned char ch1 = ((codePoint >> 18) & ~0x08) | (0x80 | 0x40 | 0x20 | 0x10); 
        unsigned char ch2 = ((codePoint >> 12) & ~0x40) | 0x80;
        unsigned char ch3 = ((codePoint >> 6) & ~0x40) | 0x80;
        unsigned char ch4 = (codePoint & ~0x40) | 0x80;
        utf8 += ch1;
        utf8 += ch2;
        utf8 += ch3;
        utf8 += ch4;
        break;
    }
    }
}

}
