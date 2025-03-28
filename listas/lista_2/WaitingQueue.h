#ifndef WAITING_QUEUE_H
#define WAITING_QUEUE_H

namespace WaitingQueueTAD {
    struct Client {
        const char* name;
        int priority;  // 0 = Geral; 1 = Idoso
    };

    struct QueueNode {
        Client client;
        QueueNode* next;
        QueueNode* previous;
        // <Demais variáveis a serem definidas>
    };

    struct WaitingQueue {
        int generalCount;
        int elderlyCount;
        int size;

        QueueNode* head;
        QueueNode* tail;
    };

    WaitingQueue* createQueue();
    void enqueue(WaitingQueue* queue, Client client);
    int peek(const WaitingQueue* queue, Client* returnClient);
    int dequeue(WaitingQueue* queue, Client* returnClient);
    int removeClient(WaitingQueue* queue, char* name);
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients);
    void deleteQueue(WaitingQueue* queue);
}

#endif