/*
 * Project: Schlager_UE1_warmup
 * Author: Schlager Daniela
 * Date: 22.11.2019
 */

#include "report.h"
static FILE *fp = NULL;
static char *source = "F:\\01_Schule\\4BHIT\\SYT\\REFR\\workspace\\Schlager_UE1_warmup\\access.log.6";


bool reportOpenFile(){
    if(source == NULL){
        printf("Funktioniert nicht ");
        return false;
    }

    fp = fopen(source, "r");
    if(fp == NULL){
        printf("Funktioniert");
        return true;
    }
}

int counter = 0;

bool reportReport(){
    /*while(){
        counter++;
    }*/

}

bool reportCloseFile(){
    if(fp !=NULL){
        fclose(fp);
    }
    return true;
}

