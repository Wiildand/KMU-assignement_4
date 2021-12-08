# Set the required version of CMake
cmake_minimum_required(VERSION 3.7)

# Set the current compilation version of C++
set(CMAKE_CXX_STANDARD 11)

# Create the Executable
set(PROJECT_NAME ComputerGraphic_Assignment_02)
project(${PROJECT_NAME})

# Find OPENGL Library
find_package(OpenGL REQUIRED)

#include(MSVCMultipleProcessCompile)


IF (WIN32) # for windows
    # Compile external dependencies
    add_subdirectory(external)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/list-cmake")
    #include(CreateLaunchers)
    #include(MSVCMultipleProcessCompile)
    include_directories(
            external/glfw-3.1.2/include/
            external/glm-0.9.7.1/
            external/glew-1.13.0/include/
            external/glew-1.13.0/include/GL/
    )
    IF (CMAKE_BUILD_TYPE MATCHES RELEASE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2")
    ENDIF (CMAKE_BUILD_TYPE MATCHES RELEASE)
    set(ALL_LIBS ${OPENGL_LIBRARY} glfw GLEW_1130)
ELSE (WIN32) # for unix (g++ clangs)
    find_package(GLFW3 REQUIRED)
    find_package(glm REQUIRED)
    find_package(GLEW REQUIRED)

    if (GLEW_FOUND)
        include_directories(${GLEW_INCLUDE_DIRS})
        link_libraries(${GLEW_LIBRARIES})
    endif ()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
    IF (CMAKE_BUILD_TYPE MATCHES RELEASE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    ENDIF (CMAKE_BUILD_TYPE MATCHES RELEASE)
    set(ALL_LIBS ${OPENGL_LIBRARY} glfw)
ENDIF (WIN32)


add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

include_directories(include
        source/MidPoint
        )

set(SRC_FILES
        source/main.cpp
        source/MidPoint/MidPoint.cpp
        )


set(HDR_FILES)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})