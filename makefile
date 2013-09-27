 CXXFLAGS=-std=c++11 -w

play : main.o futuristic.o

clean :
	-rm play *.o
