# Semana 4: Complexidade de Algoritmos

## Questão 1

Suponha que temos dois algoritmos $T_1$ e $T_2$ para resolver um determinado problema,
com os seguintes tempos de execução:

* $T_1(n) = 625n$;
* $T_2(n) = n^2$.

Responda:
1. Qual é a complexidade assintótica de cada algoritmo?

Complexidade $T_1 = O(n)$ e $T_2 = O(n^2)$

2. Para quais valores de $n$ o algoritmo $T_1$​ é mais eficiente que o $T_2$​, e para quais valores $T_2$​ se torna mais eficiente que $T_1$​?

$T_1 \lt T_2 \Leftrightarrow n \lt 625$

$T_1 = T_2 \Leftrightarrow n = 625$

$T_1 \gt T_2 \Leftrightarrow n \gt 625$

Logo, $T_1$ é mais eficiente que $T_2$ para $n \gt 625$

## Questão 2
O custo computacional $T_i(n)$ de diversos algoritmos é mostrado abaixo.\
Qual a complexidade de cada algoritmo? Ponha-os em ordem crescente de complexidade.
* $T_1(n)    = nlog(n)+log(n)$;

$T_1(n) = nlog(n) + log(n)$, como o termo $nlog(n)$ cresce muito mais rápido que $log(n)$, temos $O(nlog(n))$

* $T_2(n)    = 2n + n^3 + 25$;

$T_2(n) = O(n^3)$

* $T_3(n,k)  = n+k$ onde $k \le n$

$T_3(n, k) = n + k /k \le n = O(n)$

* $T_4(n)    = n + log(n)$;

$T_4(n) = n+log(n)$, como $n$ cresce mais rápido que $log(n)$ quando $n \rightarrow \infty$, logo $T_4(n) = O(n)$

* $T_5(n)    = 100n log(n) + n^3 + 100n$;

$T_5(n) = 100n log(n) + n^3 + 100n$, nesse caso, $n^3$ explode quando $n \rightarrow \infty$, então $T_5(n) = O(n^3)$

* $T_6(n)    = 0.01n log(n) + n (log(n))^2$;

$T_6(n)    = 0.01n log(n) + n (log(n))^2$, como $n(log(n))^2$ cresce mais rapidamente que $0.01 n log(n)$, então a complexidade é $O(nlog^2(n))$

* $T_7(n)    = 2n + n^{0.5} + 0.5n^{1.25}$;

$T_7(n) = 2n + \sqrt{n} + 0.5n^{1.25}$, primeiramente, desconsideramos as constantes. $T_7(n) \sim n + \sqrt{n} + n^{1.25} $, tendendo ao infinito, o $n$ com maior expoente cresce mais rápido, consequentemente, este será $O(n^{1.25})$

* $T_8(n)    = 0.01n + 100n^2$;

$T_8(n) = 0.01n + 100n^2$. Desconsideramos as constantes: $T_8(n) \sim n + n^2$, logo $O(n^2)$

* $T_9(n)    = 100n + 0.01n^2$;

$T_9(n) = 100n + 0.01n^2 \sim n + n^2 = O(n^2)$

* $T_{10}(n) = T(n) = 2T(n-1)+2$ para $n > 1$ e $T(1)=O(1)$; **Dica**: `método da árvore de recursão`

$T_{10}(n) = T(n) = 2T(n-1)+2$ para $n > 1$ e $T(1)=O(1)$, fazemos então: $T(n) = 2T(n-1)+2 = 2(T(n-1) + 1) = 2*2T(n-2) + 4$, generalizando: $T(n) = 2^nT(1) + 2n$, logo $T(n) = O(2^n)$

## Questão 3

Calcule a complexidade dos algoritmos abaixo:

1. Loops em sequência
    ```c
    int a = 0, b = 0;
    for (i = 0; i < n; i++) {
        a = a + i;
    }
    for (j = 0; j < m; j++) {
        b = b + j;
    }
    ```
    $n + n = O(n)$

2. Loop com condicionais
    ```c
    float what2(int *arr, int n) {
        int a = 0;
        for (int i = 0; i < n; i++) {
            if(arr[i] > 10) {
                for (int j = 0; j < n; j++) {
                    a += n / 2;
                }
            } else {
                printf("ok :(")
            }
        }
    }
    ```
    Analisamos o pior caso, que é `arr[i] > 10`, logo, temos $\sum_{i=1}^n\sum_{j=1}^n1 = nn=n^2 = O(n^2)$

3. Loops duplo
    ```c
    int a = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            a += i + j;
        }
    }
    ```
    $\sum_{i=1}^n\sum_{j=i}^n1 = \sum_{i=1}^n(n-i+1) = \sum_{i=1}^nn - \sum_{i=1}^ni + \sum_{i=1}^n1$, com certeza o maior termo será $n^2$, logo temos $O(n^2)$

4. Loops duplo com constantes
    ```c
    float what4(int *arr, int n) {
        int a = 0;
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 5000; j++) {
                a += i + j;
            }
        }
    }
    ```
    Será $O(1)$ pois independente do tamanho do array, a execução será sempre a mesma

