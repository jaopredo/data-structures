# Aula 10: Exercícios sobre Tipos Abstratos de Dados (TAD) (RESOLUÇÃO)

## Questão 1

Dada a estrutura de pilha, ilustre o estado da pilha após a execução sequencial das seguintes operações:
(**OBS**: O estado B leva em conta as operações feitas no estado A)

(a) push(10) -> push(70) -> push(25) -> push(-50);
```py
[10, 70, 25, -50]
```

(b) pop() -> pop();
```py
[10, 70]
```

(c) push(13) -> pop() -> pop() -> push(10)
```py
[10, 70, 13] => [10, 70] => [10] => [10, 10]
```

## Questão 2

Dada a estrutura de fila, ilustre o estado da fila após a execução sequencial das seguintes operações:
(**OBS**: O estado B leva em conta as operações feitas no estado A)

(a) enqueue(10) -> enqueue(70) -> enqueue(25) -> enqueue(-50);
```py
[10, 70, 25, -50]
```

(b) dequeue() -> dequeue();
```py
[70, 25, -50] => [25, -50]
```

(c) enqueue(13) -> dequeue() -> dequeue() -> enqueue(10).
```py
[25, -50, 13] => [-50, 13] => [13] => [13, 10]
```

## Questão 3

Dada a estrutura de fila implementada com um array de tamanho `4`, ilustre o estado do array após a execução sequencial das seguintes operações:
(**OBS**: O estado B leva em conta as operações feitas no estado A)

(a) enqueue(10) -> enqueue(70) -> enqueue(25) -> enqueue(-50);
```py
[10, 70, 25, -50]
```

(b) dequeue() -> dequeue();
```py
[25, -50]
```

(c) enqueue(13) -> dequeue() -> dequeue() -> enqueue(10).
```py
[25, -50, 13] => [13] => [13, 10]
```

## Questão 4

### Inversão de uma fila usando uma pilha

Dada uma fila `L`, escreva um algoritmo que gere uma nova fila `R` contendo os elementos de `L` na ordem reversa utilizando uma estrutura de pilha.

**Exemplo:**

Entrada:
`L = [A, B, C, D]`

Saída esperada:
`R = [D, C, B, A]`

```cpp
Queue* invert_queue(Queue* q1) {
    Queue* q2 = initialization_queue(q1->size);
    // Fila q1 invertida

    int value;
    Stack* s = initialization_stack(q1->size);

    // Adicionando item por item na pilha
    for (int i = q1->size-1; i >= 0; i--) {
        dequeue_queue(q1, &value);
        push_stack(s, value);
    }

    for (int i = q1->size-1; i >= 0; i--) {
        pop_stack(s, &value);
        enqueue_queue(q2, value);
    }

    return q2;
}
```

## Questão 5

Explique como implementar duas pilhas em um único array de maneira eficiente.

**Resulução**\
Podemos criar duas variáveis indicando os índices que ambas as pilhas estão apontado, óbvio que depende do tamanho da pilha que eu quero, mas, para evitar muitos desvios, vamos considerar que ambas tem o mesmo tamanho e esse tamanho é o tamanho do array, basta que uma aponte para o primeiro elemento do array e a outra pro último, ou seja, uma é a inversa da outra

## Questão 6

Implemente a busca sequencial em uma lista circular.

## Questão 7

Enquanto uma pilha permite inserção e remoção de elementos apenas em uma extremidade e uma fila permite inserção em uma extremidade e remoção na outra, uma deque (double-ended queue, ou fila de extremidade dupla) permite inserção e remoção em ambas as extremidades.

Implemente quatro procedimentos de tempo $O(1)$ para:

* Inserir no início;
* Inserir no fim;
* Remover do início;
* Remover do fim.

**OBS**: Considere uma deque implementada com um array.

## Questão 8

Mostre como implementar uma fila utilizando duas pilhas.
Analise o tempo de execução das operações.

## Questão 9

Implemente a estrutura de dados **Pilha com Mínimo**, que deve conter as operações:

- `push` (empilhar)
- `pop` (desempilhar)
- `getMinValue` (retornar o valor mínimo na pilha)

### Estrutura base:
```cpp
struct Stack {
    int* data;
    int maxSize;
    int size;
    <Estruturas adicionais necessárias>
};
```

(a) Implemente a função `getMinValue` 'com complexidade $O(n)$

(b) Como você implementaria essa função em $O(1)$? Quais estruturas de dados adicionais poderiam ser adicionadas à `struct Stack` para garantir complexidade $O(1)$ para as operações `Insert`, `Delete` e `getMinValue`?

## Questão 10

Agora, dado uma fila, implemente a operação `getMinValue`, que retorna o menor valor na fila:

(a) Implemente a função com complexidade $O(n)$

(b) Se soubéssemos que a fila só receberia valores no intervalo $[1, 10]$, seria possível implementar uma solução mais eficiente? Explique como otimizá-la.
