#include "../include/NumericProcessor.hpp"
#include <iostream>

NumericProcessor::NumericProcessor() : Processor()
{

}

NumericProcessor::NumericProcessor(std::string type, double threhold, int maxRetries) : Processor(type, threhold, maxRetries)
{
}

void NumericProcessor::process() {
    Processor::process();
    std::cout<<"=================================================================="<<std::endl;
    std::cout<<"NumericProcessor processing: Sample Data (interpreted as numeric data)"<<std::endl;
    std::cout<<"=================================================================="<<std::endl<<std::endl;
}