#ifndef PATIENT_ARRAY_H
#define PATIENT_ARRAY_H

namespace PatientArrayTAD {

    struct Patient {
        char name[50];
        int severity;         // Número positivo. Quanto maior, mais severo.
        char arrival_time[6]; // Formato "XXhYY"
    };

    struct PatientArray {
        Patient *patients; // Ponteiro para o array de pacientes
        int size;          // Número atual de pacientes armazenados
        int capacity;      // Capacidade total do array
    };

    PatientArray* initializePatientArray();
    void printPatients(PatientArray *pa);
    void insertPatient(PatientArray *pa, Patient p);
    int findNextPatient(PatientArray *pa);
    void removePatient(PatientArray *pa, int index);
    Patient popNextPatient(PatientArray *pa);
}

#endif