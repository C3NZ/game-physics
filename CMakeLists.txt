cmake_minimum_required(VERSION 3.0.0)

if (${DISTRIBUTION_BUILD})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Dist/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Dist/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Dist/bin)
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release" OR ${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
endif()

# For vim setup.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------- ENGINE ----------------------------------

project(simplistic)

file(
    GLOB_RECURSE
    SIMPLISTIC_SRC
    ${CMAKE_SOURCE_DIR}/simplistic/src/*.h
    ${CMAKE_SOURCE_DIR}/simplistic/src/*.cpp
)

add_library(simplistic STATIC ${SIMPLISTIC_SRC})

set_target_properties(
    simplistic
    PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/simplistic/src/Simplistic.h
)

target_include_directories(
    simplistic
    PUBLIC ${CMAKE_SOURCE_DIR}/simplistic/src
)

project(sandbox)

file(
    GLOB_RECURSE
    SANDBOX_SRC
    ${CMAKE_SOURCE_DIR}/sandbox/src/*.h
    ${CMAKE_SOURCE_DIR}/sandbox/src/*.cpp
)

add_executable(sandbox ${SANDBOX_SRC})

target_link_libraries(sandbox PRIVATE simplistic)
