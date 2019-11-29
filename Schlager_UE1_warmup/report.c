/*
 * Project: Schlager_UE1_warmup
 * Author: Schlager Daniela
 * Date: 22.11.2019
 */

#include "report.h"

FILE *fp;

int counter = 1;
char c;

bool reportOpenFile(char* source) {

    fp = fopen(source, "r");
    if (fp == NULL) {
        printf("File konnte nicht geoeffnet werden \n");
        return false;
    }
    if(fp != NULL){
        printf("File konnte geoeffnet werden.\n");
        return true;
    }
}

bool reportReport() {

    while((c = fgetc(fp)) != EOF){
        if(c == '\n'){
            counter++;
        }
    }

    return true;
}

bool reportCloseFile() {
    if (fp != NULL) {
        fclose(fp);
        printf("File wurde geschlossen. \n");
    }
    printf("Zeilen: %d",counter);
    return true;
}