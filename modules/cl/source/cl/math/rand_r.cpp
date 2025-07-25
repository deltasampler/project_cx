#include <stdlib.h>

#include "math_r.h"

f32 frand() {
    return (f32)rand() / (f32)RAND_MAX;
}

f64 drand() {
    return (f64)rand() / (f64)RAND_MAX;
}

f32 rand_ex(f32 min, f32 max) {
    return mfloor(frand() * (max - min) + min);
}

f64 rand_ex(f64 min, f64 max) {
    return mfloor(drand() * (max - min) + min);
}

f32 rand_in(f32 min, f32 max) {
    return mfloor(frand() * (max - min + 1.0f) + min);
}

f64 rand_in(f64 min, f64 max) {
    return mfloor(drand() * (max - min + 1.0) + min);
}
