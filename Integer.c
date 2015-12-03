//
// Created by Alex on 11/28/2015.
//

#include "Integer.h"
#include <stdio.h>
#include <stdlib.h>

IntegerQueueP newIntegerQueue(){
    IntegerQueueP tmp = malloc(sizeof(struct IntegerQueue));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->size = 0;
    return tmp;

}
IntegerP newInteger(int num){
    IntegerP tmp = malloc(sizeof(struct Integer));
    tmp->num = num;
    tmp->next = NULL;
}

void insertIntegerQueue(IntegerQueueP queue, IntegerP integer){
    if(NULL == queue){
        fprintf(stderr, "No Integer Queue allocated!\n");
        return;
    }
    if(NULL == integer){
        fprintf(stderr, "No Integer allocated!\n");
        return;
    }

    if(NULL == queue->head && NULL == queue->tail){
        queue->head = queue->tail = integer;
        queue->size += 1;
        return;
    }
    else {
        queue->tail->next = integer;
        queue->tail = queue->tail->next;
        queue->size += 1;
        return;
    }
}
IntegerP removeIntegerQueue(IntegerQueueP queue){
    if(NULL == queue){
        fprintf(stderr, "No Integer Queue Allocated! Cannot dequeue!\n");
        return NULL;
    }
    if(NULL == queue->head){
        fprintf(stderr, "No Integer Item Allocated! Cannot dequeue!\n");
        return NULL;
    }
    IntegerP tmp = queue->head;
    queue->head = queue->head->next;
    queue->size -= 1;
    tmp->next = NULL;
    return tmp;
}

int getIntegerQueueSize(IntegerQueueP queue) {
    if (NULL == queue) {
        fprintf(stderr, "No Integer Queue allocated. Cannot get size!\n");
        return -1;
    }
    return queue->size;
}

int * integerQueueToArray(IntegerQueueP queue){
    int *tmp = malloc(sizeof(int)*getIntegerQueueSize(queue));
    int i;
    int j = queue->size;
    for(i = 0; i < j; i++){
        IntegerP tmp_integer = removeIntegerQueue(queue);
        tmp[i] = tmp_integer->num;
        free(tmp_integer);
    }
    free(queue);
    return tmp;
}

