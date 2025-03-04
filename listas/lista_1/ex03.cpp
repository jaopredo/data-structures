#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int target_num = 0;
    bool prime = true;
    cout << "Descubra se o número é primo, digite o número desejado" << endl;

    cin >> target_num;

    for (int i = 0; i <= sqrt(target_num); i++) {
        if (target_num % i == 0) {
            prime = false;
            // break;
        }
    }

    if (prime) {
        cout << "O número passado não é primo!" << endl;
    } else {
        cout << "O número passado é primo!" << endl;
    }

    return 0;
}
