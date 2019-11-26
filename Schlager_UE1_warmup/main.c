/*
 * Project: Schlager_UE1_warmup
 * Author: Schlager Daniela
 * Date: 22.11.2019
 */

#include "report.h"


int main() {


    if(reportOpenFile() == true){;
        reportReport();
        reportCloseFile();
    }else{
        reportCloseFile();
    }

    return 0;
}