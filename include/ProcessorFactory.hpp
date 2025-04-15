#pragma once
#include "Processor.hpp"
#include <string>
#include<memory>
class ProcessorFactory {
    public:
    static std::shared_ptr<Processor> create(std::string type, double threshold, int maxRetries);
};