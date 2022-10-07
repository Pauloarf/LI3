#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* stackCreate(void (*elemPrint)(void*)){
    Stack* stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = 0;
    stack->elemPrint = elemPrint;
    return stack;
}

void stackPush(Stack* stack, void* data){
    Node* node = nodeCreate(data);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void* stackPop(Stack* stack){
    if (stack->size == 0){
        return 0;
    }
    Node* top = stack->top;
    stack->top = top->next;
    void* data = top->data;
    free(top);
    stack->size--;
    return data;
}