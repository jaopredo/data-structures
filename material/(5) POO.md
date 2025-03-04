# Orientação a Objetos
No C++, diferentemente do C, é possível utilizar da orientação a objetos. (Esse documento não é focado em explicar os conceitos da Orientação a Objetos)

## Classes
Criando uma classe:
```cpp
class Animal {
    public:
        char species;
        int age;
}
```

Instanciando a classe:
```cpp
int main() {
    Animal cachorro;
    
    cachorro.species = "Cachorro"
    cachorro.age = 12

    return 0;
}
```

No exemplo eu criei apenas o animal cachorro, mas é possível criar quantas instâncias quiser com uma classe

## Structs
Structs são estruturas muito parecidas com as Classes, porém, a principal diferença entre eles é o padrão de visibilidade dos atributos e métodos. Nas classes, eles são privados por padrão, enquanto no struct eles são públicos por padrão:
```cpp
struct Pessoa {
    char name;
    void apresentar() {
        cout << name << endl;
    }
}

class Animal {
    char name;
    void apresentar() {
        cout << name << endl;
    }
}

int main() {
    Pessoa p1;
    // Não dá erros!
    p1.name = "João";
    p1.apresentar();

    Animal a1;
    // Erro, pois "name" é privado
    a1.name = "Rex"

    return 0;
}
```

## Disclaimer
Os tópicos a seguir mostram exemplos com `class`, mas valem para `struct` também

## Criando Métodos
Para criar métodos, fazemos o seguinte:

```cpp
class Pessoa {
    public:
        char name;
        void apresentar() {
            cout << name << endl;
        }
}
```

Declaramos como uma função qualquer, mas dentro do escopo da classe Pessoa. Podemos definir o método fora da classe também:

```cpp
void Pessoa::acenar() {
    cout << "Acenando!" << endl;
}
```

Você também pode passar parâmetros sem problema nenhum!

```cpp
class Pessoa {
    public:
        char name;
        void apresentar_para_alguem(char name2) {
            cout << "Prazer, " << name2 << ", eu sou " << name << endl;
        }
}
```

## Constructors
Método especial chamado quando um objeto é instanciado

```cpp
class Pessoa {
    public:
        Pessoa() {
            cout << "Tá instanciando!" << endl;
        }
}

int main() {
    Pessoa alberto;  // Vai mostrar "Tá instanciando!" no terminal

    return 0;
}
```

Podemos usar isso para passar parâmetros nesse construtor e declarar todas as variáveis necessárias para a classe em uma única linha

```cpp
class Pessoa {
    public:
        char name;
        int age;
        Pessoa(char n, int a) {
            name = n;
            age = a;
        }
}

int main() {
    Pessoa alberto("Alberto", 35);

    cout << alberto.name << endl;  // Mostra "Alberto"
    cout << alberto.age << endl;  // Mostra "35"

    return 0;
}
```

Também podem ser declarados fora da classe

```cpp
Pessoa::Pessoa(char n, int a) {
    ...
}
```

## Modificadores de Acesso
Já foi mostrado antes como fazer isso, os modificadores são:
- `public`: Acesso livre para todos
- `protected`: Apenas a classe pai e as classes filhas podem ter acesso
- `private`: Apenas aquela classe tem acesso

## Herança
Para fazer com que uma classe herde de outras classe, usamos `:`, e caso queiramos que ela herde de mais que uma única classe, utilizamos `,`:

```cpp
class Parent1 {}

class Parent2 {}

class Child1 : public Parent1 {}

class Child2 : public Parent1, protected Parent2 {}
```

O modificador de acesso na herança é importante:
- `public`: Mantém o acesso original dos membros da classe herdada;
- `protected`: Os membros de acesso `public` na classe pai viram de acesso `protected` na classe filha;
- `private`: Os membros de acesso `public` e `protected` da classe pai viram de acesso `private` na classe filha;

## Enums
Enums são usados para representar um conjunto de valores nomeados, tornando o código mais legível.

```cpp
enum DiaDaSemana {
    Domingo,
    Segunda,
    Terca,
    Quarta,
    Quinta,
    Sexta,
    Sabado
};

int main() {
    DiaDaSemana hoje = Segunda;
    if (hoje == Segunda) {
        cout << "Hoje é segunda-feira!" << endl;
    }
    return 0;
}
```

Também é possível alterar os valores associados a cada `nome`:

```cpp
enum Level {
    LOW    = 25,
    MEDIUM = 50,
    HIGH   = 75
}; 
  
int main() {
    int lv = 15;
    if (lv <= LOW) {
        std::cout << "Beginner level" << std::endl;
    } else if (LOW < lv && lv <= MEDIUM) {
        std::cout << "Low level" << std::endl;
    } else if (MEDIUM < lv && lv <= HIGH) {
        std::cout << "Medium level" << std::endl;
    } else if (HIGH < lv) {
        std::cout << "High level" << std::endl;
    }
    return 0;
}
```
