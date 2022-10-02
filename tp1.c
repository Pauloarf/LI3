#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    void* data;
    Node* next;
    Node* prev;
} Node;

typedef struct deque{
    int size;
    Node* first;
    Node* last;
    bool reversed;
} Deque;

Node* nodeCreate(void *data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Deque* createDeque(){
    Deque* deque = malloc(sizeof(Deque));
    deque->size = 0;
    deque->first = 0;
    deque->last = 0;
    return deque;
}

void push(Deque* deque, void* data){
    Node* node = nodeCreate(data);
    node->prev = deque->last;
    deque->last = node;
    deque->size++;
}

void pushFront(Deque* deque, void* data){
    Node* node = nodeCreate(data);
    node->next = deque->first;
    deque->first = node;
    deque->size++;
}