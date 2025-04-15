#include <iostream>

using namespace std;

struct StackWithMin {
    int* data;
    int maxSize;
    int size;
    // <Estruturas adicionais necessárias>
};


StackWithMin* initialize_min_stack(int maxSize) {
    StackWithMin* s = new StackWithMin();
    s->data = new int[maxSize];
    s->maxSize = maxSize;
    s->size = 0;

    return s;
}

int push(StackWithMin* s, int value) {
    if (s->size == s->maxSize) {
        return 0;
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
    *value = s->data[s->size];

    // Changing the last value is not necessary, because when we push another,
    // it will override

    return 1;
}

void destroy(StackWithMin* s) {
    delete[] s->data;
    delete s;
}

int getMinValue(StackWithMin* s, int* min_value_pointer) {
    if (s->size == 0) {
        return 0;
    }

    StackWithMin* temp_stack = initialize_min_stack(s->maxSize);  // Initializing stack with same size

    int min_value = s->data[s->size-1];  // Getting a value on the stack to compare later
    int temp_holder = 0;
    // This variable holds the popped value of the real stack so we can manipulate it and store on
    // the other stack

    int initial_size = s->size;

    for (int i = 0; i < initial_size; i++) {
        pop(s, &temp_holder);
        push(temp_stack, temp_holder);

        if (temp_holder < min_value) {
            // If the actual value being compared is less then the minimal
            min_value = temp_holder;  // it becames the minimal
        }
    }

    for (int i = 0; i < initial_size; i++) {
        pop(temp_stack, &temp_holder);
        push(s, temp_holder);
    }

    destroy(temp_stack);

    *min_value_pointer = min_value;

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
    getMinValue(s, &min_value);

    cout << "======= MENOR VALOR =======" << endl;
    cout << min_value << endl;

    cout << "======= Pilha depois =======" << endl;
    for (int i = 0; i < s->size; i++) {
        cout << s->data[i] << endl;
    }

    destroy(s);
    return 1;
}
