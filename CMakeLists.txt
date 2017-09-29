cmake_minimum_required (VERSION 2.8)
project (u8filesystem)

if(MSVC)
    add_definitions("/FI\"${CMAKE_CURRENT_SOURCE_DIR}/precmp.h\"")
else()
    add_definitions("-include \"${CMAKE_CURRENT_SOURCE_DIR}/precmp.h\"")
endif()

file(GLOB SOURCE_FILES "*.h" "*.cpp")
add_library(u8fs STATIC ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(test)
