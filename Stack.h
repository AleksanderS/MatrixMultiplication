/************************
 * Stack.h
 * Alex Lindemann
 * 11/25/2015
 * Matrix Multiplication.
 ************************/

#ifndef MATRIXMULTIPLICATION_STACK_H
#define MATRIXMULTIPLICATION_STACK_H



typedef struct Stack {

    char stack[100];
    int position;

} *StackP;


StackP newStack();
void push(StackP, char);
char pop(StackP);
char peek(StackP);

int isEmpty(StackP);



#endif //MATRIXMULTIPLICATION_STACK_H
