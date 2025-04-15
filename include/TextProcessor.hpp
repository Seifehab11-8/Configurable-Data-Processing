#pragma once
#include "Processor.hpp"
#include <string>
class TextProcessor : public Processor{
    public:
    void process() override;
    TextProcessor();
    TextProcessor(std::string type, double threhold, int maxRetries);
};