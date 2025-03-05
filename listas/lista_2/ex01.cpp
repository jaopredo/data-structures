#include <iostream>

using namespace std;

void param_copia(int x) {
    x = 10;  // Vou alterar o valor da variável x
    cout << "Dentro da função, x tem valor " << x << endl;
}

void param_ref(int& y) {
    y = 40;  // Alterando o valor do rótulo x
    cout << "Dentro da função, x é 40" << endl;
}

void param_end(int* z) {
    *z = 50;  // Alterando o valor no endereço de z
    cout << "Dentro da função, Z tem valor de " << z << endl;
    cout << "O valor do endereço de Z é " << *z << endl;
}

int main() {
    int x = 20;

    // Parâmetro por cópia
    param_copia(x);
    cout << "Valor de x fora da função copia é " << x << endl;

    // Parâmetro por referência
    int y = 10;
    param_ref(y);
    cout << "Fora da função, y tem o valor " << y << endl;

    // Parâmetro por endereço
    int z = 10;
    param_end(&z);
    cout << "Fora da função, z tem o valor " << z << endl;

    return 0;
}
