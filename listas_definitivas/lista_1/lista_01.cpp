#include <iostream>
#include <cstring>
#include "patient_array.h"

using namespace PatientArrayTAD;
using namespace std;

int main() {
    PatientArray* patient_arr = initializePatientArray();

    strcpy(patient_arr->patients->name, "Jotinha");
    patient_arr->size += 1;
    strcpy(patient_arr->patients->arrival_time, "18:30");
    patient_arr->patients->severity = 10;
    
    Patient* next_patient = patient_arr->patients + 1;
    strcpy(next_patient->name, "Samuel");
    patient_arr->size += 1;
    strcpy(next_patient->arrival_time, "20:30");
    next_patient->severity = 5;

    printPatients(patient_arr);

    delete patient_arr;

    return 0;
}
