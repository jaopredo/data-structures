#include "patient_array.h"
#include <iostream>
#include <cstring>

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

        cout << endl;
        cout << "Capacity: " << pa->capacity << endl;
        cout << "Current size: " << patients_amount << endl;
        cout << endl;

        cout << "Patients: " << endl;
        for (int i = 0; i < patients_amount; i++) {
            cout << "* " << (pa->patients+i)->arrival_time << " | " << (pa->patients+i)->severity << " | " << (pa->patients+i)->name << endl;
        }
    }

    /**
     * @brief Função para inserir um paciente no Array e aumentar sua capacidade dependendo da situação
     * 
     * @param pa Array de pacientes
     * @param p Paciente a ser adicionado
     */
    void insertPatient(PatientArray *pa, Patient p) {
        pa->patients[pa->size] = p;  // Inserindo o novo paciente na última posição
        pa->size += 1;  // Aumento a quantidade total de pessoas

        if (pa->size+1 >= pa->capacity*3/4) {
            pa->capacity *= 2;  // Dobrando a capacidade máxima do array
            Patient* new_patient_array = new Patient[pa->capacity];  // Criando um novo array com a capacidade dobrada

            for (int i = 0; i < pa->size; i++) {
                /*
                Percorrendo o array para adicionar os pacientes antigos
                */
                new_patient_array[i] = pa->patients[i];
            }

            delete[] pa->patients;

            pa->patients = new_patient_array;
        }
    }

    /**
     * @brief Compara se o paciente 1 é mais urgente que o paciente 2
     * 
     * @param p1 Paciente 1
     * @param p2 Paciente 2
     * @return (int) 1 se p1 for mais urgente, 0 se p1 e p2 tem o mesmo nível, -1 se p2 for mais urgente
     */
    int comparePatients(Patient p1, Patient p2) {
        if (p1.severity > p2.severity) {
            return 1;
        } else if (p2.severity > p1.severity) {
            return -1;
        } else {  // Desempatando pelo horário de chegada
            return strcmp(p1.arrival_time, p2.arrival_time)*(-1);
        }
    }

    /**
     * @brief Retorna o índice do próximo paciente a ser atendido
     * 
     * @param pa O array de pacientes
     * @return (int) Retorna o índice do paciente mais urgente
     */
    int findNextPatient(PatientArray *pa) {
        int next_patient = 0;  // Defino que o primeiro paciente é o próximo
        for (int i = 1; i < pa->size; i++) {  // Faço um loop passando por cada paciente
            if (comparePatients(pa->patients[next_patient], pa->patients[i]) == -1) {
                next_patient = i;
            }
        }
        return next_patient;
    };

    /**
     * @brief Função para remover paciente do PatientArray
     * 
     * @param pa PatientArray que será manipulado
     * @param index Index do paciente que será removido
     */
    void removePatient(PatientArray *pa, int index) {
        Patient* new_pacients_arr = new Patient[pa->capacity];  // Crio o novo array de pacientes

        for (int i = 0; i < pa->size-1; i++) {  // Faço um for indo de 0 até n-2 (n = quantidade de pacientes)
            if (i >= index) {  // Se i for maior que o index passado
                new_pacients_arr[i] = pa->patients[i+1];  // Começo a assinalar o próximo item do array
            } else {  // Caso contrário
                new_pacients_arr[i] = pa->patients[i];  // Eu continuo assinalando os mesmos índices
            }
        }

        delete[] pa->patients;  // Libero a memória do array antigo
        pa->size -= 1;  // Diminuo a quantidade de pacientes presente
        pa->patients = new_pacients_arr;  // Digo que os novos pacientes são a nova variável
    };
}
