#pragma once

#include <cl/types.h>

#undef num_t
#define num_t s32

#undef pre
#define pre(name) s##name

#include "struct.h"
