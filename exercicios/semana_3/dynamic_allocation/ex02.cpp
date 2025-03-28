#include <iostream>

using namespace std;

int* criar_array(int tamanho) {
    int* dyn_arr = new int[tamanho];
    int* pointer_counter = dyn_arr;
    for (int i = 0; i < tamanho; i++) {
        *pointer_counter = i+1;
        pointer_counter += 1;
    }

    return dyn_arr;
}

int main() {
    int n = 10;  // Tamanho do array
    int* arr = criar_array(n);

    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << endl;
    }

    delete[] arr;

    return 0;
}
