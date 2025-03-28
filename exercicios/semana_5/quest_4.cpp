#include "../../modules/tad.h"
#include <iostream>

using namespace TAD;
using namespace std;

int main() {
    int queue_size = 4;
    Queue* q1 = initialization_queue(queue_size);
    enqueue_queue(q1, 1);
    enqueue_queue(q1, 2);
    enqueue_queue(q1, 3);
    enqueue_queue(q1, 4);
    
    Queue* q2 = initialization_queue(queue_size);  // Fila q1 invertida

    int value;

    Stack* s = initialization_stack(queue_size);

    // Adicionando item por item na pilha
    for (int i = queue_size-1; i >= 0; i--) {
        dequeue_queue(q1, &value);
        push_stack(s, value);
    }

    for (int i = queue_size-1; i >= 0; i--) {
        pop_stack(s, &value);
        enqueue_queue(q2, value);
    }
    
    cout << "Fila Invertida:" << endl;
    for (int i = 0; i<queue_size; i++) {
        cout << q2->data[i] << endl;
    }
}
