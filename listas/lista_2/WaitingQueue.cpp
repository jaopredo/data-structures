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

        QueueNode* temp = nullptr;

        if (queue->priority_gone < 2 && queue->elderlyCount > 0) {
            // Se não foi nenhum idoso e tem idosos na fila
            temp = queue->head_eldery;
            *returnClient = queue->head_eldery->client;
            if (queue->head_eldery->next != nullptr) {
                queue->head_eldery = queue->head_eldery->next;
            }
            queue->elderlyCount -= 1;
            queue->priority_gone += 1;

            delete temp;
            // Retorno o primeiro na fila de idosos
        } else {
            queue->priority_gone = 0;  // Reseto e agora vai ou um geral (Se não tiver, vai idoso)

            if (queue->generalCount <= 0) {  // Se não houver nenhum geral, eu mando idoso
                temp = queue->head_eldery;
                *returnClient = queue->head_eldery->client;
                if (queue->head_eldery->next != nullptr) {
                    queue->head_eldery = queue->head_eldery->next;
                }
                queue->elderlyCount -= 1;
                queue->size -= 1;
                delete temp;
                return 1;
            }
            
            // Do contrário, mando geral
            temp = queue->head_general;
            *returnClient = queue->head_general->client;
            if (queue->head_general->next != nullptr) {
                queue->head_general = queue->head_general->next;
            }
            queue->generalCount -= 1;
            delete temp;
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

        QueueNode* node_being_analyzed_general = queue->head_general;
        // Procurando entre os não prioritários
        for (int i = 0; i < queue->generalCount; i++) {
            if (string(node_being_analyzed_general->client.name) == string(name)) {
                if (node_being_analyzed_general->next != nullptr) {
                    node_being_analyzed_general->next->previous = node_being_analyzed_general->previous;
                } else {
                    queue->tail_general = node_being_analyzed_general->previous;
                    queue->tail_general->next = nullptr;
                }

                if (node_being_analyzed_general->previous != nullptr) {
                    node_being_analyzed_general->previous->next = node_being_analyzed_general->next;
                } else {
                    queue->head_general = node_being_analyzed_general->next;
                    queue->head_general->previous = nullptr;
                }

                queue->size -= 1;
                queue->generalCount -= 1;

                delete node_being_analyzed_general;

                return 1;
            }
            node_being_analyzed_general = node_being_analyzed_general->next;
        }

        QueueNode* node_being_analyzed_eldery = queue->head_eldery;
        // Procurando entre os prioritários
        for (int j = 0; j < queue->elderlyCount; j++) {
            if (string(node_being_analyzed_eldery->client.name) == string(name)) {
                if (node_being_analyzed_eldery->next != nullptr) {
                    node_being_analyzed_eldery->next->previous = node_being_analyzed_eldery->previous;
                } else {
                    queue->tail_eldery = node_being_analyzed_eldery->previous;
                    queue->tail_eldery->next = nullptr;
                }

                if (node_being_analyzed_eldery->previous != nullptr) {
                    node_being_analyzed_eldery->previous->next = node_being_analyzed_eldery->next;
                } else {
                    queue->head_eldery = node_being_analyzed_eldery->next;
                    queue->head_eldery->previous = nullptr;
                }

                queue->size -= 1;
                queue->elderlyCount -= 1;

                delete node_being_analyzed_eldery;

                return 1;
            }
            node_being_analyzed_eldery = node_being_analyzed_eldery->next;
        }

        return 0;
    };

    /**
     * @brief Retorna uma lista com os pacientes na exata ordem de atendimento
     * 
     * @param queue A lista que será analisada
     * @param numClients Número de clientes na fila
     * @return Client* Retorna o array de clientes
     */
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients) {
        if (queue == nullptr || queue->size == 0) {
            *numClients = 0;
            return nullptr;
        }

        Client* arr = new Client[queue->size];
        
        int elderyChecked = 0;

        QueueNode* eldery_node_checked = queue->head_eldery;
        QueueNode* general_node_checked = queue->head_general;
        
        for (int i = 0; i < queue->size; i++) {
            if (elderyChecked < 2 && eldery_node_checked != nullptr) {
                *(arr + i) = eldery_node_checked->client;
                eldery_node_checked = eldery_node_checked->next;
                elderyChecked += 1;
            } else {
                elderyChecked = 0;
                if (general_node_checked != nullptr) {
                    *(arr + i) = general_node_checked->client;
                    general_node_checked = general_node_checked->next;
                } else {
                    *(arr + i) = eldery_node_checked->client;
                    eldery_node_checked = eldery_node_checked->next;
                }
            }
        }

        *numClients = queue->size;

        return arr;
    };

    /**
     * @brief Deleta a fila passada
     * 
     * @param queue Fila a ser deletada
     */
    void deleteQueue(WaitingQueue* queue) {
        cout << "===============" << endl;

        // Declaro um nó temporário que usarei para percorrer a lista encadeada
        QueueNode* actual_general_node = queue->head_general;
        for (int i = 0; i < queue->generalCount; i++) { // Faço um for em todas as pessoas gerais
            if (actual_general_node->next != nullptr) {  // Se o próximo nó não for nulo
                actual_general_node = actual_general_node->next;  // Eu vou para o próximo
                delete actual_general_node->previous;  // Deleto o anterior
            }
        }

        // Declaro um nó temporário que usarei para percorrer a lista encadeada
        QueueNode* actual_eldery_node = queue->head_eldery;
        for (int i = 0; i < queue->elderlyCount; i++) { // Faço um for em todos os idosos
            if (actual_eldery_node->next != nullptr) {  // Se o próximo nó não for nulo
                actual_eldery_node = actual_eldery_node->next;  // Eu vou para o próximo
                delete actual_eldery_node->previous;  // Deleto o anterior
            }
        }

        delete actual_eldery_node;
        delete actual_general_node;  // Deleto o último nó percorrido

        delete queue;
    };
}
