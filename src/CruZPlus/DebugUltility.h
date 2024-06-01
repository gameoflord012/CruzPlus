#pragma once

#include <cstdio>

#define PRINTF(...) printf(__VA_ARGS__)
#define PRINT_VEC2(v) printf("%f %f\n", v ## .x, v ## .y)