# Semana 3: Exercício sobre Modularização

## Questão 1
**Objetivo:** Criar um programa modularizado que implemente um sistema simples de conversão de temperatura (Celsius para Fahrenheit e vice-versa).

1. Criar um arquivo `conversao.h` com a declaração das funções.
2. Criar um arquivo `conversao.cpp` com a implementação das funções.
3. Criar um `main.cpp` para testar as conversões.
4. Criar um `Makefile` para compilar os arquivos separadamente.
---
Arquivo `conversao.h`:
```h
#ifndef CONVERSAO_H
#define CONVERSAO_H

float farenheit_to_celsius(float farenheit);
float celsius_to_farenheit(float celsius);

#endif
```

Arquivo `conversao.cpp`:
```cpp
#include "conversao.h"

float farenheit_to_celsius(float farenheit) {
    return (farenheit - 32) * 5/9;
}

float celsius_to_farenheit(float celsius) {
    return (celsius*5/9 + 32);
}
```

Arquivo `main.cpp`:
```cpp
#include <iostream>
#include "conversao.h"

using namespace std;

int main() {
    int graus_celsius = 100;
    int graus_farenheit = 80;

    cout << CONVERSAO_H::celsius_to_farenheit(graus_celsius) << endl;
    cout << CONVERSAO_H::farenheit_to_celsius(graus_farenheit) << endl;

    return 0;
}
```

Arquivo `makefile`:
```makefile
all: programa

programa: main.o conversao.o
	g++ main.o conversao.o -o programa

main.o: main.cpp conversao.h
	g++ -c main.cpp -o conversao.o

conversao.o: conversao.cpp conversao.h
	g++ -c conversao.cpp -o conversao.o

clean:
	rm -f *.o programa
```