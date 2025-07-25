#pragma once

#include <cl/types.h>

#undef num_t
#define num_t f32

#undef pre
#define pre(name) f##name

#include "struct.h"
