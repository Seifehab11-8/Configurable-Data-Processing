cmake_minimum_required(VERSION 3.10)
project(ConfigurableDataProcessing VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/Configuration.cpp
    src/main.cpp
    src/Processor.cpp 
    src/ProcessorFactory.cpp
    src/AudioProcessor.cpp
    src/ImageProcessor.cpp
    src/NumericProcessor.cpp
    src/TextProcessor.cpp
    src/Utilities.cpp
)

# Add header files
set(HEADERS
    include/Configuration.hpp
    include/Processor.hpp
    include/ProcessorFactory.hpp
    include/AudioProcessor.hpp
    include/ImageProcessor.hpp
    include/NumericProcessor.hpp
    include/TextProcessor.hpp
    include/Utilities.hpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)