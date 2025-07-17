CXX ?= g++

CXXFLAGS := -Wall -std=c++17 -O2

INCLUDES := -I .

SRCS := extractor.cpp

HEADERS := extractor.h json.hpp

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: extractor$(EXE)
	@:

extractor$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) extractor extractor.exe
