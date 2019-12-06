/*
 * Author: Schlager Daniela
 * Class: 4BHIT
 * Date: 06.12.2019
 */
#include <stdio.h>


#ifndef SCHLAGER_UE2_LEDBLINKEN_FUNCTION_H
#define SCHLAGER_UE2_LEDBLINKEN_FUNCTION_H

static int GPIOExport(int pin);
static int GPIOUnexport(int pin);
static int GPIODirection(int pin, int dir);
static int GPIORead(int pin);
static int GPIOWrite(int pin, int value);


#endif //SCHLAGER_UE2_LEDBLINKEN_FUNCTION_H
