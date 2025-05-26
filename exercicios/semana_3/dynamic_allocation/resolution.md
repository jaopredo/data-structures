## Semana 3: Exercícios sobre Alocação Dinâmica

## Questão 1
**Criando uma Struct Dinâmica**
- Crie uma struct chamada `Aluno` com os atributos `nome` e `nota`.
- Aloque dinamicamente um objeto dessa struct e preencha os valores.
- Exiba os valores e libere a memória corretamente.

```cpp
struct Aluno {
    const char * nome;
    float nota;
};

Aluno* criar_aluno(const char * nome, float nota) {
    Aluno* aluno = new Aluno;
    aluno->nome = nome;
    aluno->nota = nota;
    return aluno;
}

int main() {
    Aluno* aluno = criar_aluno("João Pedro", 8);
    cout << aluno->nome << endl;
    cout << aluno->nota << endl;
    delete aluno;
    return 0;
}
```

## Questão 2
**Manipulando Arrays Dinâmicos**
- Crie uma função que receba um número `n` e retorne um array dinâmico preenchido com os números de `1` a `n`.
- Libere a memória corretamente no `main`.

```cpp
int* criar_array(int tamanho) {
    int* dyn_arr = new int[tamanho];
    int* pointer_counter = dyn_arr;
    for (int i = 0; i < tamanho; i++) {
        *pointer_counter = i+1;
        pointer_counter += 1;
    }
    return dyn_arr;
}

int main() {
    int n = 10;  // Tamanho do array
    int* arr = criar_array(n);
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << endl;
    }
    delete[] arr;
    return 0;
}
```

## Questão 3
**Enum e Structs**
- Crie um enum chamado `Cargo` com valores `Estagiario`, `Junior`, `Pleno` e `Senior`.
- Defina uma struct `Funcionario` que contenha um nome e um cargo.
- Crie um vetor dinâmico para armazenar `n` funcionários e exiba os valores.

```cpp
enum Cargos {
    Estagiario,
    Junior,
    Pleno,
    Senior
};

struct Funcionario {
    const char * nome;
    Cargos cargo;
    Funcionario(const char * name, Cargos position) {
        nome = name;
        cargo = position;
    };
};

int main() {
    Funcionario* funcionarios = new Funcionario[3] {
        Funcionario("João Pedro", Pleno),
        Funcionario("Samuel", Pleno),
        Funcionario("Alex Júnio", Senior)
    };
    for (int i = 0; i < 3; i++) {
        cout << "==============================" << endl;
        cout << (funcionarios+i)->nome << endl;
        cout << (funcionarios+i)->cargo << endl;
    }
    cout << "==============================" << endl;
    delete[] funcionarios;
    return 0;
}
```