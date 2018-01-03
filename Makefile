CXX=g++
FLAGS= -std=c++14 -Wall -g -o

SRC=src/*.cc
DEP := $(shell find $(SOURCEDIR) -name '*.hh|*.hxx')
BIN=FUNC

.PHONY: all

all: $(SRC)
	$(CXX) $(FLAGS) $(BIN) -Isrc $(SRC)

clean:
	$(RM) $(BIN) *~ src/*~ /#* src/#*
