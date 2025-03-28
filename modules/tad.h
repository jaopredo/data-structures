#ifndef TAD_H
#define TAD_H

namespace TAD {
    // Definindo Pilhas
    typedef struct {
        int * data;
        int maxSize;
        int top;
    } Stack;

    Stack* initialization_stack(int maxSize);
    void destroy_stack(Stack* s);
    int push_stack(Stack *s, int value);
    int pop_stack(Stack *s, int *value);
    int peek_stack(const Stack *s, int *value);

    // Definindo Filas normais
    typedef struct {
        int* data;
        int maxSize;
        int size;
    } Queue;

    Queue* initialization_queue(int maxSize);
    void destroy_queue(Queue* q);
    int enqueue_queue(Queue* q, int value);
    int dequeue_queue(Queue *q, int *value);
    int peek_queue(Queue *q, int *value);

    // Definindo as Filas Circulares
    typedef struct {
        int *data;
        int maxSize;
        int size;
        int head;
        int tail;
    } CircularQueue;

    CircularQueue* initialization_circular_queue(int maxSize);
    void destroy_circular_queue(CircularQueue* q);
    int enqueue_circular_queue(CircularQueue* q, int value);
    int dequeue_circular_queue(CircularQueue *q, int *value);
    int peek_circular_queue(CircularQueue *q, int *value);
}

#endif