cmake_minimum_required(VERSION 3.5)

project(C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A
)

# find_package(GTest REQUIRED)
# find_package()
# include(GoogleTest)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/B)
add_subdirectory(googletest)

 
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE}/googletest)
include_directories(${GTEST_INCLUDE_DIRS})


set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/A/index.cpp) 

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h ${CMAKE_CURRENT_SOURCE_DIR}/B/lib.h ${CMAKE_CURRENT_SOURCE_DIR}/C/main.h)


make_directory(${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)



set(SOURCES2 ${CMAKE_CURRENT_SOURCE_DIR}/C/main_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/C/testing.cpp ${CMAKE_CURRENT_SOURCE_DIR}/A/index.cpp ${CMAKE_CURRENT_SOURCE_DIR}/B/lib.cpp)
set(HEADERS2 ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h ${CMAKE_CURRENT_SOURCE_DIR}/B/lib.h)

add_executable(C ${SOURCES} ${HEADERS})
add_executable(CTest ${SOURCES2} ${HEADERS2})

target_link_libraries(C lib_B)
target_link_libraries(CTest gtest_main)
target_link_libraries(CTest gtest)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread)
target_link_libraries(CTest lib_B)

enable_testing()




