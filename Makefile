CXX = g++
CXXFLAGS = -Wall -std=c++0x
CPPLIST = $(wildcard src/*.cpp)

all: $(CPPLIST)

src/%.cpp: force
	$(CXX) $(CXXFLAGS) -o bin/$* $@

force: ;
	
.PHONY: clean

clean:
	rm bin/*