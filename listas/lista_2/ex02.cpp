#include <iostream>

using namespace std;

void alterar_inteiros(int* x, int* y) {
    *x = 10;
    *y = 20;
}

int main() {
    int x = 0;
    int y = 0;

    cout << "Valores de x e y antes da execução da função, respectivamente: " << x << ", " << y << endl;
    alterar_inteiros(&x, &y);
    cout << "Valores de x e y depois da execução da função, respectivamente: " << x << ", " << y << endl;

    return 0;
}
