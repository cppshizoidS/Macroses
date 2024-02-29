#include "defer.h"
#include <stdio.h>

int main() {

  // Deferred code block
  DEFER(printf("Before DEFER. Already inside. ["),
        printf("] After DEFER. Still inside.\n")) {
    printf("] Inside DEFER. [");
  }

  return 0;
}
