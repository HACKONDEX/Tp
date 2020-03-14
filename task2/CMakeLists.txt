cmake_minimum_required(VERSION 3.5)

project(C)

# execute_process(COMMAND echo where_am_I)
# execute_process(COMMAND pwd)
# execute_process(COMMAND echo CURRENT_SOURCE_DIR)
# execute_process(COMMAND echo ${CMAKE_CURRENT_SOURCE_DIR})
# execute_process(COMMAND echo PROJECT_SOURCE_DIR)
# execute_process(COMMAND echo ${PROJECT_SOURCE_DIR})


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A
)



enable_testing()
find_package(GTest REQUIRED)
# find_package()
include(GoogleTest)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/B)

# add_subdirectory(googletest)

 
include_directories(PUBLIC ${CMAKECMAKE_CURRENT_SOURCE_DIR}/A
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}/B
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}/C
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}/googletest
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}
)



set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp) 

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h ${CMAKE_CURRENT_SOURCE_DIR}/B/lib.h ${CMAKE_CURRENT_SOURCE_DIR}/C/main.h)



make_directory(${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)




add_executable(C ${SOURCES} ${HEADERS})
add_executable(CTest ${CMAKE_CURRENT_SOURCE_DIR}/C/main_test.cpp)

target_link_libraries(C lib_B)
target_link_libraries(CTest gtest_main)
target_link_libraries(CTest gtest)
target_link_libraries(CTest pthread)
target_link_libraries(CTest lib_B)
target_link_libraries(C gtest_main)

add_test(
    NAME CTest1
    COMMAND CTest1
)

add_test(
    NAME CTest2
    COMMAND CTest2
)
# target_link_libraries(CTest gtest_main)



