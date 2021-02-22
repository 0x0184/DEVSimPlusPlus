# CMake Version
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

# Include CMake modules
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Builds/CMake")

SET(HEADER_DIR "Includes")
SET(SOURCE_DIR "Sources")

SET(KERNEL_HEADERS
    "${HEADER_DIR}/Kernel/Atomic.hpp"
    "${HEADER_DIR}/Kernel/Coupled.hpp"
    "${HEADER_DIR}/Kernel/DEVSDEF.h"
    "${HEADER_DIR}/Kernel/Digraph.hpp"
    "${HEADER_DIR}/Kernel/Entity.hpp"
    "${HEADER_DIR}/Kernel/Entstr.hpp"
    "${HEADER_DIR}/Kernel/List.hpp"
    "${HEADER_DIR}/Kernel/Log.hpp"
    "${HEADER_DIR}/Kernel/MList.hpp"
    "${HEADER_DIR}/Kernel/Message.hpp"
    "${HEADER_DIR}/Kernel/Model.hpp"
    "${HEADER_DIR}/Kernel/Port.hpp")
SET(KERNEL_SOURCES
    "${SOURCE_DIR}/Kernel/Atomic.cpp"
    "${SOURCE_DIR}/Kernel/Coupled.cpp"
    "${SOURCE_DIR}/Kernel/Digraph.cpp"
    "${SOURCE_DIR}/Kernel/Entity.cpp"
    "${SOURCE_DIR}/Kernel/Entstr.cpp"
    "${SOURCE_DIR}/Kernel/List.cpp"
    "${SOURCE_DIR}/Kernel/Log.cpp"
    "${SOURCE_DIR}/Kernel/MList.cpp"
    "${SOURCE_DIR}/Kernel/Message.cpp"
    "${SOURCE_DIR}/Kernel/Model.cpp"
    "${SOURCE_DIR}/Kernel/Port.cpp")
SET(HEADERS
    "${HEADER_DIR}/Generator.hpp"
    "${HEADER_DIR}/Process.hpp"
    "${HEADER_DIR}/Transducer.hpp"
    "${HEADER_DIR}/Utility.hpp")
SET(SOURCES
    "${SOURCE_DIR}/Generator.cpp"
    "${SOURCE_DIR}/Process.cpp"
    "${SOURCE_DIR}/Transducer.cpp"
    "${SOURCE_DIR}/Utility.cpp")

ADD_EXECUTABLE( "Main.out" "${SOURCE_DIR}/Main.cpp" ${KERNEL_HEADERS} ${KERNEL_SOURCES} ${HEADERS} ${SOURCES} )
