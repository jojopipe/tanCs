#include <stdio.h>
#include <raylib.h>
#include "settings.h"
#include "startup.h"

int main(void) {
    int result;
    result = init_game();
    if (result != 0) return 69;
    return 0;
}
