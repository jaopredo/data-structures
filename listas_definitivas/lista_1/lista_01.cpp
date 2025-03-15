#include <iostream>
#include "patient_array.h"

using namespace PatientArrayTAD;
using namespace std;

int main() {
    PatientArray* pacientes = initializePatientArray();

    cout << pacientes->capacity << endl;
    cout << pacientes->size << endl;

    delete pacientes;

    return 0;
}
