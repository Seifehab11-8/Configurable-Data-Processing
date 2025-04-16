#include "../include/Configuration.hpp"
#include <fstream>
#include <iostream>
#include "../include/Configuration.hpp"

std::tuple<std::string, double, int> Configuration::configure(std::string path)
{
    std::tuple<std::string, double, int> config;
    try {
        std::map<std::string, std::string> jsonKeyMap = JsonParse(path);
        std::get<0>(config) = jsonKeyMap["Type"];
        std::get<1>(config) = std::stod(jsonKeyMap["Threshold"]);
        std::get<2>(config) = std::stoi(jsonKeyMap["MaxRetries"]);
    }
    catch (const std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }
    return config;
}
std::map<std::string, std::string> Configuration::JsonParse(std::string path)
{
    std::map<std::string, std::string> jsonKeyMap;
    std::ifstream ifs(path);

    bool key_found = false, 
    value_found = false, 
    str_found = false, 
    key_created = false, 
    value_created = false;

    std::string key_builder, value_builder;
    if(!ifs.is_open()) {
        std::cerr<<"Failed to open the file"<<std::endl;
        throw std::runtime_error("Couldn't find the file");
    }

    try{
        char ch;
        while(ifs.get(ch)) {
            if(key_found) {
                while(ifs.get(ch)) {
                    if(ch == '"'&& str_found) {
                        key_found = false;
                        str_found = false;
                        key_created = true;
                        break;
                    }
                    else if(ch == '"' && !str_found) {
                        str_found = true;
                        continue;
                    }
                    if(str_found) key_builder+= ch;
                }
            }
            
            if(value_found && key_created) {
                while(ifs.get(ch)) {
                    if(ch == '"' && !str_found) {
                        value_builder.clear();
                        str_found = true;
                        continue;
                    }
                    else if(ch == '"' && str_found) {
                        value_found = false;
                        value_created = true;
                        str_found = false;
                        key_found = true;
                        break;
                    }
                    else if(ch == ',' || ch == '}') {
                        value_found = false;
                        value_created = true;
                        value_builder.erase(std::remove(value_builder.begin(),
                                            value_builder.end(), ' '),value_builder.end());
                        key_found =true;
                        break;
                    }
                    value_builder+=ch;
                }
            }
            if(ch == '{') key_found = true;
            if(ch == ':') value_found = true;
            if(value_created && key_created) {
                jsonKeyMap[key_builder] = value_builder;
                value_created = false;
                key_created = false;
                value_builder.clear();
                key_builder.clear();
            }
        }
    }
    catch(...){
        std::cerr<<"Error Occurred. . ."<<std::endl;
    }
    ifs.close();
    return jsonKeyMap;
}