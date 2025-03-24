#include <iostream>

using namespace std;

int main() {
    int n = 10;  // Tamanho dos arrays

    int arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* inverted_arr[n];

    for (int i = 0; i < n; i++) {
        inverted_arr[i] = arr + n - i - 1;

        cout << *inverted_arr[i] << endl;  // Mostrando o array invertido
    }

    return 0;
}
