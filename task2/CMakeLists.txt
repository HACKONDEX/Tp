cmake_minimum_required(VERSION 3.0)

project(C)

# execute_process(COMMAND echo where_am_I)
# execute_process(COMMAND pwd)
# execute_process(COMMAND echo CURRENT_SOURCE_DIR)
# execute_process(COMMAND echo ${CMAKE_CURRENT_SOURCE_DIR})
# execute_process(COMMAND echo PROJECT_SOURCE_DIR)
# execute_process(COMMAND echo ${PROJECT_SOURCE_DIR})

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/B)

include_directories(PUBLIC ${CMAKECMAKE_CURRENT_SOURCE_DIR}/A
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}/B
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}/C
                    ${CMAKECMAKE_CURRENT_SOURCE_DIR}
)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h ${CMAKE_CURRENT_SOURCE_DIR}/B/lib.h ${CMAKE_CURRENT_SOURCE_DIR}/C/main.h)


make_directory(${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(C ${SOURCES} ${HEADERS})


link_libraries(C lib_B)



