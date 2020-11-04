CXX = g++
CXXFLAGS = -g -Wall -MMD

.PHONY: clean all

all: newton fixed_point

clean:
	rm *.d
	rm *.o
	rm fixed_point

fixed_point: vector.o

newton: vector.o matrix.o

-include *.d

