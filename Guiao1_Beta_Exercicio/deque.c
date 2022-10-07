#include "deque.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//funcao a ser implementada no ficheiro node.c
/*
Node* nodeCreate(void *data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
*/

Deque* createDeque(){
    Deque* deque = malloc(sizeof(Deque));
    deque->size = 0;
    deque->first = 0;
    deque->last = 0;
    return deque;
}

// no caso de size = 0; deque->front e deque->last apontam para o mesmo,
// (adicionar if para deque->size = 0)
void push(Deque* deque, void* data){
    Node* node = nodeCreate(data);
    node->next = deque->last;
    (deque->last)->prev = node;
    deque->last = node;
    deque->size++;
}

void pushFront(Deque* deque, void* data){
    Node* node = nodeCreate(data);
    node->prev = deque->first;
    deque->first->next = node;
    deque->first = node;
    deque->size++;
}