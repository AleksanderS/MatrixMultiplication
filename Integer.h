//
// Created by Alex on 11/28/2015.
//

#ifndef MATRIXMULTIPLICATION_INTEGER_H
#define MATRIXMULTIPLICATION_INTEGER_H


typedef struct Integer {
    int num;
    struct Integer * next;
} *IntegerP;

typedef struct IntegerQueue{
    IntegerP head;
    IntegerP tail;
    int size;
} *IntegerQueueP;

IntegerQueueP newIntegerQueue();
IntegerP newInteger(int);

void insertIntegerQueue(IntegerQueueP, IntegerP);
IntegerP removeIntegerQueue(IntegerQueueP);

int getIntegerQueueSize(IntegerQueueP);
int * integerQueueToArray(IntegerQueueP);

#endif //MATRIXMULTIPLICATION_INTEGER_H
