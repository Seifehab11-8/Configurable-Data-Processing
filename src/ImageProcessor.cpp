#include "../include/ImageProcessor.hpp"
#include <iostream>

ImageProcessor::ImageProcessor() : Processor()
{
}

ImageProcessor::ImageProcessor(std::string type, double threhold, int maxRetries) : Processor(type, threhold, maxRetries)
{
}

void ImageProcessor::process() {
    Processor::process();
    std::cout<<"=================================================================="<<std::endl;
    std::cout<<"ImageProcessor processing: Sample Data (interpreted as image data)"<<std::endl;
    std::cout<<"=================================================================="<<std::endl<<std::endl;
}
