
#ifndef THROW_HPP
#define THROW_HPP

#include <string>
#include <sstream>
#include <typeinfo>

#include "StringUtils.hpp"

namespace Util {

using std::string;

template <typename T>
void _throwSpecific(const string &file, int line, const string &message) {
    std::ostringstream oss;
    oss << demangle(typeid(T).name());
    if (message != "") {
        oss << ": " << message;
    }
    oss << " at " << file << ":" << line;
    throw T(oss.str());
}

#define throwSpecific(Type, message) \
    Util::_throwSpecific<Type>(__FILE__, __LINE__, message)

}

#endif
