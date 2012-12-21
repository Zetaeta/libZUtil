
#include <time.h>

#include "Time.hpp"

namespace Util {

long currentTimeMillis() {
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

long currentTimeNanos() {
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_nsec;
}

}
