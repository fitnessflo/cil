typedef struct {
  int (*f)(int);
} FOO;

int highorder(int a(int), int arg) __attribute__ ((precision (1))) {
  return a(arg);
}

int incr(int x) __attribute__ ((precision (0))) {
  return x + 1;
}
#include "testharness.h"

int main() {
  if(highorder(incr, 5) != 6) E(1);

  {
    FOO x = { incr };
    if(x.f(6) != 7) E(2);
  }

  SUCCESS;
  
}
