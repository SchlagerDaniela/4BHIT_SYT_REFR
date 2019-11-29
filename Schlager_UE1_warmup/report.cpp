
#include "report.h"
#include <fstream>
#include <iostream>
#include <regex>


std::ifstream myfile;
std::regex browser(".*\"(\\w+)/.*");
std::regex os("\\s\\((.*?)\\)[^\\\"]");
std::regex method("((GET)|(POST))");
std::smatch match;


bool reportOpenFile(char *source){
    myfile.open (source);
    if (myfile.is_open()){
        return true;
    } else{
        return false;
    }
}

bool reportReport(){
    std::string line;
    int lines = 0;
    std::map<std::string, int> mapOfBrowser;
    std::map<std::string, int> mapOfOS;
    std::map<std::string, int> mapOfMethod;

    while (getline(myfile, line)){
        lines++;
        const std::string s = line;
        if(std::regex_search(s.begin(), s.end(), match, browser)){
            if(mapOfBrowser.find(match[1]) == mapOfBrowser.end()){
                mapOfBrowser.insert(std::make_pair(match[1], 1));
            } else{
                mapOfBrowser[match[1]]++;
            }
        } else{
            if(mapOfBrowser.find("no agent") == mapOfBrowser.end()){
                mapOfBrowser.insert(std::make_pair("no agent", 1));
            } else{
                mapOfBrowser["no agent"]++;
            }
        }

        std::string s1 = line;
        if(s1.find("Android") != std::string::npos){
            if(mapOfOS.find("Android") == mapOfOS.end()){
                mapOfOS.insert(std::make_pair("Android", 1));
            } else{
                mapOfOS["Android"]++;
            }
        }else if(s1.find("Windows") != std::string::npos){
            if(mapOfOS.find("Windows") == mapOfOS.end()){
                mapOfOS.insert(std::make_pair("Windows", 1));
            } else{
                mapOfOS["Windows"]++;
            }
        }
        else if(s1.find("Mac") != std::string::npos){
            if(mapOfOS.find("Mac") == mapOfOS.end()){
                mapOfOS.insert(std::make_pair("Mac", 1));
            } else{
                mapOfOS["Mac"]++;
            }
        }
        else if(s1.find("Linux") != std::string::npos){
            if(mapOfOS.find("Linux") == mapOfOS.end()){
                mapOfOS.insert(std::make_pair("Linux", 1));
            } else{
                mapOfOS["Linux"]++;
            }
        }
        else{
            if(std::regex_search(s.begin(), s.end(), match, os)){
                std::stringstream ss(match[1]);
                std::string item;
                std::vector<std::string> splittedStrings;
                std::string strOS;
                while (std::getline(ss, item, ' '))
                {
                    splittedStrings.push_back(item);
                }
                strOS = splittedStrings[0];

                if(splittedStrings[0].find(";") != std::string::npos){
                    splittedStrings[0].erase (std::remove(splittedStrings[0].begin(), splittedStrings[0].end(), ';'), splittedStrings[0].end());
                    strOS = splittedStrings[0];
                }
                if(mapOfOS.find(strOS) == mapOfOS.end()){
                    mapOfOS.insert(std::make_pair(strOS, 1));
                } else{
                    mapOfOS[strOS]++;
                }
            } else{
                if(mapOfOS.find("no os") == mapOfOS.end()){
                    mapOfOS.insert(std::make_pair("no os", 1));
                } else{
                    mapOfOS["no os"]++;
                }
            }
        }
        if(std::regex_search(s.begin(), s.end(), match, method)){
            if(mapOfMethod.find(match[1]) == mapOfMethod.end()){
                mapOfMethod.insert(std::make_pair(match[1], 1));
            } else{
                mapOfMethod[match[1]]++;
            }
        }
        else{
            if(mapOfMethod.find("no method") == mapOfMethod.end()){
                mapOfMethod.insert(std::make_pair("no method", 1));
            } else{
                mapOfMethod["no method"]++;
            }
        }

    }

    std::cout << "Lines: " << lines << "\n";

    std::cout << "\nBrowser: \n";
    std::map<std::string, int>::iterator it = mapOfBrowser.begin();
    while(it != mapOfBrowser.end())
    {
        std::cout << "\t" <<it->first<<": "<<it->second<<std::endl;
        it++;
    }

    std::cout << "\nHTTP Method: \n";
    it = mapOfMethod.begin();
    while(it != mapOfMethod.end())
    {
        std::cout << "\t" <<it->first<<": "<<it->second<<std::endl;
        it++;
    }

    std::cout << "\nOS: \n";
    it = mapOfOS.begin();
    while(it != mapOfOS.end())
    {
        std::cout << "\t" <<it->first<<": "<<it->second<<std::endl;
        it++;
    }
    return true;
}

bool reportCloseFile(){
    myfile.close();
    return true;
}
