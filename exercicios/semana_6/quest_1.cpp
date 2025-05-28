#include "../../modules/tad.h"
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next_node;
};

struct Stack {
    Node* top_node;
    int size;
    int max_size;
};

Stack* initialization_stack(int maxSize) {
    Stack* stack = new Stack;
    stack->max_size = maxSize;
    stack->size = 0;
    stack->top_node = nullptr;
    return stack;
}

bool push(int value, Stack* s) {
    if (s->size == s->max_size){
        return false;
    }

    s->size += 1;

    if (s->top_node == nullptr) {
        s->top_node = new Node;
        s->top_node->value = value;
        s->top_node->next_node = nullptr;

        return true;
    }
    Node* new_node = new Node;
    new_node->value = value;
    new_node->next_node = s->top_node;
    s->top_node = new_node;

    return true;
}

bool pop(Stack* s, int* return_value) {
    if (s->size == 0) {
        return false;
    }

    s->size-=1;
    if (s->top_node->next_node == nullptr) {
        *return_value = s->top_node->value;
        Node* top_node = s->top_node;
        s->top_node = nullptr;
        delete top_node;
        return true;
    }

    Node* top_node = s->top_node;
    s->top_node = s->top_node->next_node;
    *return_value = top_node->value;
    delete top_node;

    return true;
}

void destroy_stack(Stack* s) {
    int temp_val = 0;

    while (s->top_node != nullptr) {
        pop(s, &temp_val);
    }

    delete s;
}

bool isEmpty(Stack* s) {
    return s->size == 0;
}

bool peek(Stack* s, int* returnValue) {
    if (!isEmpty(s)) {
        *returnValue = s->top_node->value;
    }
    return !isEmpty(s);
}

void print_division() {
    cout << "===============================" << endl;
}

void print_stack(Stack* s) {
    Node* actual_node = s->top_node;
    for (int j = 0; j < s->size; j++) {
        cout << actual_node->value << endl;
        actual_node = actual_node->next_node;
    }

    print_division();
}

int main() {
    Stack* s = initialization_stack(10);
    
    for (int i = 0; i < 10; i++) {
        push(i, s);
    }

    print_stack(s);

    int returnValue = 0;

    pop(s, &returnValue);

    cout << returnValue << endl;

    destroy_stack(s);

    return 0;
}
