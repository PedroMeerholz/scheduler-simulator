#include "generator.h"
#include <time.h>
#include <stdlib.h>

int generate() {
    srand(time(NULL));
    return rand() % 2;
}
