//
// Created by Alex on 11/28/2015.
//

#include "FileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include "Integer.h"

IntegerQueueP getMatrixDimensions(){
    FILE *in = fopen("MatrixDimensions.txt", "r");
    IntegerQueueP tmp_queue = newIntegerQueue();
    if(in == NULL){
        fprintf(stderr, "file not found!\n");
        return NULL;
    }
    int tmp;

    while(fscanf(in, "%i", &tmp) == 1){
        IntegerP tmp_integer = newInteger(tmp);
        insertIntegerQueue(tmp_queue, tmp_integer);
    }

    fclose(in);
    return tmp_queue;
}


