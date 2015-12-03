/************************
 * Queue.h
 * Alex Lindemann
 * 11/25/2015
 * Matrix Multiplication.
 ************************/

#ifndef MATRIXMULTIPLICATION_QUEUE_H
#define MATRIXMULTIPLICATION_QUEUE_H




typedef struct char_item{

    char item;
    struct char_item *next_item;

} *char_itemP;


typedef struct Queue {

    struct char_item *head;
    struct char_item *tail;
    int size;

} *QueueP;

QueueP newQueue();

void enqueue(QueueP, char);


#endif //MATRIXMULTIPLICATION_QUEUE_H
