# Semana 6: Exercícios sobre Listas Encadeadas

## Questão 1
Implemente uma classe de pilha (stack) utilizando uma lista simplesmente encadeada, sem uso de nós cabeça ou cauda. A implementação deve conter métodos para:
- Inserir um elemento (push)
- Remover um elemento (pop)
- Verificar se a pilha está vazia
- Consultar o elemento no topo sem removê-lo (peek)

```cpp

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
```

## Questão 2
Implemente uma classe de fila (queue) utilizando uma lista simplesmente encadeada, sem uso de nós cabeça ou cauda. A implementação deve conter métodos para:
- Inserir um elemento (enqueue)
- Remover um elemento (dequeue)
- Verificar se a fila está vazia
- Consultar o primeiro elemento sem removê-lo (front)

```cpp
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

bool front(Queue* q, int* returnValue) {
    if (!isEmpty(q)) {
        *returnValue = q->top_node->value;
    }
    return !isEmpty(q);
}
```

## Questão 3
Dadas duas listas ordenadas **L1** e **L2**, implemente um procedimento que compute **L1 ∩ L2** utilizando apenas operações básicas sobre listas.

```cpp
SingleLinkedList* get_ordered_list_intersection(SingleLinkedList* l1, SingleLinkedList* l2) {
    SingleLinkedListNode* n1 = l1->head;
    SingleLinkedListNode* n2 = l2->head;

    if (n1 == nullptr || n2 == nullptr) {  // Se alguma lista tiver vazia
        cout << "Alguma lista é vazia" << endl;
        return nullptr;
    }

    SingleLinkedList* intersection = initialization_single_linked_list();

    do {
        if (n1->value == n2->value) {
            insert_end_single_linked_list(intersection, n1->value);

            if (n1->next != nullptr) {
                n1 = n1->next;
            } else if (n2->next != nullptr) {
                n2 = n2->next;
            }

            continue;
        }

        if (n1->value < n2->value) {
            if (n1->next != nullptr) {
                n1 = n1->next;
            } else if (n2->next != nullptr) {
                n2 = n2->next;
            }
        }
        if (n1->value > n2->value){
            if (n2->next != nullptr) {
                n2 = n2->next;
            } else if (n1->next != nullptr) {
                n1 = n1->next;
            }
        }
    } while (n1->next != nullptr || n2->next != nullptr);

    return intersection;
}
```

## Questão 4
Dadas duas listas ordenadas **L1** e **L2**, implemente um procedimento que compute **L1 ∪ L2** utilizando apenas operações básicas sobre listas.

```cpp
SingleLinkedList* get_ordered_list_union(SingleLinkedList* l1, SingleLinkedList* l2) {
    SingleLinkedListNode* n1 = l1->head;
    SingleLinkedListNode* n2 = l2->head;

    if (n1 == nullptr || n2 == nullptr) {  // Se alguma lista tiver vazia
        cout << "Alguma lista é vazia" << endl;
        return nullptr;
    }

    SingleLinkedList* union_list = initialization_single_linked_list();

    do {
        if (n1->value < n2->value || n1->value == n2->value) {
            if (!search_single_single_linked_list(union_list, n1->value)) {
                insert_end_single_linked_list(union_list, n1->value);
            }
            
            if (n1->next != nullptr) {
                n1 = n1->next;
            } else if (n2->next != nullptr) {
                n2 = n2->next;
            }
        }
        if (n1->value > n2->value){
            if (!search_single_single_linked_list(union_list, n2->value)) {
                insert_end_single_linked_list(union_list, n2->value);
            }

            if (n2->next != nullptr) {
                n2 = n2->next;
            } else if (n1->next != nullptr) {
                n1 = n1->next;
            }
        }

        if (n1->next == nullptr && n2->next == nullptr) {
            if (!search_single_single_linked_list(union_list, n2->value)) {
                insert_end_single_linked_list(union_list, n2->value);
            } else if (!search_single_single_linked_list(union_list, n1->value)) {
                insert_end_single_linked_list(union_list, n1->value);
            }
        }
    } while (n1->next != nullptr || n2->next != nullptr);

    return union_list;
}
```

