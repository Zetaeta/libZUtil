
#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include <string>

#include "ErrorType.hpp"

namespace Util {

void _throwException(const std::string &file, int line,\
                     int errorCode, const std::string &, ErrorType::ErrorType = ErrorType::DEFAULT);

std::string getMessage(int errorCode, ErrorType::ErrorType type);

inline void _throwException(const std::string &file, int line,\
                            int errorCode, ErrorType::ErrorType type = ErrorType::DEFAULT) {
    _throwException(file, line, errorCode, getMessage(errorCode, type), type);
}

#define throwException(...) \
    Util::_throwException(__FILE__, __LINE__, __VA_ARGS__)

}

#endif

