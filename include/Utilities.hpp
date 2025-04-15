#pragma once
#include <stdexcept>
class ProcessorTypeNotFound : public std::exception {
    private:
    std::string msg;
    public:
    ProcessorTypeNotFound(std::string message);
    const char* what() const noexcept override;
};