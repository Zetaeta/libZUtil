
#ifndef MAYBEPOINTER_HPP
#define MAYBEPOINTER_HPP

#include <type_traits>

namespace Util {

template <typename T>
class MaybePointer {
public:
    MaybePointer(T *p)
    :ptr(p), isPointer(true) {}

    MaybePointer(T &r)
    :ptr(&r), isPointer(false) {}

    MaybePointer(MaybePointer<T> &&other)
    :ptr(other.ptr), isPointer(other.isPointer) {
        other.isPointer = false;
    }

    MaybePointer(const MaybePointer<T> &other)
    :ptr(other.ptr), isPointer(other.isPointer) {
        other.isPointer = false;
    }

    template <typename U, typename = typename
    std::enable_if<
        std::is_convertible<U *, T *>::value,
    U>::type>
    MaybePointer(const MaybePointer<U> &other)
    :ptr(other.ptr), isPointer(other.isPointer) {
        other.isPointer = false;
    }

    template <typename U, typename = typename
    std::enable_if<
        std::is_convertible<U *, T *>::value,
    U>::type>
    MaybePointer(MaybePointer<U> &&other)
    :ptr(other.ptr), isPointer(other.isPointer) {
        other.isPointer = false;
    }

    template <typename U, typename = typename std::enable_if<
                                        std::is_convertible<U *, T *>::value,
                                     U>::type>
    MaybePointer & operator=(const MaybePointer<U> &other) {
        ptr = other.ptr;
        isPointer = other.isPointer;
        other.isPointer = false;
        return *this;
    }

    MaybePointer & operator=(const MaybePointer<T> &other) {
        ptr = other.ptr;
        isPointer = other.isPointer;
        other.isPointer = false;
        return *this;
    }

    T & operator*() {
        return *ptr;
    }

    T & operator*() const {
        return *ptr;
    }

    T * operator->() const {
        return ptr;
    }

    operator T*() const {
        return ptr;
    }

/*
    template <class U>
    operator MaybePointer<U>() {
        return MaybePointer<U>(ptr);
    }

    template <class U>
    operator const MaybePointer<U>() const {
        return MaybePointer<U>(ptr);
    }
*/

    template<class U>
    operator typename std::enable_if<std::is_convertible<T, U>::value, U>::type*() {
        return ptr;
    }

    template<class U>
    operator const typename std::enable_if<std::is_convertible<T, U>::value, U>::type*() const {
        return ptr;
    }


    T * getRaw() {
        return operator T*();
    }

    ~MaybePointer() {
        if (isPointer) {
            delete ptr;
        }
    }
private:
    T *ptr;
    mutable bool isPointer; // Must be mutable for modification in copy constructor

    template <class U>
    friend class MaybePointer;

    MaybePointer(T *ptr, bool isPointer)
    :ptr(ptr), isPointer(isPointer) {}
};

}

#endif
