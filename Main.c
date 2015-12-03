/************************
 * Main.c
 * Alex Lindemann
 * 11/25/2015
 * Matrix Multiplication.
 ************************/

#include "Queue.h"
#include "Postfix.h"
#include "Integer.h"
#include "FileIO.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Matrix {

    int matrix[200][200];
    int width;
    int height;

} *MatrixP;

void printOptimalParens(MatrixP, int , int, char *, int * );

int main(){
/*
    char expression[50] = "(A + B) / (C + D)";
    QueueP postfix1 = toPostfix(expression);
    printNewExpression(postfix1);
*/

    IntegerQueueP matrixDimensionsTmp = getMatrixDimensions();
    int matrixDimensionsSize = getIntegerQueueSize(matrixDimensionsTmp);
    int m[matrixDimensionsSize + 1][matrixDimensionsSize + 1];
    int s[matrixDimensionsSize + 1][matrixDimensionsSize + 1];
    MatrixP my_matrix = malloc(sizeof(struct Matrix));
    my_matrix->height =matrixDimensionsSize;
    my_matrix->width = matrixDimensionsSize;
    int *matrixDimensions = integerQueueToArray(matrixDimensionsTmp);
    int i;
    int n = matrixDimensionsSize - 1;
    for(i = 1; i <= n; i++)
        m[i][i] = 0;
    int L;
    for(L = 2; L <= n; L++){
        for(i = 1; i <= n - L + 1; i++){
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            int k;
            for(k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k+1][j] + matrixDimensions[i-1] * matrixDimensions[k] * matrixDimensions[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    int j;
    for(i = 0; i < matrixDimensionsSize ; i++)
        for(j = 0; j < matrixDimensionsSize ; j++)
            my_matrix->matrix[i][j] = s[i][j];
    char parensString[500];
    int p = 0;
    printOptimalParens(my_matrix, 1, matrixDimensionsSize - 1, parensString, &p);
    parensString[p] = '\0';
    printf("\n");
    QueueP postfix = toPostfix(parensString);
    printNewExpression(postfix);
    return 0;
}

void printOptimalParens(MatrixP matrix, int i, int j, char *string, int *p){
    if(i == j){
        fprintf(stdout, "A%i", i);
        string[(*p)++] = 'A';
        string[(*p)++] = i + '0';
        return;
    }
    else {
        fprintf(stdout, "(");
        string[(*p)++] = '(';
        printOptimalParens(matrix, i, matrix->matrix[i][j], string, p);
        fprintf(stdout, "*");
        string[(*p)++] = '*';
        printOptimalParens(matrix, matrix->matrix[i][j] + 1, j, string, p);
        fprintf(stdout, ")");
        string[(*p)++] = ')';
        return;
    }
}



