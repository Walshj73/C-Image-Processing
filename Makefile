INCLUDES= -I ./include
FLAGS= -g

OBJECTS= ./build/image.o
all: ${OBJECTS}
	mingw32-g++ ${FLAGS} ${INCLUDES} ./src/main.cpp ${OBJECTS} -o ./bin/main

./build/image.o:src/image.cpp
	mingw32-g++ ${FLAGS} ${INCLUDES} ./src/image.cpp -o ./build/image.o

clean:
	del build\*
