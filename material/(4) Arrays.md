# Arrays
Array são variáveis que armazenam valores do mesmo tipo em endereços de memória sequênciais:

**Variáveis Independentes:**
```cpp
int x = 10;
int y = 20;
int z = 30;
```

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
| `x`       | 0x1000    | 10     |
|           | 0x1004    |        |
|           | 0x1008    |        |
|           | 0x100C    |        |
| `y`       | 0x1008    | 20     |
|           | 0x1010    |        |
|           | 0x1014    |        |
| `z`       | 0x1018    | 30     |
|           | 0x101C    |        |
|           | 0x1020    |        |

**Arrays:**
```cpp
int a[3];
int a[0] = 10;
int a[1] = 20;
int a[2] = 30;
```

| Variável  | Endereço  | Valor  |
|-----------|-----------|--------|
|           | 0x1000    |        |
|           | 0x1004    |        |
| a[0]      | 0x1008    | 10     |
| a[1]      | 0x100C    | 20     |
| a[2]      | 0x1008    | 30     |
|           | 0x1010    |        |

Ele faz isso pois, como declaramos o tipo de cada valor do Array, a máquina consegue fazer uma matemática para calcular o próximo valor. Exemplo: Temos um array de `int`, sabemos que ele tem 4 bytes, então ao armazenar o primeiro elemento, eu avanço exatamente 4 bytes na memória, de forma que o próximo elemento está logo ao lado do último.

Ao declarar um array, o nome do mesmo se torna um ponteiro do primeiro elemento, exemplo:
```cpp
int arr[3] = { 1, 2, 3 };

cout << arr << endl;
cout << &arr[0] << endl;
// Saídas são iguais
```

## Arrays n-dimensionais
Para declarar um array com mais de uma dimensão, basta indicar quantos arrays ele terá dentro dele. Exemplo de um array bidimensional:

```cpp
int arr[3][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
};
```

## Acessando espaços não alocados
É possível no C++ acessar espaços de memória não alocados para o array em específico:
```cpp
int arr[3] = { 1, 2, 3 };
cout << arr[3] << endl;  // Mostrará lixo
```

Isso ocorre pela matemática descrita antes, já que o índice mostra quantos bytes o compilador deverá andar na memória a partir do endereço do primeiro valor, então descrever um valor maior do que o máximo do array é possível, mesmo que seja inútil;

## Passando arrays para funções
Como descrito antes, a variável do array é um ponteiro para o primeiro elemento do array, então ao passar como parâmetro de uma função, devemos fazer com que esse parâmetro seja um ponteiro:

```cpp
void exibirArray(int * p, int tamanho) {
    ...
}

int main() {
    int tamanho_array = 3;
    int arr[tamanho_array] = {1, 2, 3};

    exibirArray(arr, tamanho_array);
    ...
}
```

Então utilizamos o ponteiro dentro da função `exibirArray`

## Somando ponteiros
Se um ponteiro `p` é de tipo `T` e `n` um número inteiro, então a operação `p + n` faz com que o ponteiro ande `n*sizeof(T)` bytes. Isso quer dizer que, se temos o ponteiro de um array, podemos percorrer seus elementos apenas utilizando um ponteiro que aponta para um elemento e sabendo qual elemento ele está apontando.
