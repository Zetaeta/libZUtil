
#ifndef IOERROR_HPP
#define IOERROR_HPP

#include "IOException.hpp"

namespace Util {

class IOError : public IOException {
public:
    IOError(const std::string &what = "IOError")
    :IOException(what) {}
};

}

#endif

