#ifndef TAD_H
#define TAD_H

namespace TAD {
    // Definindo Pilhas
    struct Stack {
        int * data;
        int maxSize;
        int top;
    };

    Stack* initialization_stack(int maxSize);
    void destroy_stack(Stack* s);
    int push_stack(Stack *s, int value);
    int pop_stack(Stack *s, int *value);
    int peek_stack(const Stack *s, int *value);

    // Definindo Filas normais
    struct Queue {
        int* data;
        int maxSize;
        int size;
    };

    Queue* initialization_queue(int maxSize);
    void destroy_queue(Queue* q);
    int enqueue_queue(Queue* q, int value);
    int dequeue_queue(Queue *q, int *value);
    int peek_queue(Queue *q, int *value);

    // Definindo as Filas Circulares
    struct CircularQueue {
        int *data;
        int maxSize;
        int size;
        int head;
        int tail;
    };

    CircularQueue* initialization_circular_queue(int maxSize);
    void destroy_circular_queue(CircularQueue* q);
    int enqueue_circular_queue(CircularQueue* q, int value);
    int dequeue_circular_queue(CircularQueue *q, int *value);
    int peek_circular_queue(CircularQueue *q, int *value);

    // Definindo as Listas simplesmente Encadeadas
    struct SingleLinkedListNode {
        int value;
        SingleLinkedListNode* next;
    };

    struct SingleLinkedList {
        SingleLinkedListNode* head;
        int size;
    };
    
    SingleLinkedList* create_single_linked_list();
    void insert_front_single_linked_list(SingleLinkedList* list, int value);
    void insert_end_single_linked_list(SingleLinkedList* list, int value);
    void remove_front_single_linked_list(SingleLinkedList* list);
    void remove_middle_single_linked_list(SingleLinkedList* list, int value);
    bool search_single_single_linked_list(SingleLinkedList* list, int value);

    //Definindo as Listas duplamente Encadeadas
    struct DoubleLinkedListNode {
        int value;
        DoubleLinkedListNode* next;
        DoubleLinkedListNode* prev;
    };

    struct DoubleLinkedList {
        DoubleLinkedListNode* head;
        DoubleLinkedListNode* tail;
        int size;
    };

    void insert_front_double_linked_list(DoubleLinkedList* list, int value);
    void insert_end_double_linked_list(DoubleLinkedList* list, int value);
    void remove_front_double_linked_list(DoubleLinkedList* list);
    void remove_middle_double_linked_list(DoubleLinkedList* list, int value);
    void remove_end_double_linked_list(DoubleLinkedList* list) ;
}

#endif