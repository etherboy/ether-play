CXXFLAGS=$(CDEBUG) -std=c++11 -w -pthread

LIBRARIES=
SOURCES=main.cpp futuristic.cpp lamb.cpp
OBJECTS=$(SOURCES:.cpp=.o)

play : $(OBJECTS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJECTS) $(LIBRARIES)

clean :
	-rm -f play *.o
