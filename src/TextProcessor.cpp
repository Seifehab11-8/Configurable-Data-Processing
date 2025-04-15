#include "../include/TextProcessor.hpp"
#include <iostream>

TextProcessor::TextProcessor() : Processor()
{
}

TextProcessor::TextProcessor(std::string type, double threhold, int maxRetries) : Processor(type, threhold, maxRetries)
{
}

void TextProcessor::process() {
    Processor::process();
    std::cout<<"=================================================================="<<std::endl;
    std::cout<<"TextProcessor processing: Sample Data (interpreted as text data)"<<std::endl;
    std::cout<<"=================================================================="<<std::endl<<std::endl;
}