cmake_minimum_required(VERSION 3.25)

project(upsi)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall)
#add_compile_options(-fsanitize=address)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-g -ggdb)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_options(-O2)
endif ()

file(GLOB SOURCES "src/*/*.cpp" "src/*/*.hpp" "src/*.cpp" "src/*.hpp")
add_executable(upsi ${SOURCES})

target_include_directories(upsi PUBLIC src/cuckoofilter)

#set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_DEBUG_RUNTIME OFF)

find_package(libOTe REQUIRED
        PATHS ./libOTe
        NO_DEFAULT_PATH
        NO_CMAKE_ENVIRONMENT_PATH
        NO_CMAKE_PATH
        NO_SYSTEM_ENVIRONMENT_PATH
        NO_CMAKE_SYSTEM_PATH
        NO_CMAKE_FIND_ROOT_PATH)
target_link_libraries(upsi oc::libOTe)
