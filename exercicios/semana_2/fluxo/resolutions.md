# Semana 2: Exercícios sobre Controle de Fluxo

## Questão 1
Escreva uma função que receba um número inteiro e imprima se ele é positivo, negativo ou zero.

```cpp
int main() {
    int num = 0;
    cin >> num;
    if (num < 0) {
        cout << "Número digitado é negativo" << endl;
    } else if (num > 0) {
        cout << "Número digitado é positivo" << endl;
    } else {
        cout << "Número digitado é igual a 0" << endl;
    }
}
```

## Questão 2
Escreva uma função que receba um array de inteiros e o tamanho do array, e retorne a soma de todos os elementos do array.
```cpp
float sum_arr_items(float* arr, int arr_size) {
    float sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }
    return sum;
}
```

## Questão 3
Escreva uma função que receba um número inteiro e retorne true se o número for primo e false caso contrário.

```cpp
int main() {
    int target_num = 0;
    bool prime = true;
    cout << "Descubra se o número é primo, digite o número desejado" << endl;

    cin >> target_num;

    for (int i = 0; i <= sqrt(target_num); i++) {
        if (target_num % i == 0) {
            prime = false;
            // break;
        }
    }

    if (prime) {
        cout << "O número passado não é primo!" << endl;
    } else {
        cout << "O número passado é primo!" << endl;
    }

    return 0;
}
```