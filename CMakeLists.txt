cmake_minimum_required(VERSION 3.1)
project(TcXboxController)

# Include and link folders
include_directories(
    C:/TwinCAT/AdsApi/TcAdsDll/Include/
)

link_directories(
    C:/TwinCAT/AdsApi/TcAdsDll/x64/lib
)


# Add executable from source files
add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    XboxController.cpp
)

# Link TwinCAT ADS lib
target_link_libraries(${CMAKE_PROJECT_NAME}
    TcAdsDll
)
