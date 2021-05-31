#include <WinSock2.h>
#include <windows.h>
#include "libWin.h"

LARGE_INTEGER
getFILETIMEoffset()
{
    SYSTEMTIME s;
    FILETIME f;
    LARGE_INTEGER t;

    s.wYear = 1970;
    s.wMonth = 1;
    s.wDay = 1;
    s.wHour = 0;
    s.wMinute = 0;
    s.wSecond = 0;
    s.wMilliseconds = 0;
    SystemTimeToFileTime(&s, &f);
    t.QuadPart = f.dwHighDateTime;
    t.QuadPart <<= 32;
    t.QuadPart |= f.dwLowDateTime;
    return (t);
}

int
clock_gettime(int X, struct timeval* tv)
{
    LARGE_INTEGER           t;
    FILETIME            f;
    double                  microseconds;
    static LARGE_INTEGER    offset;
    static double           frequencyToMicroseconds;
    static int              initialized = 0;
    static BOOL             usePerformanceCounter = 0;

    if (!initialized) {
        LARGE_INTEGER performanceFrequency;
        initialized = 1;
        usePerformanceCounter = QueryPerformanceFrequency(&performanceFrequency);
        if (usePerformanceCounter) {
            QueryPerformanceCounter(&offset);
            frequencyToMicroseconds = (double)performanceFrequency.QuadPart / 1000000.;
        }
        else {
            offset = getFILETIMEoffset();
            frequencyToMicroseconds = 10.;
        }
    }
    if (usePerformanceCounter) QueryPerformanceCounter(&t);
    else {
        GetSystemTimeAsFileTime(&f);
        t.QuadPart = f.dwHighDateTime;
        t.QuadPart <<= 32;
        t.QuadPart |= f.dwLowDateTime;
    }

    t.QuadPart -= offset.QuadPart;
    microseconds = (double)t.QuadPart / frequencyToMicroseconds;
    t.QuadPart = microseconds;
    tv->tv_sec = t.QuadPart / 1000000;
    tv->tv_usec = t.QuadPart % 1000000;
    return (0);
}

uint8_t atomic_fetch_add_byte(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr + value;
    return *ptr;
}

uint8_t atomic_fetch_and_byte(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr & value;
    return *ptr;
}

uint8_t atomic_fetch_or_byte(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr | value;
    return *ptr;
}

uint8_t atomic_fetch_sub_byte(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr - value;
    return *ptr;
}

uint8_t atomic_fetch_xor_byte(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr - value;
    return *ptr;
}

uint8_t atomic_exchange_byte(uint8_t* ptr, uint32_t value)
{
    *ptr = value;
    return *ptr;
}

uint8_t atomic_fetch_add_short(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr + value;
    return *ptr;
}

uint8_t atomic_fetch_and_short(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr & value;
    return *ptr;
}

uint8_t atomic_fetch_or_short(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr | value;
    return *ptr;
}

uint8_t atomic_fetch_sub_short(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr - value;
    return *ptr;
}

uint8_t atomic_fetch_xor_short(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr - value;
    return *ptr;
}

uint8_t atomic_exchange_short(uint8_t* ptr, uint32_t value)
{
    *ptr = value;
    return *ptr;
}

uint8_t atomic_fetch_add_int(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr + value;
    return *ptr;
}

uint8_t atomic_fetch_and_int(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr & value;
    return *ptr;
}

uint8_t atomic_fetch_or_int(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr | value;
    return *ptr;
}

uint8_t atomic_fetch_sub_int(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr - value;
    return *ptr;
}

uint8_t atomic_fetch_xor_int(uint8_t* ptr, uint32_t value)
{
    *ptr = *ptr - value;
    return *ptr;
}

uint8_t atomic_exchange_int(uint8_t* ptr, uint32_t value)
{
    *ptr = value;
    return *ptr;
}

