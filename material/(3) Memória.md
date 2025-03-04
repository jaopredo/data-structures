# Memória
## Endereços de Memória
Toda variável é um espaço na memória do computador que armazena um dado. Podemos obter qual espaço da memória aquela variável está atribuida da seguinte forma:
```cpp
int x = 10;
cout << &x << endl;
```
`&x` é o endereço de memória de `x`

Ao declarar uma variável, o compilador atribui um espaço na memória para ela, logo, se não a inicializarmos com algum valor, ela irá pegar o chamado "lixo", pegando um valor qualquer que possa estar naquele espaço de memória

## Referências
Uma referência é um alias para uma variável (Apelido).
```cpp
int x = 10;
int& ref = x;

ref = 20;
cout << x << endl;  // Saída é 20
```
As referências não ocupam um novo espaço na memória do computador, elas são apenas um novo rótulo para a variável antes estabelecida

## Ponteiros
Ponteiros são variáveis que armazenam endereços de memória
```cpp
int x = 10;
int* p = &x;
```
`p` recebe um endereço de memória de um **inteiro**. Para acessar o valor armazenado no espaço guardado pelo ponteiro utilizamos o operador de desreferência `*`
```cpp
cout << *p << endl;  // Mostra 10
```

Para evitar lixos de memória armazenados em ponteiros não inicializados, podemos utilizar o nullptr.
```cpp
int * p1;  // Pode fazer, mas não é recomendado
//--------------------------------
int * p2 = nullptr;  // Recomendado
```
