#include "../../modules/tad.h"
#include <iostream>
#include <limits>

using namespace std;
using namespace TAD;

struct StackWithMin {
    int* data;
    int maxSize;
    int size;
    int minValue;
    Stack* minValuesStack;
};


StackWithMin* initialize_min_stack(int maxSize) {
    StackWithMin* s = new StackWithMin();
    s->data = new int[maxSize];
    s->maxSize = maxSize;
    s->size = 0;
    s->minValue = std::numeric_limits<int>::max();
    s->minValuesStack = initialization_stack(maxSize);

    return s;
}

int push(StackWithMin* s, int value) {
    if (s->size == s->maxSize) {
        return 0;
    }

    if (value <= s->minValue) {
        s->minValue = value;
        push_stack(s->minValuesStack, value);
    }

    s->data[s->size] = value;
    s->size += 1;
    
    return 1;
}

int pop(StackWithMin* s, int* value) {
    if (s->size == 0) {
        return 0;
    }

    s->size -= 1;

    if (s->data[s->size] == s->minValue) {
        int trash = 0;
        pop_stack(s->minValuesStack, &trash);
        peek_stack(s->minValuesStack, &(s->minValue));
    }

    *value = s->data[s->size];

    // Changing the last value is not necessary, because when we push another,
    // it will override

    return 1;
}

void destroy(StackWithMin* s) {
    delete[] s->data;
    destroy_stack(s->minValuesStack);
    delete s;
}

int getMinValue(StackWithMin* s, int* min_value_pointer) {
    if (s->size == 0) {
        return 0;
    }

    *min_value_pointer = s->minValue;

    return 1;
}


int main() {
    StackWithMin* s = initialize_min_stack(5);

    // pop(s, &temp);

    // cout << temp << endl;
    push(s, 3);
    push(s, 5);
    push(s, 1);
    push(s, 7);
    push(s, 2);

    cout << "======= Pilha antes =======" << endl;
    for (int i = 0; i < s->size; i++) {
        cout << s->data[i] << endl;
    }

    int min_value = 0;
    int temp = 0;
    getMinValue(s, &min_value);

    cout << "======= MENOR VALOR =======" << endl;
    cout << min_value << endl;

    pop(s, &temp);
    pop(s, &temp);
    pop(s, &temp);

    getMinValue(s, &min_value);

    cout << "======= Pilha depois =======" << endl;
    for (int i = 0; i < s->size; i++) {
        cout << s->data[i] << endl;
    }

    cout << "======= MENOR VALOR =======" << endl;
    cout << min_value << endl;

    destroy(s);
    return 1;
}
