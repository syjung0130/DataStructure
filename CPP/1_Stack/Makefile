.SUFFIXES : .c .cpp .o

OBJECTS	=	main.o stack.o
SRCS = main.cpp stack.cpp

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

#main.o : main.cpp
#stack.o : stack.h stack.cpp
