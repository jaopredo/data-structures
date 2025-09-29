def swap(lista: list, i: int, j: int):
    """Recebe uma lista e troca os valores nos índices i e j

    Args:
        lista (list): Lista alvo
        i (int): Índice i
        j (int): Índice j
    """
    temp = lista[i]
    lista[i] = lista[j]
    lista[j] = temp

def insertion_sort(lista: list) -> list:
    """Recebe uma lista e ordena ela utilizando o algoritmo Insertion Sort

    Args:
        lista (list): Lista a ser ordenada

    Returns:
        list: Lista ordenada
    """
    n = len(lista)  # Pego o tamanho da lista
    for i in range(1,n):  # Vou percorrer cada elemento da minha lista
        target = lista[i]  # O meu target é o valor atual que estarei olhando
        for j in range(i,-1,-1):  # Vou percorrer minha sublista em ordem decrescente
            lista[j] = lista[j-1]  # Vou mexendo todos para a direita
            # Se eu chego no último elemento ou meu elemento atual é menor que o meu target
            if lista[j] <= target or j == 0:
                lista[j] = target  # Então ele vai receber o target
                # Tem que lembrar que o lista[j] foi substituido pelo valor anterior lista[j-1]
                # então quer dizer que, se essa condição foi satisfeita, no passo anterior, o elemento
                # que estava na posição que estamos analisando era maior e agora o elemento da próxima
                # posição é menor, ou seja, achamos o intervalo que target deve estar na lista ordenada
                break
    
    return lista


def merge(A: list, B: list) -> list:
    """Recebo duas listas ordenadas e unifico elas em uma única lista ordenada

    Args:
        A (list): Lista Ordenada 1
        B (list): Lista Ordenada 2

    Returns:
        list: União ordenada das duas listas
    """
    i = 0
    j = 0

    ni = len(A)
    nj = len(B)

    C = []

    while i < ni or j < nj:
        if i >= ni:
            ai = float('inf')
        else:
            ai = A[i]

        if j >= nj:
            bj = float('inf')
        else:
            bj = B[j]

        if ai > bj:
            C.append(bj)
            j+=1
        elif ai <= bj:
            C.append(ai)
            i+=1
    
    return C


def merge_sort(lista: list) -> list:
    """Implementação do algoritmo Merge Sort

    Args:
        lista (list): Lista não-ordenada

    Returns:
        list: Lista ordenada
    """
    n = len(lista)
    if n > 1:
        midIdx = n//2
        lista1 = merge_sort(lista[0:midIdx])
        lista2 = merge_sort(lista[midIdx:n])
        return merge(lista1, lista2)
    else:
        return lista


def partition(lista: list, p: int, r: int) -> list:
    pivot = lista[r]
    j = p

    for i in range(p, r):
        if lista[i] <= pivot:
            swap(lista, i, j)
            j += 1
    
    swap(lista, j, r)

    return j


def quick_sort(lista: list, p: int, r: int):
    if p < r:
        j = partition(lista, p, r)

        quick_sort(lista, p, j-1)
        quick_sort(lista, j, r)
    
    return lista


def max_heapify(lista: list, n: int, i: int):
    maior = i

    idxEsquerdo = 2*i+1
    idxDireito = 2*i+2

    # Checo se o nó atual não é maior que o filho esquerdo
    if idxEsquerdo < n and lista[maior] <= lista[idxEsquerdo]:
        maior = idxEsquerdo

    if idxDireito < n and lista[maior] <= lista[idxDireito]:
        maior = idxDireito
    
    if maior != i:
        swap(lista, i, maior)
        max_heapify(lista, n, maior)


def build_max_heap(lista):
    n = len(lista)
    primeiro_no_com_folha = n//2 - 1

    for j in range(primeiro_no_com_folha,-1,-1):
        max_heapify(lista, n, j)


def build_min_heap(lista):
    def min_heapify(lista: list, n: int, i: int):
        menor = i

        idxEsquerdo = 2*i+1
        idxDireito = 2*i+2

        # Checo se o nó atual não é maior que o filho esquerdo
        if idxEsquerdo < n and lista[menor] >= lista[idxEsquerdo]:
            menor = idxEsquerdo

        if idxDireito < n and lista[menor] >= lista[idxDireito]:
            menor = idxDireito
        
        if menor != i:
            swap(lista, i, menor)
            min_heapify(lista, n, menor)
    
    n = len(lista)
    primeiro_no_com_folha = n//2 - 1

    for j in range(primeiro_no_com_folha,-1,-1):
        min_heapify(lista, n, j)


def heap_sort(lista: list):
    n = len(lista)

    build_max_heap(lista)

    for i in range(n-1,-1,-1):
        swap(lista, i, 0)
        max_heapify(lista, i, 0)


def counting_sort(lista: list):
    m = max(lista)

    nova = [None for _ in range(len(lista))]

    f = [0 for i in range(m+1)]
    for elemento in lista:
        f[elemento] += 1
    
    sf = [0 for _ in range(m+2)]
    for i in range(m+2):
        if i == 0:
            continue
        sf[i] = f[i-1] + sf[i-1]
    
    for e in lista:
        i = sf[e]
        nova[i] = e
        sf[e] += 1
    
    return nova


A = [5,2,4,5,1,3,1,1,5,0,4]
B = counting_sort(A)
print(B)
