
#include <errno.h>
#include <string.h>

#include "ErrorHandler.hpp"
#include "InvalidFileDescriptor.hpp"
#include "IOError.hpp"
#include "InvalidIOOperation.hpp"
#include "InvalidArgument.hpp"

using std::string;

namespace Util {

void throwException(int errorCode, const string &message) {
    switch (errorCode) {
    case EBADF:
        throw InvalidFileDescriptor(message != "" ? message : strerror(errorCode));
    case EINVAL:
        throw InvalidArgument(message != "" ? message : strerror(errorCode));
    case EISDIR:
        throw InvalidIOOperation(message != "" ? message : strerror(errorCode));
    case EIO:
        throw IOError(message != "" ? message : strerror(errorCode));
    default:
        throw std::runtime_error(message != "" ? message : strerror(errorCode));
    }
}

std::string getMessage(int errorCode, ErrorType::ErrorType type) {
    switch (errorCode) {
    case EPERM:
        if (type == ErrorType::PTHREAD_LOCK) {
            return "Lock or mutex not held by caller!\n";
        }
        break;
    }

    def:
    return strerror(errorCode);
}

}
