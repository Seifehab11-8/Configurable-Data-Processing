#include "../include/Configuration.hpp"
#include <fstream>
#include <iostream>

std::tuple<std::string, double, int> Configuration::configure(std::string path)
{
    std::tuple<std::string, double, int> config;
    std::ifstream ifs(path);

    if(!ifs.is_open()) {
        std::cerr<<"Failed to open the file"<<std::endl;
        return config;
    }

    bool value_found = false, value_obtained = false;
    int counter = 0;

    try{
        std::string line;
        std::string value;
        while(getline(ifs, line)) {
            value_obtained = false;
            value_found = false;
            value.clear();
            for(auto ch: line) {
                if(ch == ',') {
                    value_obtained = true;
                    value_found = false;
                }
                if(ch == '{') {
                    value_obtained = false;
                    value_found = false;
                    break;
                }
                if(value_found && ch != ' ' && ch != '"') {
                    value+=ch;
                }
                if(ch == ':') {
                    value_found = true;
                }
            }
            
            if(value_obtained) {
                if (counter == 0) {
                    std::get<0>(config) = value;
                } else if (counter == 1) {
                    std::get<1>(config) = std::stod(value);
                } else if (counter == 2) {
                    std::get<2>(config) = std::stoi(value);
                }
                counter++;
            }
        }
    }
    catch(...){
        std::cerr<<"Error Occurred. . ."<<std::endl;
    }
    ifs.close();
    return config;
}