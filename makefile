 CXX=g++ -std=c++11

playground : main.o futuristic.o
	$(CXX) -o playground main.o futuristic.o

main.o : main.cpp
	$(CXX) -c -w main.cpp
	
futuristic.o : futuristic.cpp
	$(CXX) -c -w futuristic.cpp

clean :
	-rm playground *.o
