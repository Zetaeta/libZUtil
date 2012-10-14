
#ifndef INVALIDFILEDESCRIPTOR_HPP
#define INVALIDFILEDESCRIPTOR_HPP

#include "IOException.hpp"

namespace Util {

class InvalidFileDescriptor : public IOException {
public:
    InvalidFileDescriptor(const std::string &what)
    :IOException(what) {
    }
};

}

#endif

