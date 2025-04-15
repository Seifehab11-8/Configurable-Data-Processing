#include "../include/Utilities.hpp"

ProcessorTypeNotFound::ProcessorTypeNotFound(std::string message):msg(message)
{
}

const char* ProcessorTypeNotFound::what() const noexcept {
	return msg.c_str();
}