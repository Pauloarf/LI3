#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "stack.h"

void printInt(void* i){
    int* i_ = i;
    printf("%d", *i_);
} 

int main(int argc, char** argv){
    srand(time(NULL)); // utiliza o relogio do computador para gerar um seed, que por sua vez gera um numero aleatório

    Stack* s = stackCreate(&printInt);
    for (int i = 0; i < 5; i++){
        stackPrint(s);
        int* i = malloc(sizeof(int));
        *i = rand() % 100;
        stackPush(s, i);
    }
    stackPrint(s);

    int* i;
    while (i = stackPop(s)){
        free(i);
        stackPrint(s);
    }

    free(s);
    
    return 0;
}