#include "../../modules/tad.h"
#include <iostream>

using namespace std;
using namespace TAD;

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


void print_single_linked_tree(SingleLinkedList* l, int list_to_show = 0) {
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
    cout << "================ LISTAS 1 E 2 =====================" << endl;
    // Cria duas listas simplesmente encadeadas ordenadas
    SingleLinkedList* list1 = initialization_single_linked_list();
    SingleLinkedList* list2 = initialization_single_linked_list();

    // Lista 1: {2, 4, 6, 8, 10}
    insert_end_single_linked_list(list1, 2);
    insert_end_single_linked_list(list1, 4);
    insert_end_single_linked_list(list1, 6);
    insert_end_single_linked_list(list1, 8);
    insert_end_single_linked_list(list1, 10);

    // Lista 2: {1, 3, 5, 7, 9}
    insert_end_single_linked_list(list2, 1);
    insert_end_single_linked_list(list2, 3);
    insert_end_single_linked_list(list2, 5);
    insert_end_single_linked_list(list2, 7);
    insert_end_single_linked_list(list2, 9);

    // Exibindo as duas listas
    print_single_linked_tree(list1, 1);

    print_single_linked_tree(list2, 2);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection1 = get_ordered_list_intersection(list1, list2);
    print_single_linked_tree(intersection1, 0);

    cout << "================ LISTAS 3 E 4 =====================" << endl;
    // Cria duas listas simplesmente encadeadas ordenadas
    SingleLinkedList* list3 = initialization_single_linked_list();
    SingleLinkedList* list4 = initialization_single_linked_list();

    // Lista 1: {2, 4, 6, 8, 10}
    insert_end_single_linked_list(list3, 2);
    insert_end_single_linked_list(list3, 4);
    insert_end_single_linked_list(list3, 6);
    insert_end_single_linked_list(list3, 8);
    insert_end_single_linked_list(list3, 10);

    // Lista 2: {4, 5, 6, 7, 8}  // Tem 4, 6, 8 em comum
    insert_end_single_linked_list(list4, 4);
    insert_end_single_linked_list(list4, 5);
    insert_end_single_linked_list(list4, 6);
    insert_end_single_linked_list(list4, 7);
    insert_end_single_linked_list(list4, 8);

    // Exibindo as duas listas
    print_single_linked_tree(list3, 3);

    print_single_linked_tree(list4, 4);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection2 = get_ordered_list_intersection(list3, list4);
    print_single_linked_tree(intersection2, 0);

    cout << "================ LISTAS 5 E 6 =====================" << endl;
    SingleLinkedList* list5 = initialization_single_linked_list();
    SingleLinkedList* list6 = initialization_single_linked_list();

    // Lista 1: {2, 4, 6, 8, 10, 12, 14}
    insert_end_single_linked_list(list5, 2);
    insert_end_single_linked_list(list5, 4);
    insert_end_single_linked_list(list5, 6);
    insert_end_single_linked_list(list5, 8);
    insert_end_single_linked_list(list5, 10);
    insert_end_single_linked_list(list5, 12);
    insert_end_single_linked_list(list5, 14);

    // Lista 2: {1, 3, 5, 7}
    insert_end_single_linked_list(list6, 1);
    insert_end_single_linked_list(list6, 3);
    insert_end_single_linked_list(list6, 5);
    insert_end_single_linked_list(list6, 7);

    // Exibindo as duas listas
    print_single_linked_tree(list5, 5);

    print_single_linked_tree(list6, 6);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection3 = get_ordered_list_intersection(list5, list6);
    print_single_linked_tree(intersection3, 0);

    cout << "================ LISTAS 7 E 8 =====================" << endl;
    SingleLinkedList* list7 = initialization_single_linked_list();
    SingleLinkedList* list8 = initialization_single_linked_list();
    // Lista 1: {2, 4, 6, 8, 10, 12, 14}
    insert_end_single_linked_list(list7, 2);
    insert_end_single_linked_list(list7, 4);
    insert_end_single_linked_list(list7, 6);
    insert_end_single_linked_list(list7, 8);
    insert_end_single_linked_list(list7, 10);
    insert_end_single_linked_list(list7, 12);
    insert_end_single_linked_list(list7, 13);
    insert_end_single_linked_list(list7, 14);

    // Lista 2: {4, 7, 10, 13}  // Tem 4 e 10 em comum
    insert_end_single_linked_list(list8, 4);
    insert_end_single_linked_list(list8, 7);
    insert_end_single_linked_list(list8, 10);
    insert_end_single_linked_list(list8, 13);

    // Exibindo as duas listas
    print_single_linked_tree(list7, 7);

    print_single_linked_tree(list8, 8);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection4 = get_ordered_list_intersection(list7, list8);
    print_single_linked_tree(intersection4, 0);

    cout << "================ LISTAS 9 E 10 =====================" << endl;
    SingleLinkedList* list9 = initialization_single_linked_list();
    SingleLinkedList* list10 = initialization_single_linked_list();

    // Lista 1: {1, 2, 3, 4, 5, 6, 7}
    insert_end_single_linked_list(list9, 1);
    insert_end_single_linked_list(list9, 2);
    insert_end_single_linked_list(list9, 3);
    insert_end_single_linked_list(list9, 4);
    insert_end_single_linked_list(list9, 5);
    insert_end_single_linked_list(list9, 6);
    insert_end_single_linked_list(list9, 7);

    // Lista 2: {20, 25, 30, 35}
    insert_end_single_linked_list(list10, 20);
    insert_end_single_linked_list(list10, 25);
    insert_end_single_linked_list(list10, 30);
    insert_end_single_linked_list(list10, 35);


    // Exibindo as duas listas
    print_single_linked_tree(list9, 9);

    print_single_linked_tree(list10, 10);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection5 = get_ordered_list_intersection(list9, list10);
    print_single_linked_tree(intersection5, 0);

    cout << "================ LISTAS 11 E 12 =====================" << endl;
    SingleLinkedList* list11 = initialization_single_linked_list();
    SingleLinkedList* list12 = initialization_single_linked_list();

    // Lista 1: {1, 2, 3, 4, 5, 6, 7}
    insert_end_single_linked_list(list11, 1);
    insert_end_single_linked_list(list11, 2);
    insert_end_single_linked_list(list11, 3);
    insert_end_single_linked_list(list11, 4);
    insert_end_single_linked_list(list11, 5);
    insert_end_single_linked_list(list11, 6);
    insert_end_single_linked_list(list11, 7);

    // Lista 2: {5, 10, 20, 30}  // Tem 5 em comum
    insert_end_single_linked_list(list12, 5);
    insert_end_single_linked_list(list12, 10);
    insert_end_single_linked_list(list12, 20);
    insert_end_single_linked_list(list12, 30);

    // Exibindo as duas listas
    print_single_linked_tree(list11, 11);

    print_single_linked_tree(list12, 12);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection6 = get_ordered_list_intersection(list11, list12);
    print_single_linked_tree(intersection6, 0);

    cout << "================ LISTAS 13 E 14 =====================" << endl;
    SingleLinkedList* list13 = initialization_single_linked_list();
    SingleLinkedList* list14 = initialization_single_linked_list();

    // Lista 1: {1, 3, 5, 7}
    insert_end_single_linked_list(list13, 1);
    insert_end_single_linked_list(list13, 3);
    insert_end_single_linked_list(list13, 5);
    insert_end_single_linked_list(list13, 7);

    // Lista 2: {2, 4, 6, 8, 10, 12, 14}
    insert_end_single_linked_list(list14, 2);
    insert_end_single_linked_list(list14, 4);
    insert_end_single_linked_list(list14, 6);
    insert_end_single_linked_list(list14, 8);
    insert_end_single_linked_list(list14, 10);
    insert_end_single_linked_list(list14, 12);
    insert_end_single_linked_list(list14, 14);

    // Exibindo as duas listas
    print_single_linked_tree(list13, 13);

    print_single_linked_tree(list14, 14);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection7 = get_ordered_list_intersection(list13, list14);
    print_single_linked_tree(intersection7, 0);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    cout << "================ LISTAS 15 E 16 =====================" << endl;
    SingleLinkedList* list15 = initialization_single_linked_list();
    SingleLinkedList* list16 = initialization_single_linked_list();

    // Lista 1: {1, 3, 5, 7}
    insert_end_single_linked_list(list15, 1);
    insert_end_single_linked_list(list15, 3);
    insert_end_single_linked_list(list15, 5);
    insert_end_single_linked_list(list15, 7);

    // Lista 2: {2, 4, 6, 8, 10, 12, 14}
    insert_end_single_linked_list(list16, 2);
    insert_end_single_linked_list(list16, 4);
    insert_end_single_linked_list(list16, 5);
    insert_end_single_linked_list(list16, 7);
    insert_end_single_linked_list(list16, 8);
    insert_end_single_linked_list(list16, 10);
    insert_end_single_linked_list(list16, 12);
    insert_end_single_linked_list(list16, 14);

    // Exibindo as duas listas
    print_single_linked_tree(list15, 13);

    print_single_linked_tree(list16, 14);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection8 = get_ordered_list_intersection(list15, list16);
    print_single_linked_tree(intersection8, 0);

    cout << "================ LISTAS 17 E 18 =====================" << endl;
    SingleLinkedList* list17 = initialization_single_linked_list();
    SingleLinkedList* list18 = initialization_single_linked_list();

    // Lista 1: {50, 60, 70, 80}
    insert_end_single_linked_list(list17, 50);
    insert_end_single_linked_list(list17, 60);
    insert_end_single_linked_list(list17, 70);
    insert_end_single_linked_list(list17, 80);

    // Lista 2: {1, 2, 3, 4, 5, 6, 7}
    insert_end_single_linked_list(list18, 1);
    insert_end_single_linked_list(list18, 2);
    insert_end_single_linked_list(list18, 3);
    insert_end_single_linked_list(list18, 4);
    insert_end_single_linked_list(list18, 5);
    insert_end_single_linked_list(list18, 6);
    insert_end_single_linked_list(list18, 7);

    // Exibindo as duas listas
    print_single_linked_tree(list17, 13);

    print_single_linked_tree(list18, 14);

    cout << "=========================================" << endl;
    cout << "Intersecção:" << endl;

    SingleLinkedList* intersection9 = get_ordered_list_intersection(list17, list18);
    print_single_linked_tree(intersection9, 0);

    // Destruindo as listas 
    destroy_single_linked_list(list1);
    destroy_single_linked_list(list2);
    destroy_single_linked_list(list3);
    destroy_single_linked_list(list4);
    destroy_single_linked_list(list5);
    destroy_single_linked_list(list6);
    destroy_single_linked_list(list7);
    destroy_single_linked_list(list8);
    destroy_single_linked_list(list9);
    destroy_single_linked_list(list10);
    destroy_single_linked_list(list11);
    destroy_single_linked_list(list12);
    destroy_single_linked_list(list13);
    destroy_single_linked_list(list14);
    destroy_single_linked_list(list15);
    destroy_single_linked_list(list16);
    destroy_single_linked_list(list17);
    destroy_single_linked_list(list18);

    destroy_single_linked_list(intersection1);
    destroy_single_linked_list(intersection2);
    destroy_single_linked_list(intersection3);
    destroy_single_linked_list(intersection4);
    destroy_single_linked_list(intersection5);
    destroy_single_linked_list(intersection6);
    destroy_single_linked_list(intersection7);
    destroy_single_linked_list(intersection8);
    destroy_single_linked_list(intersection9);

    return 0;
}