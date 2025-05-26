# Semana 2: Exercícios sobre Ponteiros

## Questão 1
Crie um programa que demonstre a diferença entre passar um parâmetro por valor, referência e ponteiro. O programa deve:
- Definir uma função para cada tipo de passagem.
- Mostrar o efeito de cada método no valor original da variável.

```cpp
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
```

## Questão 2
Implemente uma função que receba dois ponteiros para inteiros e troque os valores das variáveis. No main, crie duas variáveis, imprima seus valores antes e depois da troca.

```cpp
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
```

## Questão 3
Crie uma função que inverta os elementos de um array utilizando ponteiros. No main, crie um array, imprima os valores antes e depois da inversão.

```cpp
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
```

## Questão 4
Implemente uma função que receba duas matrizes 2x2 e calcule a soma delas. No main, crie duas matrizes, chame a função para somá-las e imprima a matriz resultante.

```cpp
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
```
