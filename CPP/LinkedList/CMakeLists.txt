project(linked_list)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

set(APP_EXE my_template_list)
set(SRC_DIR src)
set(HDR_DIR hdr)
set(SOURCES ${SRC_DIR}/main.cpp ${SRC_DIR}/SimpleLinkedList.cpp ${SRC_DIR}/DoubleLinkedList.cpp ${SRC_DIR}/LinkedList.cpp)
set(HEADER_FILES ${HDR_DIR}/SimpleLinkedList.h ${HDR_DIR}/DoubleLinkedList.h ${HDR_DIR}/LinkedList.h ${HDR_DIR}/TLinkedList.h)

ADD_EXECUTABLE(${APP_EXE}
                ${SOURCES}
                ${HEADER_FILES})


target_include_directories(${APP_EXE} PRIVATE ${HDR_DIR})