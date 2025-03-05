#include <iostream>

using namespace std;

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
