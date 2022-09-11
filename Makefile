CC=g++

main: index.o main.o 
	$(CC) main.o -c index.o superTrunfo.h
main.o: main.cpp
	$(CC) -c main.cpp -o main.o
index.o: index.cpp 
	$(CC) -c index.cpp -o index.o
clean:
	rm *.o