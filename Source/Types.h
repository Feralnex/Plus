#pragma once

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#endif

#ifdef _WIN32
typedef int Size;
typedef int SignedSize;
typedef char Byte;
#else
typedef size_t Size;
typedef ssize_t SignedSize;
typedef void Byte;
#endif
