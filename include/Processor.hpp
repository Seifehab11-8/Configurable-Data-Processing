#pragma once
#include <string>
class Processor {
    protected:
    std::string type;
    double threshold;
    int maxRetries;
    public:
    virtual void process();
    Processor();
    Processor(std::string type, double threshold, int maxRetries);
};