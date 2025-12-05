#ifndef COMMON_H
#define COMMON_H

typedef unsigned char cc_bool;
enum { cc_false, cc_true };

#define COUNT_OF(x) (sizeof(x) / sizeof(x[0]))
#define DIVIDE_CEILING(dividant, divisor) ((dividant + (divisor - 1)) / divisor)
#define CC_MIN(a, b) ((a) < (b) ? (a) : (b))
#define CC_MAX(a, b) ((a) > (b) ? (a) : (b))

#endif /* COMMON_H */
