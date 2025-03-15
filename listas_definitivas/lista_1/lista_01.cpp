#include <iostream>
#include <cstring>
#include "patient_array.h"

using namespace PatientArrayTAD;
using namespace std;

int main() {
    // Inicializando meu array vazio
    PatientArray* patient_arr = initializePatientArray();

    // Criando dois pacientes
    Patient jota;
    strcpy(jota.name, "Jotinha");
    strcpy(jota.arrival_time, "18:30");
    jota.severity = 10;

    Patient samuel;
    strcpy(samuel.name, "Samuel");
    strcpy(samuel.arrival_time, "20:12");
    samuel.severity = 3;

    insertPatient(patient_arr, jota);
    insertPatient(patient_arr, samuel);

    printPatients(patient_arr);

    delete patient_arr;

    return 0;
}
