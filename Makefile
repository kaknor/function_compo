CXX=g++
FLAGS= -std=c++14 -Wall -g -o

SRC=src/*.cc
DEP := $(shell find $(SOURCEDIR) -name '*.hh|*.hxx')src/*.hh
BIN=FUNC

all: $(SRC)
	$(CXX) $(FLAGS) $(BIN) $(SRC)

clean:
	$(RM) $(BIN) *~
