
#include <string>
#include <stdexcept>
#include <cxxabi.h>
#include <algorithm>
#include <iostream>

#include "StringUtils.hpp"

using std::string;
using std::vector;
using std::cout;

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

bool endsWith(const string &str, const string &ending) {
    if (str.size() > ending.size()) {
        return str.compare(str.size() - ending.size(), ending.size(), ending) == 0;
    }
    else {
        return false;
    }
}

bool startsWith(const string &str, const string &start) {
    if (str.size() > start.size()) {
        return str.compare(0, start.size(), start) == 0;
    }
    else {
        return false;
    }
}

string toLower(const std::string &str) {
    string lower(str);
    std::transform(lower.begin(), lower.end(), lower.begin(), tolower);
    return lower;
}


vector<string> split(const std::string &str, const string &splitter) {
    size_t index = 0;
    size_t prevIndex = 0;
    vector<string> v;
    while (index != string::npos) {
        index = str.find(splitter, prevIndex);
        if (index != string::npos) {
            v.push_back(str.substr(prevIndex, index - prevIndex));
        }
        else {
            v.push_back(str.substr(prevIndex));
        }
        prevIndex = index + splitter.size();
    }
    return v;
}

}

