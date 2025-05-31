#include "../../modules/tad.h"
#include <iostream>

using namespace std;
using namespace TAD;


int first_occurence_index(int* l, int size, int value, int* index) {
    for (int i = 1; i < size; i++) {
        if (l[i] == value) {
            *index = i;
            return 1;
        }
        if (l[i] > value) {
            return 0;
        }
    }

    return 0;
}


int last_occurence_index(int* l, int size, int value, int* index) {
    for (int i = 1; i < size; i++) {
        if (l[i-1] == value && l[i] > value) {
            *index = i-1;
            return 1;
        }
        if (l[i-1] > value && l[i] > value) {
            return 0;
        }
    }

    return 0;
}


void print_list(int* l, int size, int list_to_show = 0) {
    if (list_to_show != 0) {
        cout << "Lista " << list_to_show << ":" << endl;
    }
    
    for (int i = 0; i < size; i++) {
        cout << l[i] << " ";
    }

    cout << endl;
}


int main() {
    int size = 12;
    int l[size] = { 1, 3, 3, 5, 6, 7, 7, 8, 9, 9, 9, 10 };

    cout << "Minha lista:" << endl;
    print_list(l, size, 1);

    cout << "Índices Encontrado: " << endl;
    int index_1 = 0;
    first_occurence_index(l, size, 9, &index_1);
    cout << index_1 << endl;

    int index_2 = 0;
    last_occurence_index(l, size, 9, &index_2);
    cout << index_2 << endl;
}