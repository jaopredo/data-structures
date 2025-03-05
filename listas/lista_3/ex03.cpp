#include <iostream>

using namespace std;

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