## Questão 5
Implemente um método para trocar dois elementos adjacentes em uma lista encadeada ajustando apenas os ponteiros (sem modificar os valores armazenados nos nós). Resolva este problema para:
- (a) Listas simplesmente encadeadas
- (b) Listas duplamente encadeadas

```cpp
// Na segunda função eu removi os if do index, mas na primeira eu fiquei com preguiça de voltar e remover

/**
 * @brief Swipes adjascent nodes in a single linked list
 * 
 * @param l A single linked list
 * @param index The "index" of the node that will be swiped (e.g If 1 is passed, the second and third nodes are swiped)
 */
void swipe_adjascents_single_linked_list(SingleLinkedList* l, int index) {
    int counter = 0;

    SingleLinkedListNode* temp_previous = nullptr;
    SingleLinkedListNode* temp_actual = l->head;
    SingleLinkedListNode* temp_next = l->head->next;

    if (index != 0) {
        while(counter < index-1) {
            counter += 1;

            temp_previous = temp_actual;
            temp_actual = temp_actual->next;
            temp_next = temp_actual->next;
        }

        temp_actual->next = temp_next->next;
        temp_previous->next = temp_next;
        temp_next->next = temp_actual;
    } else {
        temp_actual->next = temp_next->next;
        temp_next->next = temp_actual;

        l->head = temp_next;
    }
}


/**
 * @brief Swipes adjascent nodes in a double linked list
 * 
 * @param l A double linked list
 * @param index The "index" of the node that will be swiped (e.g If 1 is passed, the second and third nodes are swiped)
 */
void swipe_adjascents_double_linked_list(DoubleLinkedList* l, int index) {
    int counter = 0;

    DoubleLinkedListNode* temp_previous = nullptr;
    DoubleLinkedListNode* temp_actual = l->head;
    DoubleLinkedListNode* temp_next = l->head->next;

    while(counter < index) {
        temp_previous = temp_actual;
        temp_actual = temp_actual->next;
        temp_next = temp_actual->next;

        counter++;
    }

    temp_actual->next = temp_next->next;

    if (temp_next->next != nullptr) {
        temp_next->next->prev = temp_actual;
    } else {
        l->tail = temp_next->prev;
    }

    if (temp_previous != nullptr) {
        temp_previous->next = temp_next;
    } else {
        l->head = temp_next;
    }

    temp_actual->prev = temp_next;
    temp_next->prev = temp_previous;
    temp_next->next = temp_actual;
}
```

## Questão 6
Desenvolva um algoritmo **não recursivo** que inverta uma lista simplesmente encadeada contendo **n** elementos em tempo **O(n)**, utilizando apenas um espaço de armazenamento constante além do necessário para a própria lista.

```cpp
void reverse_single_linked_list(SingleLinkedList* l) {
    SingleLinkedListNode* previous = nullptr;
    SingleLinkedListNode* actual = l->head;
    SingleLinkedListNode* next = l->head->next;

    while (next != nullptr) {
        actual->next = previous;
        previous = actual;
        actual = next;
        next = next->next;
    }

    actual->next = previous;

    l->head = actual;
}
```

## Questão 7
Suponha que temos um ponteiro para um nó em uma lista simplesmente encadeada, mas **não temos ponteiros para os nós anteriores**. Sabemos que esse nó **não é o último** da lista. Descreva e implemente um algoritmo **O(1)** que remova logicamente o valor armazenado nesse nó, mantendo a integridade da lista encadeada.

## Questão 8
A operação **UNION** em conjuntos dinâmicos recebe dois conjuntos disjuntos **S1** e **S2** e retorna um conjunto **S = S1 ∪ S2**, destruindo os conjuntos originais **S1** e **S2**. Mostre como realizar essa operação em **tempo O(1)** utilizando uma estrutura de dados de lista adequada.
