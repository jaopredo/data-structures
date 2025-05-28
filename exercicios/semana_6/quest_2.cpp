#include "../../modules/tad.h"
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next_node;
};

struct Queue {
    Node* top_node;
    int size;
    int max_size;
};

Queue* initialization_stack(int maxSize) {
    Queue* queue = new Queue;
    queue->max_size = maxSize;
    queue->size = 0;
    queue->top_node = nullptr;
    return queue;
}

bool enqueue(int value, Queue* q) {
    if (q->size == q->max_size){
        return false;
    }

    q->size += 1;

    if (q->top_node == nullptr) {
        q->top_node = new Node;
        q->top_node->value = value;
        q->top_node->next_node = nullptr;
        return true;
    }
    
    Node* actual_node = q->top_node;
    while (actual_node->next_node != nullptr){
        actual_node = actual_node->next_node;
    }
    
    actual_node->next_node = new Node;
    actual_node->next_node->next_node = nullptr;
    actual_node->next_node->value = value;

    return true;
}

bool dequeue(Queue* q, int* return_value) {
    if (q->size == 0) {
        return false;
    }

    q->size -= 1;

    if (q->top_node->next_node == nullptr) {
        *return_value = q->top_node->value;
        delete q->top_node;
        q->top_node = nullptr;
        return true;
    }

    Node* old_top_node = q->top_node;
    q->top_node = old_top_node->next_node;
    *return_value = old_top_node->value;
    delete old_top_node;
    
    return true;
}

void destroy_queue(Queue* q) {
    int temp_val = 0;

    while (q->top_node != nullptr) {
        dequeue(q, &temp_val);
    }

    delete q;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

bool peek(Queue* q, int* returnValue) {
    if (!isEmpty(q)) {
        *returnValue = q->top_node->value;
    }
    return !isEmpty(q);
}

void print_division() {
    cout << "===============================" << endl;
}

void print_queue(Queue* q) {
    Node* actual_node = q->top_node;
    while (actual_node->next_node != nullptr){
        cout << actual_node->value << endl;
        actual_node = actual_node->next_node;
    }

    print_division();
}

int main() {
    Queue* q = initialization_stack(10);
    
    for (int i = 0; i < 10; i++) {
        enqueue(i, q);
    }

    print_queue(q);

    int returnValue = 0;

    dequeue(q, &returnValue);

    cout << returnValue << endl;

    destroy_queue(q);

    return 0;
}
