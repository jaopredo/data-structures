#include <iostream>
#include <string>

using namespace std;


int main() {
    int num = 0;
    cin >> num;
    if (num < 0) {
        cout << "Número digitado é negativo" << endl;
    } else if (num > 0) {
        cout << "Número digitado é positivo" << endl;
    } else {
        cout << "Número digitado é igual a 0" << endl;
    }
}
