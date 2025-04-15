#pragma once
#include <stdexcept>
#include <string>
class ProcessorTypeNotFound : public std::exception {
    private:
    std::string msg;
    public:
    ProcessorTypeNotFound(std::string message);
    const char* what() const noexcept override;
};