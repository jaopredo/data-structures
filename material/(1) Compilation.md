# Linguagem Compilada V.S Interpretada

A diferença entre elas são o modo que elas são executadas.

- **Compilada:** Convertida diretamente em linguagem de máquina
- **Interpretada:** Um programa chamado *interpretador* é responsável por interpretar linha a linha do programa para gerar um código que será compilado

## Fluxo de compilação do C++
Dividido em 4 etapas:
- **Pré-processamento**
- **Compilação**
- **Assembler**
- **Linkagem**

### Pré-processamento
Etapa responsável por resolver as diretivas de código, como `#define`, `#if` etc. Para ver o resultado do pré-processamento de um arquivo `.cpp` execute o seguinte código:
```bash
c++ -E <arquivo>.cpp > <arquivo>.i
```
O novo código gerado é conhecido como *Código Expandido*

### Compilação
Nesse passo, o compilador pega o código em C gerado pelo pré-processamento e o transforma em código assembly de acordo com a máquina. Para ver o resultado dessa etapa, execute:
```bash
c++ -S <arquivo>.i > <arquivo>.s
```

### Assembler
Nessa etapa, o código em Assembly é convertido em código de máquina (Binário) e colocado em um arquivo conhecido como Object. Para ver o resultado, execute:
```bash
c++ -c <arquivo>.s
```
O resultado é o arquivo com extensão `.o`

### Linker
Etapa em que o compilador transforma o arquivo binário em um executável, linkando com as referências externas, como bibliotecas, arquivos e caminhos. Para transformar o arquivo object em um executável, execute:
```bash
c++ <arquivo>.o -o app
```

Assim o programa retorna um executável chamado *app*
