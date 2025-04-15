#include "../include/Processor.hpp"
#include <iostream>

void Processor::process()
{
    std::cout<<"=================================================================="<<std::endl;
    std::cout<<"Processor Type = "<<type<<std::endl;
    std::cout<<"Processor Threshold = "<<threshold<<std::endl;
    std::cout<<"Processor Max Retries = "<<maxRetries<<std::endl;
    std::cout<<"=================================================================="<<std::endl<<std::endl;
}

Processor::Processor() : type(""), threshold(0.0), maxRetries(0)
{
}

Processor::Processor(std::string type, double threshold, int maxRetries) : type(type), threshold(threshold), maxRetries(maxRetries)
{
}
