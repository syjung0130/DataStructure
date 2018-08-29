.SUFFIXES : .c .o

OBJECTS	=	binary_tree_main.o binary_tree.o
SRCS = binary_tree_main.c binary_tree.c

CXX = gcc
CFLAGS = -lstring -libstdc++

all: binary_tree_main
binary_tree_main: $(OBJECTS)
	$(CXX) -o binary_tree_main $(OBJECTS)
clean:
	rm -rf $(OBJECTS)
	rm -rf $(TARGET)
