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
     * @brief Cria um objeto de Fila
     * 
     * @return WaitingQueue* Ponteiro para a fila criada
     */
    WaitingQueue* createQueue();

    /**
     * @brief Essa função adiciona um paciente novo na fila
     * 
     * @param queue A fila que será manipulada
     * @param client O cliente que vai ser adicionado
     */
    void enqueue(WaitingQueue* queue, Client client);

    /**
     * @brief Returo o próximo cliente
     * 
     * @param queue Fila que será manipulada
     * @param returnClient Ponteiro para uma variável do tipo Client
     * @return int Se a operação foi bem-sucedida ou não
     */
    int peek(const WaitingQueue* queue, Client* returnClient);

    /**
     * @brief Re
     * 
     * @param queue 
     * @param returnClient 
     * @return int 
     */
    int dequeue(WaitingQueue* queue, Client* returnClient);
    
    /**
     * @brief Remove um cliente a partir do seu nome
     * 
     * @param queue Fila que será utilizada
     * @param name Nome do paciente que será removido
     * @return int Retorna se a ação foi bem-sucedida
     */
    int removeClient(WaitingQueue* queue, char* name);

    /**
     * @brief Retorna uma lista com os pacientes na exata ordem de atendimento
     * 
     * @param queue A lista que será analisada
     * @param numClients Número de clientes na fila
     * @return Client* Retorna o array de clientes
     */
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients);

    
    void deleteQueue(WaitingQueue* queue);
}

#endif