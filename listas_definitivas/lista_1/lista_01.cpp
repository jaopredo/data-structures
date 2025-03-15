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
    jota.severity = 1;

    Patient samuel;
    strcpy(samuel.name, "Samuel");
    strcpy(samuel.arrival_time, "20:12");
    samuel.severity = 3;

    Patient thalis;
    strcpy(thalis.name, "Thalis");
    strcpy(thalis.arrival_time, "21:24");
    thalis.severity = 3;

    // Inserindo pacientes
    insertPatient(patient_arr, samuel);
    insertPatient(patient_arr, thalis);
    insertPatient(patient_arr, jota);

    // Mostrando os pacientes
    printPatients(patient_arr);

    // Encontrando o próximo paciente
    int next_patient = findNextPatient(patient_arr);

    cout << "O próximo paciente é o " << patient_arr->patients[next_patient].name << endl;

    // Removendo um paciente
    removePatient(patient_arr, 1);  // Removendo o Thalis

    // Mostrando o novo array
    printPatients(patient_arr);

    // Deletando tudo para não haver memory leaks
    delete[] patient_arr->patients;
    delete patient_arr;

    return 0;
}
