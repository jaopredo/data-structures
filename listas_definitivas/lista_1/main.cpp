#include <iostream>
#include <cstring>
#include "PatientArray.h"

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

    Patient jean;
    strcpy(jean.name, "Jean");
    strcpy(jean.arrival_time, "22:10");
    jean.severity = 10;

    // Inserindo pacientes
    insertPatient(patient_arr, samuel);
    insertPatient(patient_arr, thalis);
    insertPatient(patient_arr, jota);
    insertPatient(patient_arr, jean);    
    // Como eu adicionei 4 pacientes, minha capacidade vai subir para 8, veja no print a seguir

    // Mostrando os pacientes
    printPatients(patient_arr);

    // Encontrando o próximo paciente
    int next_patient = findNextPatient(patient_arr);

    cout << endl << "O próximo paciente é o " << patient_arr->patients[next_patient].name << endl;

    // Removendo os próximos 2 pacientes
    cout << endl << "Deletando o próximo paciente..." << endl;

    popNextPatient(patient_arr);
    printPatients(patient_arr);

    cout << endl << "Deletando o próximo paciente..." << endl;
    popNextPatient(patient_arr);
    printPatients(patient_arr);

    // Removendo um paciente
    cout << endl << "Deletando o segundo paciente..." << endl;
    removePatient(patient_arr, 1);  // Removendo o Jotinha

    // Mostrando o novo array
    printPatients(patient_arr);

    // Deletando tudo para não haver memory leaks
    delete[] patient_arr->patients;
    delete patient_arr;

    return 0;
}
