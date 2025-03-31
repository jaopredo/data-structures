#include <limits>
#include "WaitingQueue.h"
#include <iostream>

using namespace std;

namespace WaitingQueueTAD {
    /**
     * @brief Cria um objeto de Fila
     * 
     * @return WaitingQueue* Ponteiro para a fila criada
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
     * @brief Essa função adiciona um paciente novo na fila
     * 
     * @param queue A fila que será manipulada
     * @param client O cliente que vai ser adicionado
     */
    void enqueue(WaitingQueue* queue, Client client) {
        if (queue == nullptr) {
            return;
        }

        queue->size += 1;  // Aumento o tamanho total da minha fila

        QueueNode* recent_node = new QueueNode;  // Crio o nó mais recente
        recent_node->next = nullptr;
        recent_node->previous = nullptr;
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
     * @brief Returo o próximo cliente
     * 
     * @param queue Fila que será manipulada
     * @param returnClient Ponteiro para uma variável do tipo Client
     * @return int Se a operação foi bem-sucedida ou não
     */
    int peek(const WaitingQueue* queue, Client* returnClient) {
        if (queue == nullptr || queue->size == 0) {
            // Se não houver ninguém
            returnClient = nullptr;
            return 0;
        }

        cout << queue->priority_gone << endl;
        cout << queue->elderlyCount << endl;

        if (queue->priority_gone < 2 && queue->elderlyCount > 0) {
            // Se não foi nenhum idoso e tem idosos na fila
            *returnClient = queue->head_eldery->client;
            // Retorno o primeiro na fila de idosos
        } else {

            if (queue->generalCount <= 0) {
                *returnClient = queue->head_eldery->client;
                return 1;
            }

            *returnClient = queue->head_general->client;
        }

        return 1;
    };

    /**
     * @brief Re
     * 
     * @param queue 
     * @param returnClient 
     * @return int 
     */
    int dequeue(WaitingQueue* queue, Client* returnClient) {
        if (queue == nullptr || queue->size == 0) {  // Se a fila estiver vazia
            returnClient = nullptr;
            return 0;
        }

        if (queue->priority_gone < 2 && queue->elderlyCount > 0) {
            // Se não foi nenhum idoso e tem idosos na fila
            *returnClient = queue->head_eldery->client;
            queue->head_eldery = queue->head_eldery->next;
            queue->elderlyCount -= 1;
            queue->priority_gone += 1;
            // Retorno o primeiro na fila de idosos
        } else {
            queue->priority_gone = 0;  // Reseto e agora vai ou um geral (Se não tiver, vai idoso)

            if (queue->generalCount <= 0) {  // Se não houver nenhum geral, eu mando idoso
                *returnClient = queue->head_eldery->client;
                queue->head_eldery = queue->head_eldery->next;
                queue->elderlyCount -= 1;
                queue->priority_gone += 1;
                return 1;
            }
            
            // Do contrário, mando geral
            *returnClient = queue->head_general->client;
            queue->head_general = queue->head_general->next;
            queue->generalCount -= 1;
        }

        queue->size -= 1;

        return 1;
    };

    /**
     * @brief Remove um cliente a partir do seu nome
     * 
     * @param queue Fila que será utilizada
     * @param name Nome do paciente que será removido
     * @return int Retorna se a ação foi bem-sucedida
     */
    int removeClient(WaitingQueue* queue, char* name) {
        if (queue == nullptr || queue->size == 0) {
            return 0;
        }

        QueueNode* node_being_analyzed = queue->head_general;
        // Procurando entre os não prioritários
        for (int i = 0; i < queue->generalCount; i++) {
            cout << "========================================" << endl;
            cout << name << endl;
            cout << node_being_analyzed->client.name << endl;

            if (string(node_being_analyzed->client.name) == string(name)) {
                if (node_being_analyzed->next != nullptr) {
                    node_being_analyzed->next->previous = node_being_analyzed->previous;
                } else {
                    queue->tail_general = node_being_analyzed->previous;
                    queue->tail_general->next = nullptr;
                }

                if (node_being_analyzed->previous != nullptr) {
                    node_being_analyzed->previous->next = node_being_analyzed->next;
                } else {
                    queue->head_general = node_being_analyzed->next;
                    queue->head_general->previous = nullptr;
                }

                queue->size -= 1;
                queue->generalCount -= 1;

                // delete node_being_analyzed;

                return 1;
            }

            cout << "Ta dando certo" << endl;
            node_being_analyzed = node_being_analyzed->next;
        }

        // Procurando entre os prioritários
        for (int j = 0; j < queue->elderlyCount; j++) {
            
        }

        return 0;
    };

    // Client* getQueueOrder(const WaitingQueue* queue, int* numClients) {

    // };

    // void deleteQueue(WaitingQueue* queue) {

    // };
}
