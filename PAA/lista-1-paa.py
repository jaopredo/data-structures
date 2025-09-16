from typing import List, Optional

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


# Estrutura de nó para o exercício de árvore
class TreeNode:
    """
    Classe para representar um nó de uma árvore binária.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def insert(self, value: int):
        if value <= self.val:
            if self.left:
                self.left.insert(value)
            else:
                self.left = TreeNode(value)
        elif value >= self.val:
            if self.right:
                self.right.insert(value)
            else:
                self.right = TreeNode(value)

# ==============================================================================
# Problema 6
# ==============================================================================
def problema_6(raiz: Optional[TreeNode]) -> int:
    """
    Dada uma árvore binária de busca (BST) T com $n$ nós contendo inteiros, projete
    um algoritmo que encontre a menor diferença absoluta entre dois nós diferentes 
    da árvore. O algoritmo deve ter complexidade $O(n)$ no pior caso.
    """
    # Inicio minha menor distância como infinito
    menor_distancia = float("inf")

    # Faço o inorder trasversal
    def comparar_in_order(raiz: TreeNode, anterior: int):
        nonlocal menor_distancia
        # Se eu tenho uma subárvore na esquerda
        if raiz.left:
            # Começo a percorrer a subarvore da esquerda
            comparar_in_order(raiz.left, raiz.val)
        
        # Faço a diferença do nó atual com o anterior
        dif = abs(raiz.val - anterior)

        # Se a distância menor encontrada for maior que a atual
        if menor_distancia >= dif:
            # Atulizo a menor distância
            menor_distancia = dif
        
        # Se eu tenho uma subárvore na direita
        if raiz.right:
            # Também vou percorrer essa subárvore
            comparar_in_order(raiz.right, raiz.val)

    comparar_in_order(raiz, menor_distancia)

    return menor_distancia


# ==============================================================================
# Problema 7
# ==============================================================================

def problema_7(A: List[int]) -> List[int]:
    """
    Desenvolva um algoritmo $O(n)$ que particiona um array $A$ em números pares e ímpares. 
    O algoritmo deve terminar com A contendo todos os seus elementos pares precedendo todos 
    os seus elementos ímpares. A solução deve ser um algoritmo in-place, o que significa que 
    ele pode usar apenas um espaço de memória constante além do próprio $A$. Na prática, 
    isso significa que você não pode usar outro array auxiliar.
    """
    i = 0
    j = -1
    array_size = len(A)

    def swap(A, i, j):
        Ai = A[i]
        A[i] = A[j]
        A[j] = Ai

    for _ in range(array_size):
        if A[i] % 2 == 1 and A[j] % 2 == 0:
            swap(A, i, j)
        
        if A[i+1] == A[j]:
            break
        
        if A[i] % 2 == 0:
            i += 1
        if A[j] % 2 == 1:
            j -= 1

    return A

# ==============================================================================
# Problema 8
# ==============================================================================

def problema_8_a(A: List[int], k: int) -> int:
    """
    Dado um inteiro k e uma lista A que contém n inteiros, projete um algoritmo 
    que retorne a quantidade de pares de inteiros em A cuja soma seja k. 
    Mais especificamente, retorne a quantidade de pares $(i, j)$ com $i<j$, 
    tal que $A_i + A_j = k$

    Projete o algoritmo com complexidade de execução $O(n)$
    """
    auxiliar = {}  # Hash auxiliar para armazenar os valores que foram analisados
    qtd = 0  # O valor que será retornado

    for element in A:  # Para cada elemento em A
        procurar = k - element  # Vejo que elemento deve estar na lista
                                # Para somar na quantidade que será retornada
        
        # Se o elemento que eu tenho que procurar estiver no dicionário
        if procurar in auxiliar:
            # Então eu somo a quantidade de vezes que
            # ele foi observado com a quantidade de
            # combinações possiveis
            qtd += auxiliar[procurar]
        
        # Se o elemento atual for uma chave no dicionário
        if element in auxiliar:
            # Eu somo mais 1 na quantidade de elementos
            # observado
            auxiliar[element] += 1
        else:  # Se não
            # Eu crio a chave com esse elemento
            auxiliar[element] = 1
    
    return qtd

def problema_8_b(A: List[int], k: int) -> int:
    """
    [...]
    Agora assuma que A esteja ordenado, projete 
    o algoritmo com complexidade de execução $O(n log n)$ e complexidade de 
    espaço $O(1)$
    """
    pass

def problema_8_c(A: List[int], k: int, debug=False) -> int:
    """
    [...]
    Novamente assumindo que A está ordenado, projeto o algoritmo com complexidade 
    de execução $O(n)$ e complexidade de espaço $O(1)$
    """
    i = 0  # Índice de análise direito
    j = len(A)-1  # Índice e análise esquerdo
    qtd = 0  # Quantidade de combinações da soma de k

    # Variáveis de controle para evitar contagens repetidas
    changed_i = False
    changed_j = False
    # Quantas vezes eu analisei um valor repetido
    repeated_i = 1
    repeated_j = 1
    while i < j:
        if A[i] + A[j] < k:
            changed_i = True
            changed_j = False
            i += 1
        elif A[i] + A[j] > k:
            changed_i = False
            changed_j = True
            j -= 1
        else:
            if A[i] != A[j]:
                # Analisando se o elemento anterior é igual ao atual:
                if i > 0 and A[i-1] == A[i] and changed_i:
                    repeated_i += 1
                if j < len(A)-1 and A[j+1] == A[j] and changed_j:
                    repeated_j += 1
        
                if A[i+1]==A[i]:
                    changed_i = True
                    changed_j = False
                    i+=1
                elif A[j-1]==A[j]:
                    changed_j = True
                    changed_i = False
                    j-=1
                else:
                    qtd += repeated_i * repeated_j

                    repeated_j = 1
                    repeated_i = 1

                    changed_i = True
                    changed_j = False
                    i += 1
            else:
                qtd += (j-i+1)*(j-i)//2
                break
    
    return qtd
