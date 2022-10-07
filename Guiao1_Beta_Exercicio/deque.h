#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stdbool.h>

typedef struct deque{
    int size;
    Node* first;
    Node* last;
    bool reversed;
} Deque;

#endif
