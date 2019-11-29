#include <iostream>
#include <cstring>
#include "report.h"

int main(int argc, const char* argv[])
{
    char* source;
    for (int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-f") == 0){
            source = const_cast<char *>(argv[i + 1]);
        }
    }
    if(source != NULL && strcmp(source, "")){
        bool isOpen = reportOpenFile(source);
        if (isOpen){
            reportReport();
            reportCloseFile();
        }
    }
    else{
        std::cout << "Please specify the relative path to the file! <command> -f <file>";
        exit(EXIT_FAILURE);
    }

}