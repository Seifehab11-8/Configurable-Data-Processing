#pragma once
#include "Processor.hpp"
#include <string>
class ImageProcessor : public Processor{
    public:
    void process() override;
    ImageProcessor();
    ImageProcessor(std::string type, double threhold, int maxRetries);
};