#include "../include/Utilities.hpp"
#include "../include/Processor.hpp"
#include "../include/AudioProcessor.hpp"
#include "../include/ImageProcessor.hpp"
#include "../include/NumericProcessor.hpp"
#include "../include/TextProcessor.hpp"
#include "../include/ProcessorFactory.hpp"

std::shared_ptr<Processor>ProcessorFactory::create(std::string type, double threshold, int maxRetries)
{
    if(type == "Audio") {
        return std::make_shared<AudioProcessor>(AudioProcessor(type, threshold, maxRetries));
    }
    else if(type == "Image") {
        return std::make_shared<ImageProcessor>(ImageProcessor(type, threshold, maxRetries));
    }
    else if(type == "Text") {
        return std::make_shared<TextProcessor>(TextProcessor(type, threshold, maxRetries));
    }
    else if(type == "Numeric") {
        return std::make_shared<NumericProcessor>(NumericProcessor(type, threshold, maxRetries));
    }
    throw ProcessorTypeNotFound("This type is not found your file is not being processed");
}
