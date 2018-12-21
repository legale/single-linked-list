/*
 * Using __builtin_constant_p(x) to ignore cases where the return
 * value is always the same.  This idea is taken from a similar patch
 * written by Daniel Walker.
 */
# ifndef LIKELY
#  define LIKELY(x)	__builtin_expect((x),1)
# endif
# ifndef UNLIKELY
#  define UNLIKELY(x)	__builtin_expect((x),0)
# endif