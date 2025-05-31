#include "../../modules/tad.h"
#include <iostream>

using namespace std;
using namespace TAD;

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


void print_single_linked_list(SingleLinkedList* l, int list_to_show = 0) {
    if (list_to_show != 0) {
        cout << "Lista " << list_to_show << ":" << endl;
    }
    SingleLinkedListNode* node1 = l->head;
    if (node1 == nullptr) {
        cout << "Lista Vazia" << endl;
    }
    while (node1 != nullptr) {
        cout << node1->value << " ";
        node1 = node1->next;
    }
    cout << endl;
}


int main() {
    SingleLinkedList* l = initialization_single_linked_list();

    insert_end_single_linked_list(l, 2);
    insert_end_single_linked_list(l, 4);
    insert_end_single_linked_list(l, 6);
    insert_end_single_linked_list(l, 8);
    insert_end_single_linked_list(l, 10);
    insert_end_single_linked_list(l, 1);
    insert_end_single_linked_list(l, 3);
    insert_end_single_linked_list(l, 5);
    insert_end_single_linked_list(l, 7);
    insert_end_single_linked_list(l, 9);

    cout << "Antes da inversão:" << endl;
    print_single_linked_list(l, 1);

    cout << "Depois da inversão: " << endl;
    reverse_single_linked_list(l);
    print_single_linked_list(l, 1);

    destroy_single_linked_list(l);
}
