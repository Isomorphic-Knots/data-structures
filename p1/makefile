CC = g++ -std=c++11 -Wall -pedantic

all: driver.x mydriver.x

driver.x: driver.cpp
	$(CC) driver.cpp -o driver.x 

mydriver.x: mydriver.cpp
	$(CC) mydriver.cpp -o mydriver.x
    
clean: 
	rm *.x
