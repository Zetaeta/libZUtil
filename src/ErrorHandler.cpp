
#include <errno.h>
#include <string.h>
#include <sstream>

#include "ErrorHandler.hpp"
#include "InvalidFileDescriptor.hpp"
#include "IOError.hpp"
#include "InvalidIOOperation.hpp"
#include "InvalidArgument.hpp"

using std::string;
using namespace Util::ErrorType;

namespace Util {

void _throwException(const std::string &file, int line, int errorCode,
                     const string &message, ErrorType::ErrorType type) {
    std::ostringstream msg_;
    msg_ << strerror(errorCode);
    if (message != "") {
        msg_ << ": " << message;
    }
    msg_ << " at " << file << ":" << line;
    std::string msg = msg_.str();
    switch (errorCode) {
    case EBADF:
        throw InvalidFileDescriptor(msg);
    case EINVAL:
        throw InvalidArgument(msg);
    case EISDIR:
        throw InvalidIOOperation(msg);
    case EIO:
        throw IOError(msg);
    case EPIPE:
        if (type == DEFAULT) {
            
        }
    default:
        throw std::runtime_error(msg);
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

    return strerror(errorCode);
}

}
