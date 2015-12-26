//
// Created by Alex on 12/6/2015.
//

#include <stdlib.h>
#include "Multiply.h"


MatrixP multiplyMatrices(MatrixP A, MatrixP B) {
    MatrixP tmp = malloc(sizeof(struct Matrix));
    tmp->height = A->height;
    tmp->width = B->width;

    int i;
    int j;
    int k;
    long sum = 0;
    for (i = 1; i <= A->height; i++)
        for (j = 1; j <= B->width; j++) {
            sum = 0;
            for (k = 1; k <= A->width; k++) {
                sum += sum + (A->matrix[i][k] * B->matrix[k][j]);
            }
            tmp->matrix[i][j] = sum;
        }

    return tmp;
}

