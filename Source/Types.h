#pragma once

#ifdef _WIN32
#include <vcruntime.h>
#else
#include <sys/types.h>
#endif

#include <cstddef>

#ifdef _WIN32
typedef size_t Size;
typedef ptrdiff_t SignedSize;
#elif __linux__
typedef size_t Size;
typedef ssize_t SignedSize;
#endif
typedef unsigned char Byte;
