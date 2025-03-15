g++ -c /mnt/Github/ED/listas_definitivas/lista_1/PatientArray.cpp -o /mnt/Github/ED/listas_definitivas/lista_1/PatientArray.o
g++ -c /mnt/Github/ED/listas_definitivas/lista_1/main.cpp -o /mnt/Github/ED/listas_definitivas/lista_1/main.o
g++ -fsanitize=address /mnt/Github/ED/listas_definitivas/lista_1/PatientArray.o /mnt/Github/ED/listas_definitivas/lista_1/main.cpp -o main
