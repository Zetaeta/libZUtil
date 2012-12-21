
#ifndef EOFEXCEPTION_HPP
#define EOFEXCEPTION_HPP

#include "IOException.hpp"

namespace Util {

class EOFException : public IOException {
public:
    EOFException(const std::string &msg = "")
    :IOException(msg) {}
};

}

#endif
