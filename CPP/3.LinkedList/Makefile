.SUFFIXES : .c .cpp .o

OBJECTS	=	main.o SimpleLinkedList.o
SRCS = main.cpp SimpleLinkedList.cpp

CXX = g++
#CFLAGS = -std=c++11 -lstring -libstdc++
#CPPFLAGS = -std=c++11 -lstring -lstdlib -liostream
CPPFLAGS = -std=c++11 -lstring

#TARGET = main

#$(TARGET) : $(OBJECTS)
#	$(CXX) -o $(TARGET) $(OBJECTS)
all: main
main : $(OBJECTS)
	$(CXX) -o main $(OBJECTS)
clean:
	rm -rf $(OBJECTS) $(TARGET)
	rm -rf main
#main.o : main.cpp
#stack.o : stack.h stack.cpp
