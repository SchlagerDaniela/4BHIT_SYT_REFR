/*
 * Project: Schlager_UE1_warmup
 * Author: Schlager Daniela
 * Date: 22.11.2019
 */

#include "report.h"

static FILE *fp;
char *source = "F:\\01_Schule\\4BHIT\\SYT\\REFR\\workspace\\Schlager_UE1_warmup\\access.log.6";


bool reportOpenFile() {
    if (source == NULL) {
        printf("Funktioniert nicht \n");
        return false;
    }

    fp = fopen(source, "r");
    if (fp == NULL) {
        printf("Funktioniert \n");
        return true;
    }
}


int counter;
char c;

bool reportReport() {
    fp = fopen(source, "r");

    for(c = getc(fp); c!=EOF; c=getc(fp)){
        if(c=='\n'){
            counter = counter +1;
        }
    }
    printf("Zeilen: %d" , counter);
}

bool reportCloseFile() {
    if (fp != NULL) {
        fclose(fp);
        printf("Close");
    }
    return true;
}

