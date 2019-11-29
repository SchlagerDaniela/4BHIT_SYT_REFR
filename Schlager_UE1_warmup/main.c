/*
 * Project: Schlager_UE1_warmup
 * Author: Schlager Daniela
 * Date: 22.11.2019
 */

#include "report.h"

char source[] = "..//access.log.6";

int main() {

    reportOpenFile(source);
    reportReport();
    reportCloseFile();

    return 0;
}