
#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include "stlfwd.hpp"

namespace Util {

std::string demangle(const std::string &);

bool endsWith(const std::string &string, const std::string &ending);
bool startsWith(const std::string &string, const std::string &start);

// Template function to check ending, useful for "Plugins::PluginLoaderRule"'s
template<const char *Ending> bool endsWithTemplate(const char *string) {
    return endsWith(string, Ending);
}

std::string toLower(const std::string &string);
std::vector<std::string> split(const std::string &string, const std::string &splitter);

}

template <typename T, typename Stream>
Stream & operator<<(Stream &stream, const std::vector<T> &v) {
    stream << '{';
    for (size_t i=0; i<v.size(); ++i) {
        stream << v[i] << ", ";
    }
    stream << '}';
    return stream;
}


#endif
