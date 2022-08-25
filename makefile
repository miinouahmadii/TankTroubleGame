CC := g++  -std=c++11
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: test.out

test.out: main.o rsdl.o
	$(CC) main.o rsdl.o $(CCFLAGS) -o test.out

rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o

main.o: rsdl.hpp main.cpp
	$(CC) -c main.cpp -o main.o


.PHONY: clean
clean:
	rm -r *.os