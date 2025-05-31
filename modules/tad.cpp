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

    // ===========================================================================
    SingleLinkedList* initialization_single_linked_list() {
        SingleLinkedList* list = new SingleLinkedList{};
        list->head = nullptr;
        list->size = 0;
        return list;
    }

    void insert_front_single_linked_list(SingleLinkedList* list, int value) {
        SingleLinkedListNode* newNode = new SingleLinkedListNode{};
        newNode->value = value;
        newNode->next = list->head;
        
        list->head = newNode;
        list->size++;
    }

    void insert_end_single_linked_list(SingleLinkedList* list, int value) {
        SingleLinkedListNode* newNode = new SingleLinkedListNode{};
        newNode->value = value;
        newNode->next = nullptr;
        
        if(list->head == nullptr) {
            list->head = newNode;
        } else {
            SingleLinkedListNode* temp = list->head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        list->size++;
    }

    void remove_front_single_linked_list(SingleLinkedList* list) {
        if (list->head == nullptr) {
            return;
        }

        SingleLinkedListNode* temp = list->head;
        list->head = list->head->next;
        delete temp;
        list->size--;
    }

    void remove_middle_single_linked_list(SingleLinkedList* list, int value) {
        if (list->head == nullptr) {
            return;
        }
        
        SingleLinkedListNode* current = list->head;
        while (current->next != nullptr && current->next->value != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return;
        }

        SingleLinkedListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        list->size--;
    }

    bool search_single_single_linked_list(SingleLinkedList* list, int value) {
        SingleLinkedListNode* current = list->head;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void destroy_single_linked_list(SingleLinkedList* list) {
        SingleLinkedListNode* current = list->head;
        while (current != nullptr) {
            SingleLinkedListNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete list;
    }

    // ===========================================================================
    DoubleLinkedList* initialization_double_linked_list() {
        DoubleLinkedList* list = new DoubleLinkedList;
        list->head = nullptr;
        list->tail = nullptr;
        list->size = 0;
        return list;
    }

    void insert_front_double_linked_list(DoubleLinkedList* list, int value) {
        DoubleLinkedListNode* newNode = new DoubleLinkedListNode{value, list->head, nullptr};

        if (list->head != nullptr) {
            list->head->prev = newNode;
        } else {
            list->tail = newNode;  // Lista estava vazia
        }

        list->head = newNode;
        list->size++;
    }

    void insert_end_double_linked_list(DoubleLinkedList* list, int value) {
        DoubleLinkedListNode* newNode = new DoubleLinkedListNode{value, nullptr, list->tail};

        if (list->tail != nullptr) {
            list->tail->next = newNode;
        } else {
            list->head = newNode;  // Lista estava vazia
        }

        list->tail = newNode;
        list->size++;
    }

    void remove_front_double_linked_list(DoubleLinkedList* list) {
        if (list->head == nullptr) {
            return;  // Lista vazia
        }

        DoubleLinkedListNode* temp = list->head;
        list->head = list->head->next;

        if (list->head != nullptr) {
            list->head->prev = nullptr;
        } else {
            list->tail = nullptr;  // Lista ficou vazia
        }

        delete temp;
        list->size--;
    }

    void remove_end_double_linked_list(DoubleLinkedList* list) {
        if (list->tail == nullptr) {
            return;  // Lista vazia
        }

        DoubleLinkedListNode* temp = list->tail;
        list->tail = list->tail->prev;

        if (list->tail != nullptr) {
            list->tail->next = nullptr;
        } else {
            list->head = nullptr;  // Lista ficou vazia
        }

        delete temp;
        list->size--;
    }

    void remove_middle_double_linked_list(DoubleLinkedList* list, int value) {
        if (list->head == nullptr) {
            return;  // Lista vazia
        }

        DoubleLinkedListNode* current = list->head;
        while (current != nullptr && current->value != value) {
            current = current->next;
        }

        if (current == nullptr) {
            return;  // Valor não encontrado
        }

        if (current == list->head) {
            remove_front_double_linked_list(list);
        } else if (current == list->tail) {
            remove_end_double_linked_list(list);
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            list->size--;
        }
    }

    void destroy_double_linked_list(DoubleLinkedList* list) {
        DoubleLinkedListNode* current = list->head;
        while (current != nullptr) {
            DoubleLinkedListNode* temp = current;
            current = current->next;
            delete temp;
        }
        delete list;
    }

}