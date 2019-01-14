project(ysw_cpp_example)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

# Chapter 04
set(APP_EXE coding_interview)
set(SRC_DIR src)
set(HDR_DIR hdr)
set(SOURCES ${SRC_DIR}/main.cpp ${SRC_DIR}/SimpleLinkedList.cpp)
set(HEADER_FILES ${HDR_DIR}/SimpleLinkedList.h)

ADD_EXECUTABLE(${APP_EXE}
                ${SOURCES}
                ${HEADER_FILES})


target_include_directories(${APP_EXE} PRIVATE ${HDR_DIR})