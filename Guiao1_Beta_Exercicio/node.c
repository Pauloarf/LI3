#ifndef NODE_H
#define NODE_H

typedef struct node{
    void* data;
    Node* next;
    Node* prev;
} Node;

Node* nodeCreate(void* data);

#endif