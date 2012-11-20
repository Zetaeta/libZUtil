
#ifndef ROUNDING_HPP
#define ROUNDING_HPP

namespace Util {

template <typename T, T multiple>
T roundUp(T number) {
    if (multiple == 0) {
        return number;
    }
    T remainder = number % multiple;
    if (remainder == 0) {
        return number;
    }
    if (number < 0) {
        return number - multiple + remainder;
    }
    return number + multiple - remainder;
}

template <typename T, T multiple>
T roundDown(T number) {
    T remainder = number % multiple;
    return number - remainder;
}

template <typename T, T multiple>
T roundDownToNeg(T number) {
    if (number < 0)
        return roundUp<T, multiple>(number);
    else
        return roundDown<T, multiple>(number);
}

}

#endif
