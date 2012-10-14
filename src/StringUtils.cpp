
#include <string>
#include <stdexcept>
#include <cxxabi.h>

#include "StringUtils.hpp"

using std::string;

namespace Util {

string demangle(const string &name) {
    int status;
    char *result = abi::__cxa_demangle(name.c_str(), NULL, NULL, &status);
    if (status == 0) {
        string ret(result);
        free(result);
        return ret;
    }
    else {
        throw std::logic_error("Invalid mangled name: " + name);
    }
}

}

