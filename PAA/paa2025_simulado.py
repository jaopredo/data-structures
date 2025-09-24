

def question_1():
    """
    Determine uma função f(n) para o código apresentado no enunciado tal que
    T(n)=θ(f(n)). Explique como a solução foi encontrada.

    ESPACO DO ALUNO:
    <Descrever aqui informações adicionais>
    """
    pass
    

def question_2(v: list[int], k: int, x: int) -> list[int]:
    """
    Retorna os k elementos mais próximos do valor em v[x], excluindo o próprio v[x].

    Regras:
    - Se k <= 0, retorna [].
    - Se k > n-1, limita para n-1 (não há como escolher mais do que todos os outros).
    - Empate de distância: prefere o elemento à esquerda (índice menor).

    ESPACO DO ALUNO:
    <Descrever aqui informações adicionais>
    """
    n = len(v)

    if k <= 0:
        return []
    if k > n-1:
        k = n-1

    proximos = []

    l = 0
    i = x+1
    j = x-1

    while l != k:
        dist_direita = float('inf')
        dist_esquerda = float('inf')

        if i < n:
            dist_direita = abs(v[x]-v[i])
        if j >= 0:
            dist_esquerda = abs(v[x]-v[j])
        
        if dist_esquerda <= dist_direita:
            proximos.append(v[j])
            j -= 1
        else:
            proximos.append(v[i])
            i += 1
        
        l += 1

    return proximos
    

def question_3(x: int, y: int, fuel_stations: list[int]) -> list[int] | None:
    """
    Determina em quais pontos reabastecer para percorrer X metros com alcance Y por tanque.
    `fuel_stations` é uma lista ordenada com as distâncias dos postos a partir da entrada (0).

    Retorna:
      - lista com as distâncias dos pontos onde deve reabastecer (na ordem),
      - ou None se for impossível completar.

    ESPACO DO ALUNO:
    <Descrever aqui informações adicionais>
    """
    pass


def question_4(v) -> list[int]:
    """
    Encontre o número mais frequente em v.
    Restrição: cada v[i] ∈ {n^2, n^2 + 1, …, n^2 + n}, onde n = len(v).
	Em caso de empate, retorne qualquer um dos valores empatados.
	Retorne None se v estiver vazio.

    ESPACO DO ALUNO:
    <Descrever aqui informações adicionais>
    """
    numeros = {}
    max_num = 0
    respective_num = None

    for num in v:
        if numeros.get(num):
            atual = numeros.get(num) + 1
            
            if atual >= max_num:
                max_num = atual
                respective_num = num
            
            numeros[num] += 1
        else:
            numeros[num] = 1
    
    return respective_num


if __name__ == '__main__':
    from random import sample

    lista = sorted(sample(range(0, 50), 5))

    print(lista)
    question_2(lista, 3, 2)
