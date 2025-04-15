#include "../../modules/tad.h"
#include <iostream>
#include <limits>

using namespace std;
using namespace TAD;

int getMinValue(Queue* q, int* min_value_pointer) {
    if (q->size == 0) {
        return 0;
    }

    Queue* temp_queue = initialization_queue(q->maxSize);

    int initial_size = q->size;
    int temp_holder = 0;
    int min_value = q->data[0];
    
    for (int i = 0; i < initial_size; i++) {
        dequeue_queue(q, &temp_holder);
        enqueue_queue(temp_queue, temp_holder);

        if (temp_holder < min_value) {
            min_value = temp_holder;
        }
    }

    *min_value_pointer = min_value;

    for (int i = 0; i < initial_size; i++) {
        dequeue_queue(temp_queue, &temp_holder);
        enqueue_queue(q, temp_holder);
    }

    destroy_queue(temp_queue);

    return 1;
}

void show_queue(Queue* q) {
    cout << "====== ELEMENTOS DA FILA ======" << endl;
    for (int i = 0; i < q->size; i++) {
        cout << q->data[i] << endl;
    }
}

int main() {
    Queue* q = initialization_queue(10);

    enqueue_queue(q, 3);
    enqueue_queue(q, 10);
    enqueue_queue(q, 2);
    enqueue_queue(q, 9);
    enqueue_queue(q, 5);

    show_queue(q);

    int min_value = 0;
    getMinValue(q, &min_value);

    cout << "====== MENOR VALOR ======" << endl;
    cout << min_value << endl;
    
    destroy_queue(q);

    return 1;
}
