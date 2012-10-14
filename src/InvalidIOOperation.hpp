
#ifndef INVALIDIOOPERATION_HPP
#define INVALIDIOOPERATION_HPP

#include "IOException.hpp"

namespace Util {

class InvalidIOOperation : public IOException {
public:
    InvalidIOOperation(const std::string &what = "InvalidIOOperation")
    :IOException(what) {}
};

}

#endif

