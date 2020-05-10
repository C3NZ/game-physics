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
    ENGINE_SRC
    ${CMAKE_SOURCE_DIR}/simplistic/src/*.h
    ${CMAKE_SOURCE_DIR}/simplistic/src/*.cpp
)

add_library(engine STATIC ${ENGINE_SRC})

set_target_properties(
    engine
    PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/simplistic/src/Simplistic.h
)

target_include_directories(
    engine
    PUBLIC ${CMAKE_SOURCE_DIR}/simplistic/src
)

if (WIN32)
    message (STATUS ">>> Setting windows compile definitions for the engine.")
    target_compile_definitions(
        engine
    )

    # Use a Multi threaded specific and DLL specific runtime for windows.
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
elseif (UNIX)
    message (STATUS ">>> Setting linux compile definitions for the engine.")
    target_compile_definitions(
        engine
    )
endif()
