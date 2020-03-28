cmake_minimum_required(VERSION 2.8)


set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
set(CMAKE_ASM_COMPILER arm-linux-gnueabihf-gcc)

set(CMAKE_FIND_ROOT_PATH ${SYSROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY))

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set(CMAKE_SYSTEM_PROCESSOR arm)

project(SimpleLibrary)

# 1 #################################

# set(CMAKE_CROSSCOMPILING TRUE)
# set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_PROCESSOR arm)

# set(CMAKE_SYSROOT /home/hakob/Sysroot-TP/sysroot-glibc-linaro-2.25-2019.12-armv8l-linux-gnueabihf)

# set(triple ${CMAKE_CURRENT_SOURCE_DIR}/../../../Toolchain_TP/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/arm-linux-gnueabihf)

# # set(CMAKE_C_COMPILER /home/hakob/Toolchain_TP/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/arm-linux-gnueabihf-g++)
# set(CMAKE_C_COMPILER clang)
# set(CMAKE_C_COMPILER_TARGET ${triple})
# set(CMAKE_CXX_COMPILER ${CMAKE_CURRENT_SOURCE_DIR}/../../../Toolchain_TP/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/arm-linux-gnueabihf)
# set(CMAKE_CXX_COMPILER_TARGET ${triple})
 
# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

if(IS_ ON ARM_BUILD)


else()




# 2 ###############################

# set(CMAKE_SYSTEM_NAME Linux)

# set(CMAKE_SYSROOT /home/hakob/Sysroot-TP/sysroot-glibc-linaro-2.25-2019.12-armv8l-linux-gnueabihf)

# set(CMAKE_C_COMPILER /home/hakob/Toolchain_TP/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
# set(CMAKE_CXX_COMPILER /home/hakob/Toolchain_TP/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)
# set(CMAKE_ASM_COMPILER /home/hakob/Toolchain_TP/gcc-linaro-7.5.0-2019.12-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
# set(CMAKE_SYSTEM_PROCESSOR arm)


   




################################

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

######################################################


