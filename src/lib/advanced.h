#include <math.h>
#include "types.h"

Distance calcRectilinearDistance(Speed s, Time t, Time t0) {
    return (Distance) s * (t - t0);
}

Distance calcAcceleratedRectilinearDistance(Speed v, Speed v0, Acceleration a) {
    return (Distance) ((v * v) - (v0 * v0)) / 2 * a;
}

Speed calcAcceleratedRectilinearSpeed(Acceleration a, Time t, Time t0, Speed v0) {
    return (Speed) a * (t - t0) + v0;
}