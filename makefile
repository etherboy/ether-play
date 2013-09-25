 CXX=g++ -std=c++11

playground : main.o
	$(CXX) -o playground main.o

main.o : main.cpp
	$(CXX) -c -w main.cpp

clean :
	rm playground *.o
