#pragma once

#ifdef BIG_INT
#include "BigInt.hpp"
typedef BigInt coord_type;
#else
typedef int64_t coord_type;
#endif