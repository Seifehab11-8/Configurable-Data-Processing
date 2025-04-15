#pragma once
#include "Processor.hpp"
#include <string>
class AudioProcessor : public Processor{
    public:
    void process() override;
    AudioProcessor();
    AudioProcessor(std::string type, double threhold, int maxRetries);
};