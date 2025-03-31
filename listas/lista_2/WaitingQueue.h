#ifndef WAITING_QUEUE_H
#define WAITING_QUEUE_H

namespace WaitingQueueTAD {
    struct Client {
        const char* name;
        int priority;  // 0 = Geral; 1 = Idoso
    };

    struct QueueNode {
        Client client;
        int order;
        QueueNode* next;
        QueueNode* previous;
    };

    struct WaitingQueue {
        int generalCount;
        int elderlyCount;
        int size;
        int priority_gone;

        QueueNode* head_eldery;
        QueueNode* tail_eldery;

        QueueNode* head_general;
        QueueNode* tail_general;
    };

    /**
     * @brief Create a Queue object
     * 
     * @return WaitingQueue* A pointer to the queue created
     */
    WaitingQueue* createQueue();

    /**
     * @brief This function is responsible for enqueuing a new client
     * 
     * @param queue The queue to be altered
     * @param client The client that will be enqueued
     */
    void enqueue(WaitingQueue* queue, Client client);


    int peek(const WaitingQueue* queue, Client* returnClient);
    int dequeue(WaitingQueue* queue, Client* returnClient);
    int removeClient(WaitingQueue* queue, char* name);
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients);
    void deleteQueue(WaitingQueue* queue);
}

#endif