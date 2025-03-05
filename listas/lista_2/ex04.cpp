#include <iostream>

using namespace std;

void somar_matriz_2x2(int (*matriz_1)[2], int (*matriz_2)[2]) {
    int matriz[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matriz[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriz[i][j] << endl;
        }
    }
}

int main() {
    int matriz_1[2][2] = {
        { 1, 2 },
        { 3, 4 }
    };
    int matriz_2[2][2] = {
        { 9, 12 },
        { 8, 31 }
    };

    somar_matriz_2x2(matriz_1, matriz_2);

    return 0;
}
