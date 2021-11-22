cmake_minimum_required (VERSION 2.8)

set(PRO_NAME cmake_demo)

project (${PRO_NAME})

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -static")

set(make_type Release1)

if(${make_type} STREQUAL Release1)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3  -DNDEBUG")
	message(STATUS "CMAKE_C_FLAGS or CMAKE_CXX_FLAGS : ${CMAKE_CXX_FLAGS}")
elseif(${make_type} STREQUAL Release2)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Dctest")
	message(STATUS "CMAKE_C_FLAGS or CMAKE_CXX_FLAGS : ${CMAKE_CXX_FLAGS}")
elseif(${make_type} STREQUAL Debug)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
	message(STATUS "CMAKE_C_FLAGS or CMAKE_CXX_FLAGS : ${CMAKE_CXX_FLAGS}")
else()
	message(FATAL_ERROR "make_type configuration error.")
endif()

set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS}")

set(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER  "arm-linux-gnueabihf-g++")

message(STATUS  "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glog/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/glog/lib)

include_directories(./src)
# 添加 src 子目录
add_subdirectory(src)


option(MESSAGE_IF  "MESSAGE_IF configuration" ON)
if(MESSAGE_IF)
	message(STATUS  "MESSAGE_IF is ON")
else()
	message(STATUS  "MESSAGE_IF is OFF")
endif()

# 指定生成目标
add_executable(${PRO_NAME} ${DIR_SRCS})

target_link_libraries(${PRO_NAME} 
#					-static
					cmake_test2
					-lglog  #也可以写成glog				
 					-lpthread
)

#set(CMAKE_EXE_LINKER_FLAGS "-static")
#add_definitions(-DNDEBUG)

set(CMAKE_INSTALL_PREFIX ./output CACHE PATH  "change install path" FORCE)
install (TARGETS ${PRO_NAME} DESTINATION bin)
#install (FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)
	