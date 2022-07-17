#include "types.h"

Speed calcSpeed(Distance s, Time t) {
    return (Speed) s / t;
}

Acceleration calcAcceleration(Speed v, Time t) {
    return (Acceleration) v / t;
}

Impulse calcImpulse(Mass m, Speed v) {
    return (Impulse) m * v;
}
