#ifndef SHARED_FORWARD_H
#define SHARED_FORWARD_H

struct probe;
struct component;

#if defined(__STDC__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#elif !defined(__cplusplus) && !defined(bool)
typedef enum { false, true } bool;
#endif // __STDC__


#endif // SHARED_FORWARD_H
