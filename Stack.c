/************************
 * Stack.c
 * Alex Lindemann
 * 11/25/2015
 * Matrix Multiplication.
 ************************/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

StackP newStack(){
    StackP tmp = malloc(sizeof(struct Stack));
    tmp->position = -1;
    return tmp;
}

void push(StackP my_stack, char item){

    my_stack->stack[++(my_stack->position)] = item;
    return;
}

char pop(StackP my_stack){
    if(my_stack->position == -1 || my_stack == NULL) return "\0";
    return my_stack->stack[(my_stack->position)--];

}

char peek(StackP my_stack){
    if(my_stack->position == -1) return '\0';
    return my_stack->stack[my_stack->position];

}

int isEmpty(StackP my_stack){
    if(my_stack->position == -1){
        return 0;//stack is empty;
    }
    else return 1;//stack is not empty

}