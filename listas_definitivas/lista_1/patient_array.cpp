#include "patient_array.h"
#include <iostream>

namespace PatientArrayTAD {
    PatientArray* initializePatientArray() {
        PatientArray* initialized_array = new PatientArray;
        initialized_array->capacity = 4;
        initialized_array->size = 0;
        return initialized_array;
    }
}
