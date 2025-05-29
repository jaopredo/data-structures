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

## Questão 5
Implemente um método para trocar dois elementos adjacentes em uma lista encadeada ajustando apenas os ponteiros (sem modificar os valores armazenados nos nós). Resolva este problema para:
- (a) Listas simplesmente encadeadas
- (b) Listas duplamente encadeadas

## Questão 6
Desenvolva um algoritmo **não recursivo** que inverta uma lista simplesmente encadeada contendo **n** elementos em tempo **O(n)**, utilizando apenas um espaço de armazenamento constante além do necessário para a própria lista.

## Questão 7
Suponha que temos um ponteiro para um nó em uma lista simplesmente encadeada, mas **não temos ponteiros para os nós anteriores**. Sabemos que esse nó **não é o último** da lista. Descreva e implemente um algoritmo **O(1)** que remova logicamente o valor armazenado nesse nó, mantendo a integridade da lista encadeada.

## Questão 8
A operação **UNION** em conjuntos dinâmicos recebe dois conjuntos disjuntos **S1** e **S2** e retorna um conjunto **S = S1 ∪ S2**, destruindo os conjuntos originais **S1** e **S2**. Mostre como realizar essa operação em **tempo O(1)** utilizando uma estrutura de dados de lista adequada.
