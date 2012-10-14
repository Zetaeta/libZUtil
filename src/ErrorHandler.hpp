
#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include <string>

#include "ErrorType.hpp"

namespace Util {

void throwException(int errorCode, const std::string & = "");

std::string getMessage(int errorCode, ErrorType::ErrorType type);

inline void throwException(int errorCode, ErrorType::ErrorType type) {
    throwException(errorCode, getMessage(errorCode, type));
}

}

#endif

