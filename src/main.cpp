#include "../include/Utilities.hpp"
#include "../include/Processor.hpp"
#include "../include/AudioProcessor.hpp"
#include "../include/ImageProcessor.hpp"
#include "../include/NumericProcessor.hpp"
#include "../include/TextProcessor.hpp"
#include "../include/ProcessorFactory.hpp"
#include "../include/Configuration.hpp"
#include <iostream>

int main () {
    auto [type, threshold, maxRetries] = Configuration::configure("/Users/seifehab/Documents/GitHub/Configurable-Data-Processing/config/settings.txt");
    try{
        std::shared_ptr<Processor> P_ptr = ProcessorFactory::create(type, threshold, maxRetries);
        P_ptr.get()->process();
    }
    catch(const ProcessorTypeNotFound &e) {
        std::cerr<<e.what()<<std::endl;
    }
}