#pragma once
#include <tuple>
#include <string>
class Configuration {
    public:
    static std::tuple<std::string, double, int> configure(std::string path);
};