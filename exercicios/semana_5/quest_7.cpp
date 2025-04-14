#include <iostream>
#include <random>

using namespace std;


int generate_random(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}


struct DoubleEndedQueue {
    int head;
    int tail;
    int* data;
    int size;
    int maxSize;
};

DoubleEndedQueue* initialize_double_ended_queue(int maxSize) {
    DoubleEndedQueue* q = new DoubleEndedQueue();
    q->maxSize = maxSize;

    if (q->maxSize % 2 == 0) {
        q->head = q->maxSize / 2 + 1;
        q->tail = q->maxSize / 2;
    } else {
        q->head = (q->maxSize+1) / 2 + 1;
        q->tail = (q->maxSize+1) / 2;
    }

    q->data = new int[maxSize];
    q->size = 0;

    return q;
}

int start_enqueue_double_ended_queue(DoubleEndedQueue* q, int value) {
    if (q->size == q->maxSize || (q->tail == q->head-1 && q->size != 0)) {
        return 0;
    }
    
    q->head -= 1;

    if (q->head <= -1) {
        q->head = q->maxSize-1;
    }

    q->data[q->head] = value;
    q->size += 1;

    return 1;
}

int end_enqueue_double_ended_queue(DoubleEndedQueue* q, int value) {
    if (q->size == q->maxSize || (q->tail == q->head-1 && q->size != 0)) {
        return 0;
    }

    q->tail = (q->tail + 1) % q->maxSize;  // Limiting the head to be inside the maxSize range
    q->data[q->tail] = value;
    q->size += 1;

    return 1;
}


int end_dequeue_double_ended_queue(DoubleEndedQueue* q) {
    if (q->size == 0 || (q->tail == q->head-1 && q->size != q->maxSize)) {
        return 0;
    }

    q->data[q->tail] = 0;

    q->tail -= 1;  // Limiting the head to be inside the maxSize range
    if (q->tail <= -1) {
        q->tail = q->tail-1;
    }
    q->size -= 1;

    return 1;
}

int start_dequeue_double_ended_queue(DoubleEndedQueue* q) {
    if (q->size == 0 || (q->tail == q->head-1 && q->size != q->maxSize)) {
        return 0;
    }

    q->data[q->head] = 0;
    q->head = (q->head + 1) % q->maxSize;  // Limiting the head to be inside the maxSize range
    q->size -= 1;

    return 1;
}


int destroy_double_ended_queue(DoubleEndedQueue* q) {
    delete[] q->data;
    delete q;
    
    return 1;
}

int main() {
    DoubleEndedQueue* deque = initialize_double_ended_queue(10);

    cout << deque->head << endl;
    cout << deque->tail << endl;
    cout << "============" << endl;

    for (int i = 0; i<10; i++) {
        int in_start = generate_random(0, 1);
        int randn = generate_random(1, 10);

        if (in_start) {
            cout << "Inseri no começo:" << endl;
            start_enqueue_double_ended_queue(deque, randn);
        } else {
            cout << "Inseri no final:" << endl;
            end_enqueue_double_ended_queue(deque, randn);
        }

        cout << deque->head << endl;
        cout << deque->tail << endl;
        cout << "============" << endl;
    }

    cout << "Valores finais: " << endl;
    cout << deque->data[deque->head] << endl;
    cout << deque->data[deque->tail] << endl;

    cout << "============" << endl;
    cout << "Removendo valores:" << endl;

    for (int i = 0; i<10; i++) {
        int in_start = generate_random(0, 1);

        if (in_start) {
            cout << "Removi no começo:" << endl;
            start_dequeue_double_ended_queue(deque);
        } else {
            cout << "Removi no final:" << endl;
            end_dequeue_double_ended_queue(deque);
        }

        cout << deque->head << endl;
        cout << deque->tail << endl;
        cout << "============" << endl;
    }

    destroy_double_ended_queue(deque);
}
