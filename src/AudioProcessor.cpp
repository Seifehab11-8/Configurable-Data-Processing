#include "../include/AudioProcessor.hpp"
#include <iostream>

AudioProcessor::AudioProcessor() : Processor()
{
}

AudioProcessor::AudioProcessor(std::string type, double threhold, int maxRetries) : Processor(type, threhold, maxRetries)
{
}

void AudioProcessor::process() {
    Processor::process();
    std::cout<<"=================================================================="<<std::endl;
    std::cout<<"AudioProcessor processing: Sample Data (interpreted as audio data)"<<std::endl;
    std::cout<<"=================================================================="<<std::endl<<std::endl;
}