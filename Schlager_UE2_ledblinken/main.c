#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "function.h"

int main(int argc, char *argv[])
{
    int repeat = 10;

    if (-1 == GPIOExport(POUT) || -1 == GPIOExport(PIN))
        return(1);


    if (-1 == GPIODirection(POUT, OUT) || -1 == GPIODirection(PIN, IN))
        return(2);

    do {

        if (-1 == GPIOWrite(POUT, repeat % 2))
            return(3);

        printf("I'm reading %d in GPIO %d\n", GPIORead(PIN), PIN);

        usleep(500 * 1000);
    }
    while (repeat--);

    if (-1 == GPIOUnexport(POUT) || -1 == GPIOUnexport(PIN))
        return(4);

    return(0);
}