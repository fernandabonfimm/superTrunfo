CC=g++
outfile = out

main: main.o superTrunfo.o
	$(CC) main.o superTrunfo.o -o $(outfile)
main.o: main.cpp
	$(CC) -c main.cpp -o main.o
superTrunfo.o: superTrunfo.cpp
	$(CC) -c superTrunfo.cpp -o superTrunfo.o
clean:
	rm *.o $(outfile)

debug: CC+= -g
debug: main