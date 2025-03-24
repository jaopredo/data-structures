#include <iostream>
#include "conversao.h"

using namespace std;

int main() {
    int graus_celsius = 100;
    int graus_farenheit = 80;

    cout << CONVERSAO_H::celsius_to_farenheit(graus_celsius) << endl;
    cout << CONVERSAO_H::farenheit_to_celsius(graus_farenheit) << endl;

    return 0;
}
