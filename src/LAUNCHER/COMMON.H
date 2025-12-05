#ifndef COMMON_H
#define COMMON_H

typedef unsigned char cc_bool;
enum { cc_false, cc_true };

#define COUNT_OF(x) (sizeof(x) / sizeof(x[0]))
#define DIVIDE_CEILING(dividant, divisor) ((dividant + (divisor - 1)) / divisor)

#endif /* COMMON_H */
