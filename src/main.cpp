#include "../include/Utilities.hpp"
#include "../include/Processor.hpp"
#include "../include/AudioProcessor.hpp"
#include "../include/ImageProcessor.hpp"
#include "../include/NumericProcessor.hpp"
#include "../include/TextProcessor.hpp"
#include "../include/ProcessorFactory.hpp"
#include <iostream>

int main () {
    try{
        std::shared_ptr<Processor> P_ptr = ProcessorFactory::create("ay7aga", 0.5, 3);
        P_ptr.get()->process();
    }
    catch(const ProcessorTypeNotFound &e) {
        std::cerr<<e.what()<<std::endl;
    }
}