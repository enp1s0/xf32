CXX=g++
CXXFLAGS=-std=c++14 -I../
TARGET=xf32.test

$(TARGET):main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(TARGET)
