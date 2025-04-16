#pragma once
#include <tuple>
#include <string>
#include <map>
class Configuration {
    public:
    static std::tuple<std::string, double, int> configure(std::string path);
    static std::map<std::string, std::string> JsonParse(std::string path);
};