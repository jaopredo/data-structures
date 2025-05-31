# Semana 7: Exercícios sobre Ordenação

## Questão 1
- a\) Como encontrar o índice da primeira ocorrência do valor $x$ em uma lista ordenada? Implemente um algoritmo eficiente para resolver esse problema. Justifique a escolha do seu método e analise sua complexidade.
```cpp
// Aqui eu percorro a lista de forma que, se o valor que eu estou analisando é maior que o valor que estou procurando, então o valor que eu estou procurando NÃO ESTÁ NA LISTA. De forma que, se o pior caso é eu estar procurando um valor maior que o último valor da lista (Vai dar complexidade O(n))
int first_occurence_index(int* l, int size, int value, int* index) {
    for (int i = 1; i < size; i++) {
        if (l[i] == value) {
            *index = i;
            return 1;
        }
        if (l[i] > value) {
            return 0;
        }
    }

    return 0;
}
```

- b\) Como encontrar o índice da última ocorrência do valor $x$ em uma lista ordenada? Implemente um algoritmo eficiente para resolver esse problema. Justifique a escolha do seu método e analise sua complexidade.

```cpp
// Segui uma lógica parecida, com a diferença que eu troquei para comparar se o elemento anterior é igual ao valor que quero encontrar e se o valor atual que estou olhando é maior, e para que o valor não esteja na lista, basta que tanto o atual quanto o anterior sejam maiores que o valor analisado
int last_occurence_index(int* l, int size, int value, int* index) {
    for (int i = 1; i < size; i++) {
        if (l[i-1] == value && l[i] > value) {
            *index = i-1;
            return 1;
        }
        if (l[i-1] > value && l[i] > value) {
            return 0;
        }
    }

    return 0;
}
```

- c\) Com base nas soluções das questões anteriores, implemente um algoritmo que determine quantos elementos estão dentro do intervalo $[x, y]$ em uma lista ordenada. Qual é a complexidade da sua solução?

    Eu nem preciso fazer código aqui, basta que eu execute `a = first_occurence_index(lista, ..., x, ...)` e `b = last_occurence_index(lista, ..., x, ...)`, depois, faço `b - a + 1` (Troco `b` e `a` de posição dependendo de quem for maior, mas a questão da a entender que `b` é sempre maior)

## Questão 2
Implemente o algoritmo de ordenação por inserção (Insertion Sort). Analise sua complexidade no pior e no melhor caso.

## Questão 3
Implemente o algoritmo de ordenação por bolha (Bubble Sort) utilizando:

a) Arrays. Analise a complexidade de pior caso do algoritmo implementado.

b) Listas simplesmente encadeadas. Compare a eficiência e a dificuldade de implementação em relação à versão com arrays.

## Questão 4
   Dada uma lista de tuplas $(x, y)$, implemente um algoritmo que ordene a lista primeiramente pelo valor de $x$ e, em caso de empate, pelo valor de $y$. Explique como sua abordagem garante a ordenação correta e analise a complexidade do seu algoritmo.

## Questão 5
   Suponha que você tem um array onde cada elemento está deslocado em no máximo $k$ posições da sua posição final na ordenação. Modifique o algoritmo de ordenação por inserção (Insertion Sort) para torná-lo mais eficiente neste caso. Justifique sua abordagem e analise a complexidade da solução otimizada.
