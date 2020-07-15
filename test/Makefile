CXX=g++
CXXFLAGS=-std=c++11 -I../
TARGET=xf32.test

$(TARGET):main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(TARGET)
