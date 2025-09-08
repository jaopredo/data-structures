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
    
    def print_tree(self, level=0, prefix="Raiz: "):
        print(" " * (4 * level) + prefix + str(self.val))
        if self.left:
            self.left.print_tree(level + 1, "L--- ")
        if self.right:
            self.right.print_tree(level + 1, "R--- ")

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

    def comparar_valores(raiz: TreeNode):
        nonlocal menor_distancia
        if raiz:
            # Pego os nós de direita e esquerda
            direita = raiz.right
            esquerda = raiz.left

            # Se o nó da direita existe
            if direita:
                # Vou pegar ele e percorrer todos os seus nós esquerdos, já que, se
                # eu pegar algum nó direito eu vou estar aumentando a distância entre
                # meu nó atual (raíz) e o nó que eu estou percorrendo

                # Checo a diferença entre meu nó raíz e o seu nó da direita
                diferenca = abs(raiz.val - direita.val)
                menor_distancia = min(diferenca, menor_distancia)

                # Agora vou percorrer todos os nós na esquerda do nó direito
                atual = direita.left
                while atual and atual.left:
                    diferenca = abs(raiz.val - atual.val)
                    menor_distancia = min(menor_distancia, diferenca)
                    atual = atual.left
            # Se o nó da esquerda existe
            if esquerda:
                # Vou repitir o mesmo processo, trocando apenas left por right,
                # já que a mesma lógica vai valer

                # Checo a diferença entre meu nó raíz e meu nó da esquerda
                diferenca = abs(raiz.val - esquerda.val)
                menor_distancia = min(diferenca, menor_distancia)

                # Vou percorrer todos os nós na direita do meu nó esquerdo
                atual = esquerda.right
                while atual and atual.right:
                    diferenca = abs(raiz.val - atual.val)
                    menor_distancia = min(menor_distancia, diferenca)
                    atual = atual.right
            
            # Faço isso recursivamente para todos os nós na árvore
            comparar_valores(direita)
            comparar_valores(esquerda)

    comparar_valores(raiz)

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
    pass

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
    pass

def problema_8_b(A: List[int], k: int) -> int:
    """
    [...]
    Agora assuma que A esteja ordenado, projete 
    o algoritmo com complexidade de execução $O(n log n)$ e complexidade de 
    espaço $O(1)$
    """
    pass

def problema_8_c(A: List[int], k: int) -> int:
    """
    [...]
    Novamente assumindo que A está ordenado, projeto o algoritmo com complexidade 
    de execução $O(n)$ e complexidade de espaço $O(1)$
    """
    pass


if __name__ == "__main__":
    values_to_insert = [ 5, 10, 1, 6, 14, 4, 7, 13, 2 ]
    root = TreeNode(8)

    for val in values_to_insert:
        root.insert(val)
    
    root.print_tree()

    print(problema_6(root))
