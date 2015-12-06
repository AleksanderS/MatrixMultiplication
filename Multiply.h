//
// Created by Alex on 12/6/2015.
//

#ifndef MATRIXMULTIPLICATION_MULTIPLY_H
#define MATRIXMULTIPLICATION_MULTIPLY_H

typedef struct Matrix {

    int matrix[200][200];
    int width;
    int height;

} *MatrixP;

MatrixP multiplyMatrices(MatrixP , MatrixP );

#endif //MATRIXMULTIPLICATION_MULTIPLY_H