5. Loops com crescimento em progressão geométrica
    ```c
    int a = 0;
    for (int i = n/2; i <= n; i++) {
        for (int j = 2; j <= n; j = j * 2) {
            a += i + j;
        }
    }
    ```
    O loop interno tem o índice crescendo de 2 em 2, então temos $j_k = 2^k$, assim, como $j \le n$, então temos: $2^k \le n \Leftrightarrow log_2(2^k) \le log_2(n) \Leftrightarrow k \le log_2(n) \Rightarrow O(log(n))$, já o loop externo tem $O(n)$, portanto, no total, temos $O(nlog(n))$

6. Loop com crescimento logarítmico
    ```c
    int a = 0, i = n;
    while (i > 0) {
        a += i;
        i /= 2;
    }
    ```
    Temos que o termo i decresce metade a cada iteração, logo: $i_k = \frac{n}{2k}$, porém, isso é equivalente a iniciar com $i=1$ e ir duplicando seu valor e somando à variável `a`, e o loop parar somente quando `i>=n`. Obtemos então a mesma situação de antes, $i_k = 2^k \Leftrightarrow i_k \le n \Leftrightarrow 2^k \le n \Leftrightarrow log_2(2^k) \le log_2(n) \Leftrightarrow k \le log_2(n) \Rightarrow O(log(n))$

7. Loop duplo com redução logarítmica
    ```c
    int a = 0, i = n;
    while (i > 0) {
        for (int j = 0; j < i; j++) {
            a += i;
        }
        i /= 2;
    }
    ```
    Vamos ver como fica os somatórios totais: $\sum_{j=0}^n1 + \sum_{j=0}^{\frac{n}{2}}1 + \sum_{j=0}^{\frac{n}{4}}1 + ... + \sum_{j=0}^11 = n + \frac{n}{2} + \frac{n}{4} + ... + 1$. Perceba que a quantidade de iterações não depende de $log(n)$ (Que seria o loop externo), logo, a complexidade do algoritmo é $O(n)$

8. Soma dos elementos de um vetor
    ```c
    float soma(float *arr, int n) {
        float total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        return total;
    }
    ```
    Sem muito mistério, cresce linearmente com as entradas do vetor, logo $O(n)$

9. Busca sequencial
    ```c
    int buscaSequencial(int *arr, int n, int x) {
        for (int i = 0; i < n; i++){
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
    ```
    O pior de todos os casos é quando eu preciso percorrer o array completamente, logo, tenho $O(n)$

10. Busca binária
    ```c
    int buscaBinaria(int *arr, int x, int i, int j) {
        if (i >= j) {
            return ‐1;
        }

        int m = (i + j) / 2;
        if (arr[m] == x) {
            return m;
        } else if ( x < arr[m] ) {
            return buscaBinaria (arr, x, i, m‐1);
        } else {
            return buscaBinaria (arr, x, m+1, j);
        }
    }
    ```
    Na recorrência, nós pegamos o índice médio entre $i$ e $j$, e se $x$ for menor que o valor do array que está lá, nós fazemos a busca novamente, utilizando os novos índices sendo $m-1$ e $i$, assim, o novo valor de índice será $\frac{i+\frac{i+j}{2}-1}{2} = \frac{2i+i+j-2}{4}$. Perceba que o tamanho de itens que eu vou precisar percorrer a cada iteração diminui pela metade, então, seja $i_k$, a quantidade de itens que eu preciso percorrer na k-ésima iteração, eu vou ter: $i_k \ge 1 \Leftrightarrow \frac{n}{2^k} \le 1 \Leftrightarrow n \le 2^k \Leftrightarrow log_2(n) \le log_2(2^k) \Leftrightarrow log_2(n) \le k \Rightarrow O(log(n))$

11. Multiplicação de matrizes
    ```c
    void multiplicacaiMatriz(float **a, float **b, int n, int p, int m, float **x) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                x[i][j] = 0.0;
                for (int k = 0; k < p; k++) {
                    x[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    ```
    Esse algoritmo não tem muito o que dizer, ele segue uma multiplicação matricial comum, que o mínimo de operações necessárias é $O(n^2)$, porém, nesse caso, temos um algoritmo que demanda $O(nmp)$

## Questão 4 (Extra)

Dada uma lista de números inteiros, queremos encontrar a subsequência contígua de soma máxima.
Ou seja, dado um array de inteiros $A = [a_1, a_2, ..., a_n]$, encontre os índices $i$ e $j$ tal que a soma $a_i+a_{i+1}+...+a_j$​ seja máxima.
Exemplo:

Para a sequência:
$$A=[−2,1,−3,4,−1,2,1,−5,4]$$

A subsequência contígua de soma máxima é $4,−1,2,1$ com soma $6$, e está nos índices $3$ a $6$ (indexação começando em 0).
Itens:
1. Proponha um algoritmo que resolva o problema com complexidade $O(n^3)$.
2. Proponha um algoritmo que resolva o problema com complexidade $O(n^2)$.
3. Existe um algoritmo mais eficiente que $O(n^2)$? Se sim, implemente-o e justifique sua complexidade. Se não, justifique por que não é possível obter uma solução mais eficiente.
