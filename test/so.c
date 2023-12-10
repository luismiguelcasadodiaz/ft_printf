#include <stdio.h>
#include <limits.h>

#ifdef __linux__
  #define MY_SYMBOL 1
  #define MY_ULL_MAX ULLONG_MAX
#elif __APPLE__
  #define MY_SYMBOL 2
  #define MY_ULL_MAX ULONG_LONG_MAX
#endif

int main() {
  if (MY_SYMBOL == 1) {
    printf("Running on Linux ==>%llu\n", MY_ULL_MAX);
  } else if (MY_SYMBOL == 2) {
    printf("Running on macOS ==>%llu\n", MY_ULL_MAX);
  } else {
    printf("Unknown operating system\n");
  }
  return 0;
}

