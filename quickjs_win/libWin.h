#pragma once

#include <sys/types.h>
#include <sys/timeb.h>


#ifdef _WIN32


#define        __S_IFMT        0170000        /* These bits determine file type.  */
/* File types.  */
#define        __S_IFDIR        0040000        /* Directory.  */
#define        __S_IFCHR        0020000        /* Character device.  */
#define        __S_IFBLK        0060000        /* Block device.  */
#define        __S_IFREG        0100000        /* Regular file.  */
#define        __S_IFIFO        0010000        /* FIFO.  */

# define S_IFMT                __S_IFMT
# define S_IFDIR        __S_IFDIR
# define S_IFCHR        __S_IFCHR
# define S_IFBLK        __S_IFBLK
# define S_IFREG        __S_IFREG
# ifdef __S_IFIFO
#  define S_IFIFO        __S_IFIFO
# endif
# ifdef __S_IFLNK
#  define S_IFLNK        __S_IFLNK
# endif
# if (defined __USE_MISC || defined __USE_XOPEN_EXTENDED) \
     && defined __S_IFSOCK
#  define S_IFSOCK        __S_IFSOCK
# endif

#define        __S_ISTYPE(mode, mask)        (((mode) & __S_IFMT) == (mask))
#define        S_ISDIR(mode)         __S_ISTYPE((mode), __S_IFDIR)
#define        S_ISCHR(mode)         __S_ISTYPE((mode), __S_IFCHR)
#define        S_ISBLK(mode)         __S_ISTYPE((mode), __S_IFBLK)
#define        S_ISREG(mode)         __S_ISTYPE((mode), __S_IFREG)

int clock_gettime(int X, struct timeval* tv);


#include <WinSock2.h>
#include <windows.h>

#include <intrin.h>
#include <stdint.h>

uint8_t atomic_fetch_add_byte(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_and_byte(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_or_byte(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_sub_byte(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_xor_byte(uint8_t* ptr, uint32_t value);
uint8_t atomic_exchange_byte(uint8_t* ptr, uint32_t value);

uint8_t atomic_fetch_add_short(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_and_short(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_or_short(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_sub_short(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_xor_short(uint8_t* ptr, uint32_t value);
uint8_t atomic_exchange_short(uint8_t* ptr, uint32_t value);

uint8_t atomic_fetch_add_int(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_and_int(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_or_int(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_sub_int(uint8_t* ptr, uint32_t value);
uint8_t atomic_fetch_xor_int(uint8_t* ptr, uint32_t value);
uint8_t atomic_exchange_int(uint8_t* ptr, uint32_t value);
#endif
