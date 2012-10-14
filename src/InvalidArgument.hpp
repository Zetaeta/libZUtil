
#ifndef INVALIDARGUMENT_HPP
#define INVALIDARGUMENT_HPP

#include <string>
#include <stdexcept>

namespace Util {

class InvalidArgument : public std::runtime_error {
public:
    InvalidArgument(const std::string &what = "")
    :std::runtime_error(what) {
    }
};

}

#endif
