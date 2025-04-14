#include "tad.h"

namespace TAD {
    Stack* initialization_stack(int maxSize) {
        Stack * s = new Stack();
        s->data = new int[maxSize];
        s->maxSize = maxSize;
        s->top = -1;
        return s;
    }

    void destroy_stack(Stack* s) {
        delete[] s->data;
        delete s;
    }

    int push_stack(Stack *s, int value) {
        if (s->top == s->maxSize - 1) {
            return 0; // Full stack
        }
        s->top += 1;
        s->data[s->top] = value;
        return 1;
    }

    int pop_stack(Stack *s, int *value) {
        if (s->top == -1) {
            return 0; // Empty stack
        }
        s->top -= 1;
        *value = s->data[s->top + 1];
        return 1;
    }

    int peek_stack(const Stack *s, int *value) {
        if (s->top == -1) {
            return 0; // Empty stack
        }
        *value = s->data[s->top];
        return 1;
    }

    // ========================================================================================
    Queue * initialization_queue(int maxSize) {
        Queue * q = new Queue();
        q->data = new int[maxSize];
        q->maxSize = maxSize;
        q->size = 0;
        return q;
    }

    void destroy_queue(Queue* q) {
        delete[] q->data;
        delete q;
    }

    int enqueue_queue(Queue *q, int value) {
        if (q->size == q->maxSize) {
            return 0; // Fila cheia
        }
        q->data[q->size] = value;
        q->size += 1;
        return 1;
    }

    int dequeue_queue(Queue *q, int *value) {
        if (q->size == 0) {
            return 0; // Fila vazia
        }

        *value = q->data[0];
        for (int i = 1; i < q->size; i++) {
            q->data[i - 1] = q->data[i];
        }
        q->size -= 1;
        return 1;
    }

    int peek_queue(const Queue *q, int *value) {
        if (q->size == 0) {
            return 0; // Fila vazia
        }
        *value = q->data[0];
        return 1;
    }

    // ========================================================================================
    CircularQueue* initialization_circular_queue(int maxSize) {
        CircularQueue * q = new CircularQueue();
        q->data = new int[maxSize];
        q->head = 0;
        q->tail = -1;
        q->size = 0;
        q->maxSize = maxSize;
        return q;
    }

    void destroy_circular_queue(CircularQueue* q) {
        delete[] q->data;
        delete q;
    }

    int enqueue_circular_queue(CircularQueue *q, int value) {
        if (q->size == q->maxSize) {
            return 0; // Fila cheia
        }
        q->tail = (q->tail + 1) % q->maxSize;
        q->data[q->tail] = value;
        q->size++;
        return 1;
    }

    int dequeue_circular_queue(CircularQueue *q, int *value) {
        if (q->size == 0) {
            return 0; // Fila vazia
        }
        *value = q->data[q->head];
        q->head = (q->head + 1) % q->maxSize;
        q->size--;
        return 1;
    }

    int peek_circular_queue(CircularQueue *q, int *value) {
        if (q->size == 0) {
            return 0; // Fila vazia
        }
        *value = q->data[q->head];
        return 1;
    }
}