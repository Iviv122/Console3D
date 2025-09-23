cmake_minimum_required(VERSION 3.10)

set(PROJECT_N Console3D)
project(${PROJECT_N} VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Gather all source files
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Macro to find unique include directories
MACRO(header_directories return_list includes_base_folder extension)
    FILE(GLOB_RECURSE new_list ${includes_base_folder}/*.${extension})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        LIST(APPEND dir_list ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

header_directories(INCLUDES ${PROJECT_SOURCE_DIR}/include hpp)

message("src files:")
foreach(file ${SRCS})
    message(STATUS ${file})
endforeach()

message("include directories:")
foreach(dir ${INCLUDES})
    message(STATUS ${dir})
endforeach()

# Create the executable
add_executable(${PROJECT_N} ${SRCS})

# Include header directories
target_include_directories(${PROJECT_N} PUBLIC ${INCLUDES})

# Platform-specific configurations
if(WIN32)
    message(STATUS "Configuring for Windows")
    target_compile_definitions(${PROJECT_N} PRIVATE PLATFORM_WINDOWS)
    # Add Windows-specific libs or flags if needed
elseif(APPLE)
    message(STATUS "Configuring for macOS")
    target_compile_definitions(${PROJECT_N} PRIVATE PLATFORM_MACOS)
    # Example: link frameworks if needed
    # target_link_libraries(${PROJECT_N} "-framework Cocoa")
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux")
    target_compile_definitions(${PROJECT_N} PRIVATE PLATFORM_LINUX)
    # Add Linux-specific libs or flags if needed
endif()
