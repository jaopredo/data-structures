#include "patient_array.h"
#include <iostream>

using namespace std;

namespace PatientArrayTAD {
    /**
     * @brief Função feita para inicializar um PatientArray vazio
     * 
     * @return PatientArray* Ponteiro para um PatientArray vazio
     */
    PatientArray* initializePatientArray() {
        PatientArray* initialized_array = new PatientArray;  // Aloco a memória para meu PatientArray
        initialized_array->patients = new Patient[4];  // Inicializo os pacientes como um array vazio
        initialized_array->capacity = 4;  // Digo que a capacidade máxima do meu array é 4
        initialized_array->size = 0;  // Informo que não há nenhum paciente
        return initialized_array;  // Retorno o array
    }


    /**
     * @brief Função que mostra, de uma maneira formatada, os pacientes dentro de um PatientArray
     * 
     * @param pa O PatientArray que eu quero vizualisar
     */
    void printPatients(PatientArray *pa) {
        int patients_amount = pa->size;  // Pegando a quantidade de pacientes presentes no array
                                        // Para colocar no FOR (apenas por organização mesmo)
        Patient* first_patient_pointer = pa->patients;

        cout << "Capacity: " << pa->capacity << endl;
        cout << "Current size: " << patients_amount << endl;
        cout << endl;

        cout << "Patients: " << endl;
        for (int i = 0; i < patients_amount; i++) {
            cout << "* " << (pa->patients+i)->arrival_time << " | " << (pa->patients+i)->severity << " | " << (pa->patients+i)->name << endl;
        }
    }


    void insertPatient(PatientArray *pa, Patient p) {
        if (pa->size+1 >= pa->capacity*3/4) {
        } else {
            cout << p.name << endl;
            pa->patients[pa->size] = p;
            pa->size += 1;  // Aumento a quantidade total de pessoas
        }
    }
}
