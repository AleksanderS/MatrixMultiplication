//
// Created by Alex on 11/26/2015.
//
#include <stdio.h>
#include "Postfix.h"
#include "Stack.h"
#include <ctype.h>




QueueP toPostfix(char *expression){
    removeSpaces(expression);
    StackP stack = newStack();
    QueueP queue = newQueue();

    int i = 0;
    char item;
    while(expression[i] != '\0'){

        if((int)expression[i] >= 48 && (int) expression[i] <=57  ){
            enqueue(queue, expression[i]);
            i++;
        }
        else if(isalpha(expression[i])){
            enqueue(queue, expression[i]);
            i++;
        }

        else if(expression[i] == '('){
            push(stack, expression[i]);
            i++;
        }
        else if(expression[i] == ')'){
            while(stack->stack[stack->position] != '('){
                enqueue(queue, pop(stack));
            }
            pop(stack);
            i++;
        }
        else {
            while ((getPriority(expression[i]) <= getPriority(peek(stack)) && stack->position != -1)) {
                item = pop(stack);
                enqueue(queue, item);
            }
            push(stack, expression[i]);
            i++;
        }
    }
    while(isEmpty(stack) == 1){
        item = pop(stack);
        enqueue(queue, item);
    }
    return queue;
}

int getPriority( char item){
    if(item == '+' || item == '-') return 1;
    if(item == '*' || item == '/') return 2;
    return 0;
}

void removeSpaces(char* source)
{
    char* i = source;
    char* j = source;
    while(*j != 0)
    {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}

void printNewExpression(QueueP expression){
    int i = 0;
    char_itemP tmp = expression->head;
    while(i < expression->size){
        printf("%c", tmp->item);
        tmp = tmp->next_item;
        i++;
    }

}
