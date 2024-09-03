CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -Werror -pedantic -O3 -Iinclude
LDLIBS=-lstdc++ -lm -lcurl

all: sample

sample: src/sample.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
