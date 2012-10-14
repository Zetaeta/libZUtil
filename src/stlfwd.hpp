
#ifndef STLFWD_HPP
#define STLFWD_HPP

#include <bits/stringfwd.h>

namespace std {

#ifndef _STL_VECTOR_H
template <class T>
class allocator;

template<class T, class A = std::allocator<T>>
class vector;
#endif

#ifndef _GLIBCXX_FUNCTIONAL
template <typename Signature>
class function;
#endif

}

#endif
