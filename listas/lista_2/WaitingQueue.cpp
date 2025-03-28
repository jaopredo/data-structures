#include "WaitingQueue.h"
#include <iostream>

using namespace std;

namespace WaitingQueueTAD {
    /**
     * @brief Create a Queue object
     * 
     * @return WaitingQueue* A pointer to the queue created
     */
    WaitingQueue* createQueue() {
        WaitingQueue* w = new WaitingQueue();
        w->generalCount = 0;
        w->elderlyCount = 0;
        w->size = 0;
        w->head = nullptr;
        w->tail = nullptr;

        return w;
    };

    /**
     * @brief This function is responsible for enqueuing a new client
     * 
     * @param queue The queue to be altered
     * @param client The client that will be enqueued
     */
    void enqueue(WaitingQueue* queue, Client client) {
        QueueNode* recent_node = new QueueNode;  // Creating the new node to be added
        recent_node->client = client;  // Setting the client on the node's attribute
        recent_node->next = nullptr;
        recent_node->previous = nullptr;

        if (queue->head == nullptr) {  // If the queue is empty
            queue->head = recent_node;  // I'm inserting the first node of the queue
            queue->tail = recent_node;  // I'm inserting the first node of the queue
        } else {
            recent_node->previous = queue->tail;
            queue->tail->next = recent_node;
            queue->tail = recent_node;

            queue->size += 1;  // Sum 1 to the total size of the queue
            // If it's elderly, I sum 1
            queue->elderlyCount += recent_node->client.priority;
            // If it's general, I sum 1
            queue->generalCount += 1 - recent_node->client.priority;
        }
    };

    // int peek(const WaitingQueue* queue, Client* returnClient) {

    // };

    // int dequeue(WaitingQueue* queue, Client* returnClient) {

    // };

    // int removeClient(WaitingQueue* queue, char* name) {

    // };

    // Client* getQueueOrder(const WaitingQueue* queue, int* numClients) {

    // };

    // void deleteQueue(WaitingQueue* queue) {

    // };
}
