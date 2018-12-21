#ifndef ALWAYS_INLINE
#define ALWAYS_INLINE inline __attribute__((always_inline))
#endif
#ifndef NEVER_INLINE
#   define NEVER_INLINE __attribute__((noinline))
#endif