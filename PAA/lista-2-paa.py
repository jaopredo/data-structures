from typing import List, Tuple

############ Atenção ################
# Não altere a assinatura das funções.
# Não altere a classe TreeNode.
# Você pode criar outras funções ou classes se julgar necessário, mas deve defini-las no corpo da função do exercicio.

# ==============================================================================
# Problema de exemplo
# ==============================================================================
def problema_0(A: List[int]) -> List[bool]:
    """
    Recebe uma lista de inteiros e retorna uma lista de booleanos
    indicando se cada numero é primo em tempo O(n * sqrt(maxval)).
    """
    def eh_primo(n: int) -> bool:
        if n==2:
            return True
        if n <= 1 or n%2==0:
            return False
        
        # Iterando apenas nos impares para diminuir a constante
        for i in range(3, int(n**0.5) + 1, 2):
            if n % i == 0:
                return False
        return True

    resultado = []
    for num in A:
        resultado.append(eh_primo(num))

    return resultado


# ==============================================================================
# Problema 1 - A Biblioteca de Alexandria
# ==============================================================================

def problema_1(eventos: List[Tuple[int, int]]) -> Tuple[int, Tuple[int, int]]:
    """
    A administração da biblioteca busca compreender o padrão de uso de seus
    frequentadores e, para isso, precisa identificar o período de pico, ou
    seja, o intervalo de tempo em que há o maior número de usuários presentes.

    O algoritmo deverá receber $n$ pares de inteiros $(a, b)$, onde $a$
    representa o horário de entrada e $b$ o de saída de um usuário. Como
    resultado, ele deve retornar $k, (u, v)$, onde $k$ é a quantidade
    máxima de pessoas na biblioteca e $(u, v)$ é o intervalo de tempo
    maximal (de maior tamanho) correspondente a esse pico. Se houver mais
    de um intervalo de pico maximal, retorne aquele com menor $u$.

    O algoritmo deve ter tempo de execução $O(n \\log n)$.
    """
    auxiliar = []
    eventos_sorted = sorted(eventos, key=lambda event: event[0])

    for i, item in enumerate(eventos_sorted):     # O(n)
        auxiliar.append((item[0], i+1))
        auxiliar.append((item[1], i+1))
    
    auxiliar = sorted(auxiliar, key=lambda item: item[0])     # O(nlog(n))

    start_max_time = 0
    end_max_time = None
    max_pessoas = 0
    last_entered = 0
    num_pessoas = 0

    maximais = []

    for item in auxiliar:
        if item[1] > last_entered:
            num_pessoas += 1
            last_entered = item[1]
        else:
            num_pessoas -= 1
        
        if num_pessoas >= max_pessoas:
            max_pessoas = num_pessoas
            start_max_time = item[0]
        elif num_pessoas + 1 == max_pessoas:
            end_max_time = item[0]
            maximais.append((start_max_time, end_max_time, max_pessoas))
    
    
    definitive_maximal = (0,0)
    k = 0

    for maximal in maximais:
        if maximal[2] > k:
            definitive_maximal = (maximal[0], maximal[1])
            k = maximal[2]
        elif maximal[2] == k:
            max_dif = maximal[1] - maximal[0]
            def_max_dif = definitive_maximal[1] - definitive_maximal[0]
            if max_dif > def_max_dif:
                definitive_maximal = (maximal[0], maximal[1])
            elif max_dif == def_max_dif:
                definitive_maximal = min([definitive_maximal, maximal], key=lambda maxim: maxim[0])

    return k, definitive_maximal


# ==============================================================================
# Problema 2 - Sisi e a Sorveteria
# ==============================================================================

def problema_2(sabores: List[int]) -> int:
    """
    Sisi quer saber qual foi o período mais longo, em dias consecutivos, que
    ela passou sem repetir um único sabor de sorvete.

    Você deve desenvolver um algoritmo com tempo de execução $O(n)$ que receba
    a sequência de sabores consumidos e retorne o tamanho da maior
    subsequência contínua de valores distintos.
    """
    pass


