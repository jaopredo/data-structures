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
    cliente_4.name = "Joao Pedro";
    cliente_4.priority = 0;

    Client cliente_5 = Client();
    cliente_5.name = "Thalis";
    cliente_5.priority = 0;

    Client cliente_6 = Client();
    cliente_6.name = "Alex";
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

    // Deletando um Geral
    char nomeClienteParaDeletar[11] = "Joao Pedro";
    removeClient(waiting_queue, nomeClienteParaDeletar);

    // Deletando um Preferencial

    // Vendo o próximo cliente
    Client next_client;

    // Atendendo as pessoas
    Client dequeued_client;

    // Mostrando tanto o pŕoximo paciente quando o cara atendido
    int size = waiting_queue->size;
    for (int i = 0; i < size; i++) {
        dequeue(waiting_queue, &dequeued_client);

        cout << "=========================" << endl;
        cout << "Paciente atendido: " << dequeued_client.name << endl;
        cout << "Tamanho atual da fila: " << waiting_queue->size << endl;
        cout << "Eu tenho " << waiting_queue->elderlyCount << " idosos" << endl;
        cout << "Eu tenho " << waiting_queue->generalCount << " gerais" << endl;

        peek(waiting_queue, &next_client);

        cout << "Próximo paciente da fila: " << next_client.name << endl;
    }
    
    return 0;
}
