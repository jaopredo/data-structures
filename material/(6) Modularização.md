# Modularização
## Protótipo de Funções
Quando executamos uma função antes de sua declaração, obtemos um erro! Porém, podemos evitar esse erro ao criar o seu *protótipo*

```cpp
// Protótipo
int somar_inteiros(int x, int y);

void exibir_soma(int x, int y) {
    cout << somar_inteiros(x, y) << endl;
}

// Implementando a função
int somar_inteiros(int x, int y) {
    return x + y
}
```

Esse código flui normalmente!

## Sobrecarga de funções
A sobrecarga de funções é um método de utilizar o mesmo nome de função em funções "diferentes". Veja o exemplo a seguir:

```cpp
void exibir(int x, int tamanho);
void exibir(char s, int tamanho);
void exibir(double d, int tamanho);

exibir(3, 6)
```
O compilador vai escolher qual das opções declaradas antes a função deverá chamar de acordo com os tipos dos parâmetros passados!

## Separando os arquivos
Para separar um código C++, temos dois tipos de arquivo: 

- **Cabeçalho**: Arquivos responsáveis pela declaração dos protótipos das funções (arquivo.h);
- **Implementação**: Arquivo responsável pela implementação do comportamento das funções (arquivo.cpp);

Criamos primeiro um arquivo de cabeçalho para declarar as funções que eu terei em meu módulo:

`operadores.h`
```h
#ifndef OPERADORES_H
#define OPERADORES_H

// Declaração das funções
int soma(int a, int b);
int subtracao(int a, int b);

#endif
```

Depois, criamos o arquivo que vai implementar o comportamento das funções:

`operadores.cpp`
```cpp
#include "operacoes.h"

// Implementação das funções
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}
```

Podemos então utilizar o nosso módulo no arquivo principal:

```cpp
#include <iostream>
#include "operadores.h"

int main() {
    std::cout << "Soma: " << soma(3, 2) << std::endl;
    std::cout << "Subtracao: " << subtracao(5, 1) << std::endl;
    return 0;
}
```

## Namespaces
Como o nome sugerem, são como espaços responsáveis por gerir nomes, eles permitem que duas variáveis tenham o mesmo rótulo, desde que estejam em `namespaces` diferentes:

```cpp

namespace first {
    int x = 1;
}

namespace second {
    int x = 2
}

int main() {
    int x = 0;

    cout << x << endl;  // Retorna 0
    cout << first::x << endl;  // Retorna 1
    cout << second::x << endl;  // Retorna 2
}

```
