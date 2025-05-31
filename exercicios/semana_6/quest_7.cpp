#include "../../modules/tad.h"
#include <iostream>

using namespace std;
using namespace TAD;


void delete_node_single_linked_list(SingleLinkedListNode* n) {
    SingleLinkedListNode* next_node = n->next;
    n->value = next_node->value;
    n->next = next_node->next;
    delete next_node;
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

    cout << "Depois de deletar: " << endl;
    delete_node_single_linked_list(l->head->next->next->next);
    print_single_linked_list(l, 1);

    destroy_single_linked_list(l);
}
