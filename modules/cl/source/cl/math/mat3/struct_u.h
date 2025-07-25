#pragma once

#include <cl/types.h>

#undef num_t
#define num_t u32

#undef pre
#define pre(name) u##name

#include "struct.h"
