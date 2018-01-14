CC = g++ -std=c++11 -Wall -pedantic
driver =  proj5
server = passserver

$(driver).x: $(driver).o $(server).o
	$(CC) -o $(driver).x $(driver).o $(server).o -lcrypt

$(driver).o: $(driver).cpp
	$(CC) -c $(driver).cpp

$(server).o: $(server).cpp $(server).h hashtable.h hashtable.hpp
	$(CC) -c $(server).cpp

clean: 
	rm *proj5.x