# ==============================================================================
# Problema 3 - Hotel de Hilbert
# ==============================================================================

def problema_3(estadias: List[Tuple[int, int]]) -> Tuple[int, List[int]]:
    """
    O Grande Hotel de Hilbert receberá $n$ hóspedes. Para cada hóspede,
    conhecemos um par de inteiros $(a, b)$, que representam seu tempo de
    chegada e de partida, respectivamente. Para minimizar os custos, o
    gerente deseja utilizar o menor número possível de quartos. Duas pessoas
    podem ocupar o mesmo quarto, desde que o período de estadia delas não se
    sobreponha.

    O algoritmo deverá receber $n$ pares de inteiros $(a, b)$ e retornar
    $k, [r_1, r_2, \\dots, r_n]$, onde $k$ é a quantidade mínima de quartos
    necessários e $r_i$ é o quarto que o i-ésimo hóspede (na mesma ordem da
    entrada) deverá utilizar.

    O algoritmo deve ter tempo de execução $O(n \\log n)$.
    """
    pass


# ==============================================================================
# Problema 4 - Quadra
# ==============================================================================

def problema_4(A: List[int], k: int) -> Tuple[int, int, int, int]:
    """
    Dado um vetor $A$ com $n$ inteiros e um valor alvo $k$, encontre quatro
    índices distintos cuja soma dos elementos seja igual a $k$.

    O algoritmo deve retornar uma tupla com os quatro índices em ordem
    crescente, $(a, b, c, d)$ com $a<b<c<d$, que satisfaça a condição
    $A_a + A_b + A_c + A_d = k$.

    Caso existam múltiplas soluções, retornar qualquer uma delas é suficiente.
    Se nenhuma combinação válida for encontrada, o algoritmo deve retornar
    (-1, -1, -1, -1).

    O algoritmo deve ter uma complexidade de tempo de $O(n^2 \\log n)$.
    """
    pass


# ==============================================================================
# Problema 5 - Os blocos
# ==============================================================================

def problema_5(blocos: List[int]) -> int:
    """
    Você recebeu $n$ blocos de madeira e seu desafio é empilhá-los, formando
    o menor número possível de torres, seguindo duas regras:
    1. Um bloco só pode ser colocado sobre outro se o seu tamanho for menor ou
       igual ao do bloco inferior.
    2. Os blocos devem ser processados um a um, na sequência predefinida em
       que são apresentados.

    A cada bloco, você deve decidir se o coloca no topo de uma torre existente
    ou se inicia uma nova torre com ele. O algoritmo deve encontrar o número
    mínimo de torres necessárias com complexidade $O(n \\log n)$.
    """
    pass


# ==============================================================================
# Problema 6: O Grande Sistema Planetário
# ==============================================================================

def problema_6(A: List[int], k: int) -> int:
    """
    Dado um conjunto de períodos orbitais $A_1, A_2, \\dots, A_n$ e um número
    alvo de voltas $k$, encontre o menor número inteiro de anos, $T$, no qual
    a soma total de órbitas completadas por todos os $n$ planetas do sistema
    seja maior ou igual a $k$.

    A complexidade esperada é de $O(n \\cdot \\log(M))$, onde $M$ é a maior
    resposta possível.
    """
    pass


# ==============================================================================
# Problema 7: Otimização
# ==============================================================================

def problema_7(A: List[int]) -> int:
    """
    Dado um vetor $A$ com $n$ inteiros, projete um algoritmo linear que retorna
    o menor valor inteiro $k$ que minimiza a soma:
    $$ \\sum_{i=1}^{n} |A_i-k| $$
    A complexidade de tempo deve ser $O(n)$.
    """
    pass


if __name__ == '__main__':
    def validar(e1, e2):
        if e1==e2:
            print('\033[32mOK\033[m')
        else:
            print('\033[31mERROR\033[m')
