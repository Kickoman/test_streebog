cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(test_streebog VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES_DIR src/)
set(HEADERS_DIR inc/)

set(SOURCES
    main.cpp
    ${SOURCES_DIR}/streebog.cpp
    ${SOURCES_DIR}/crypto_hash.cpp
    ${SOURCES_DIR}/cpuinfo.cpp
    ${SOURCES_DIR}/gost3411-2012-sse2.c
    ${SOURCES_DIR}/gost3411-2012-sse41.c
)

set(HEADERS
    ${HEADERS_DIR}/streebog.h
    ${HEADERS_DIR}/crypto_hash.h
    ${HEADERS_DIR}/alignedarray.h
    ${HEADERS_DIR}/cpuinfo.h
    ${HEADERS_DIR}/portability.h
    ${HEADERS_DIR}/gost3411-2012-sse2.h
)


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_DIR})
