g++ -c /mnt/Github/ED/modules/tad.cpp -o $1/tad.o
g++ -fsanitize=address $1/tad.o $1/$2.cpp -o $1/$3