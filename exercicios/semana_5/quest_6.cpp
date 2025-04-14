#include "../../modules/tad.h"
#include <iostream>

using namespace std;
using namespace TAD;

/**
 * @brief This functions receives a circular queue and search for the passed value in the queue, and
 * returns into the pointer passed the index that the value was found
 * 
 * @param q Circular Queue
 * @param value Desired value
 * @param index Variable that the index will be stored
 * @return int 1 if the program finds the value, 0 if it doesn't
 */
int search_circular_queue(CircularQueue* q, int value, int* index) {
    if (q->size == 0) {  // Empty queue
        return 0;
    }

    for (int i = 0; i < q->size; i++) {
        if (q->data[i] == value) {
            *index = i;
            return 1;
        }
    }

    return 0;
}


int main() {
    int max_size = 5;
    CircularQueue* circular_queue = initialization_circular_queue(max_size);

    enqueue_circular_queue(circular_queue, 8);
    enqueue_circular_queue(circular_queue, 2);
    enqueue_circular_queue(circular_queue, 7);
    enqueue_circular_queue(circular_queue, 0);
    enqueue_circular_queue(circular_queue, 3);

    int index = -1;

    search_circular_queue(circular_queue, 4, &index);  // Searching for "4" in the queue

    cout << index << endl;

    search_circular_queue(circular_queue, 0, &index);  // Searching for "0" in the queue

    cout << index << endl;

    destroy_circular_queue(circular_queue);
}
