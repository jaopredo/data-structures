all: programa

programa: main.o conversao.o
	g++ main.o conversao.o -o programa

main.o: main.cpp conversao.h
	g++ -c main.cpp -o conversao.o

conversao.o: conversao.cpp conversao.h
	g++ -c conversao.cpp -o conversao.o

clean:
	rm -f *.o programa