#include "patient_array.h"
#include <iostream>

using namespace std;

namespace PatientArrayTAD {
    PatientArray* initializePatientArray() {
        PatientArray* initialized_array = new PatientArray;
        initialized_array->patients = new Patient[4];
        initialized_array->capacity = 4;
        initialized_array->size = 0;
        return initialized_array;
    }

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
}
