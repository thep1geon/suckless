#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../slstatus.h"
#include "../util.h"

const char*
timer(const char* arg) {
    unsigned int minutes = atoi(arg);
    return bprintf("%u", minutes);
}
