#pragma once
#include "Processor.hpp"
#include <string>
class NumericProcessor : public Processor{
    public:
    void process() override;
    NumericProcessor();
    NumericProcessor(std::string type, double threhold, int maxRetries);
};