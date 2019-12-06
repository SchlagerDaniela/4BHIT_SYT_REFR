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

    if (-1 == GPIOExport(POUT1) || -1 == GPIOExport(POUT))
        return(1);


    if (-1 == GPIODirection(POUT1, OUT) || -1 == GPIODirection(POUT, OUT))
        return(2);

    do {

        if (-1 == GPIOWrite(POUT1, repeat % 2))
            return(3);

        printf("I'm reading %d in GPIO %d\n", GPIORead(POUT), POUT);

        usleep(500 * 1000);
    }
    while (repeat--);

    if (-1 == GPIOUnexport(POUT1) || -1 == GPIOUnexport(POUT))
        return(4);

    return(0);
}