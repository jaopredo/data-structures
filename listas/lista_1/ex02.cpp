#include <iostream>
#include <string>

using namespace std;


float sum_arr_items(float* arr, int arr_size) {
    float sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }
    return sum;
}


int main() {
    int arr_size = 0;
    cout << "Digite o tamanho do Array que você quer criar" << endl;
    cin >> arr_size;

    float arr[arr_size];
    cout << "Digite o número desejado e aperte Enter para ir para o próximo número:" << endl;
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }

    cout << "A soma dos valores do seu array foi: " << sum_arr_items(arr, arr_size) << endl;

    return 0;
}
