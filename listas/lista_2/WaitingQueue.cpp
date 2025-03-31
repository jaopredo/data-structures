#include <limits>
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
        
        w->priority_gone = 0;
        w->size = 0;

        w->head_eldery = nullptr;
        w->tail_eldery = nullptr;

        w->head_general = nullptr;
        w->tail_general = nullptr;

        return w;
    };

    /**
     * @brief This function is responsible for enqueuing a new client
     * 
     * @param queue The queue to be altered
     * @param client The client that will be enqueued
     */
    void enqueue(WaitingQueue* queue, Client client) {
        if (queue == nullptr) {
            return;
        }

        queue->size += 1;  // Aumento o tamanho total da minha fila

        QueueNode* recent_node = new QueueNode;  // Crio o nó mais recente
        recent_node->client = client;  // Associo ao cliente passado
        recent_node->order = queue->size;  // Indico qual é a posição geral dele na fila

        if (client.priority) {  // Se for um cliente idoso
            if (queue->elderlyCount == 0) {  // E se a fila de idosos estiver vazia
                queue->tail_eldery = recent_node;  // A cauda da fila é meu novo nó
                queue->head_eldery = recent_node;  // A cabeça da fila é meu novo nó
                queue->elderlyCount += 1;  // Aumento a quantidade de idosos
                return;
            }

            recent_node->previous = queue->tail_eldery;
            // O antigo do nó mais recente é a atual cauda
            queue->tail_eldery->next = recent_node;
            // O próximo da cauda é o meu nó atual
            queue->tail_eldery = recent_node;
            // Faço com que meu nó atual seja a cauda
            queue->elderlyCount += 1;
            // Aumento a quantidade de idosos
        } else {  // Se o cliente for geral
            if (queue->generalCount == 0) {  // E se a fila de gerais estiver vazia
                queue->tail_general = recent_node;  // A cauda da fila é meu novo nó
                queue->head_general = recent_node;  // A cabeça da fila é meu novo nó
                queue->generalCount += 1;  // Aumento a quantidade de gerais
                return;
            }
            recent_node->previous = queue->tail_general;
            // O antigo do nó mais recente é a atual cauda
            queue->tail_general->next = recent_node;
            // O próximo da cauda é o meu nó atual
            queue->tail_general = recent_node;
            // Faço com que meu nó atual seja a cauda
            queue->generalCount += 1;
            // Aumento a quantidade de gerais
        }
    };

    /**
     * @brief Returns the next client 
     * 
     * @param queue 
     * @param returnClient 
     * @return int 
     */
    int peek(const WaitingQueue* queue, Client* returnClient) {
        if (queue->size == 0) {
            // Se não houver ninguém
            returnClient = nullptr;
            return 0;
        }

        // Declarando variáveis úteis
        int infinity = std::numeric_limits<int>::max();
        QueueNode* head_eldery = queue->head_eldery;
        QueueNode* head_general = queue->head_general;

        // Farei isso para evitar muitos ifs la na frente e algumas
        // Comparações já bastarem
        if (head_eldery == nullptr) {
            head_eldery = new QueueNode;
            head_eldery->order = infinity;
        }
        if (head_general == nullptr) {
            head_general = new QueueNode;
            head_general->order = infinity;
        }

        if (queue->priority_gone < 2 && queue->elderlyCount > 0) {
            // Se não foi nenhum idoso e tem idosos na fila
            *returnClient = head_eldery->client;
            // Retorno o primeiro na fila de idosos
        } else {
            if (head_eldery->order > head_general->order) {
                *returnClient = queue->head_general->client;
            } else {
                *returnClient = queue->head_eldery->client;
            }
        }

        return 1;
    };

    // int dequeue(WaitingQueue* queue, Client* returnClient) {

    // };

    // int removeClient(WaitingQueue* queue, char* name) {

    // };

    // Client* getQueueOrder(const WaitingQueue* queue, int* numClients) {

    // };

    // void deleteQueue(WaitingQueue* queue) {

    // };
}
