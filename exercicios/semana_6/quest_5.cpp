#include "../../modules/tad.h"
#include <iostream>

using namespace std;
using namespace TAD;


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


void print_single_linked_tree(SingleLinkedList* l, int list_to_show = 0) {
    if (list_to_show != 0) {
        cout << "Lista " << list_to_show << ":" << endl;
    }
    SingleLinkedListNode* node1 = l->head;
    if (node1 == nullptr) {
        cout << "Lista Vazia";
    }
    while (node1 != nullptr) {
        cout << node1->value << " ";
        node1 = node1->next;
    }
    cout << endl;
}


void print_double_linked_tree(DoubleLinkedList* l, int list_to_show = 0) {
    if (list_to_show != 0) {
        cout << "Lista " << list_to_show << ":" << endl;
    }
    DoubleLinkedListNode* node1 = l->head;
    if (node1 == nullptr) {
        cout << "Lista Vazia";
    }
    while (node1 != nullptr) {
        cout << node1->value << " ";
        node1 = node1->next;
    }
    cout << endl;
}


int main() {
    // Cria duas listas simplesmente encadeadas ordenadas
    SingleLinkedList* list1 = initialization_single_linked_list();
    DoubleLinkedList* list2 = initialization_double_linked_list();

    // Lista 1: {2, 4, 6, 8, 10}
    insert_end_single_linked_list(list1, 2);
    insert_end_single_linked_list(list1, 4);

    // Lista 2: {1, 3, 5, 7, 9}
    insert_end_double_linked_list(list2, 1);
    insert_end_double_linked_list(list2, 3);

    // Exibindo as duas listas
    print_single_linked_tree(list1, 1);

    print_double_linked_tree(list2, 2);

    cout << endl;

    cout << "======================== DEPOIS DA TROCA ========================" << endl;
    swipe_adjascents_single_linked_list(list1, 0);
    swipe_adjascents_double_linked_list(list2, 0);

    print_single_linked_tree(list1, 1);
    print_double_linked_tree(list2, 2);

    destroy_single_linked_list(list1);
    destroy_double_linked_list(list2);

    return 0;
}
