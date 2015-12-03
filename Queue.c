/************************
 * Queue.c
 * Alex Lindemann
 * 11/25/2015
 * Matrix Multiplication.
 ************************/

#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

QueueP newQueue(){
    QueueP tmp = malloc(sizeof(struct Queue));

    tmp->tail = NULL;
    tmp->head = NULL;
    tmp->size = 0;
    return tmp;

}

void enqueue(QueueP my_queue, char tmp){

    char_itemP item = malloc(sizeof(struct char_item));
    item->item = tmp;
    item->next_item = NULL;

    if(NULL == my_queue){
        fprintf(stderr, "No Queue Allocated! Cannot enqueue!\n");
        return;
    }
    if(NULL == item){
        fprintf(stderr, "No Item Allocated! Cannot enqueue!\n");
        return;
    }
    if(NULL == my_queue->head && NULL == my_queue->tail){
        my_queue->head = my_queue->tail = item;

        my_queue->size++;
        return;
    }
    else {
        my_queue->tail->next_item = item;
        my_queue->tail = item;

        my_queue->size++;
        return;
    }
    return;
}

char_itemP dequeue(QueueP my_queue){
    if(NULL == my_queue){
        fprintf(stderr, "No Queue Allocated! Cannot dequeue!\n");
        return NULL;
    }
    if(NULL == my_queue->head){
        fprintf(stderr, "No Item Allocated! Cannot dequeue!\n");
        return NULL;
    }
    my_queue->size--;
    char_itemP tmp = my_queue->head;
    my_queue->head = my_queue->head->next_item;
    return tmp;
}
