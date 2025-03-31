#include "WaitingQueue.h"
#include <iostream>

using namespace WaitingQueueTAD;
using namespace std;

int main() {
    WaitingQueue* waiting_queue = createQueue();  // Criando a lista

    Client cliente_1 = Client();
    cliente_1.name = "Seu Genésio";
    cliente_1.priority = 1;

    Client cliente_2 = Client();
    cliente_2.name = "Camacho";
    cliente_2.priority = 1;

    Client cliente_3 = Client();
    cliente_3.name = "Paulo Sad";
    cliente_3.priority = 1;

    Client cliente_4 = Client();
    cliente_4.name = "João Pedro";
    cliente_4.priority = 0;

    Client cliente_5 = Client();
    cliente_5.name = "Thalis";
    cliente_5.priority = 0;

    Client cliente_6 = Client();
    cliente_6.name = "Aléc";
    cliente_6.priority = 0;

    Client cliente_7 = Client();
    cliente_7.name = "Paulo César";
    cliente_7.priority = 1;

    Client cliente_8 = Client();
    cliente_8.name = "Sônia";
    cliente_8.priority = 1;

    enqueue(waiting_queue, cliente_1);
    enqueue(waiting_queue, cliente_2);
    enqueue(waiting_queue, cliente_3);
    enqueue(waiting_queue, cliente_4);
    enqueue(waiting_queue, cliente_5);
    enqueue(waiting_queue, cliente_6);
    enqueue(waiting_queue, cliente_7);
    enqueue(waiting_queue, cliente_8);

    // cout << waiting_queue->head_eldery->order << endl;
    // cout << waiting_queue->head_general->order << endl;
    // cout << waiting_queue->head_eldery->next->order << endl;
    // cout << waiting_queue->head_eldery->next->next->order << endl;
    
    return 0;
}
