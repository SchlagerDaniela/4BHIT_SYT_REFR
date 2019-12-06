/*
 * Author: Schlager Daniela
 * Class: 4BHIT
 * Date: 06.12.2019
 */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef SCHLAGER_UE2_LEDBLINKEN_FUNCTION_H
#define SCHLAGER_UE2_LEDBLINKEN_FUNCTION_H

#define IN  0
#define OUT 1

#define LOW  0
#define HIGH 1

#define PIN  4 // Pin 07
#define POUT 17  //Pin 11

static int GPIOExport(int pin);
static int GPIOUnexport(int pin);
static int GPIODirection(int pin, int dir);
static int GPIORead(int pin);
static int GPIOWrite(int pin, int value);


#endif //SCHLAGER_UE2_LEDBLINKEN_FUNCTION_H
