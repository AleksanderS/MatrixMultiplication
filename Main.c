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
void populateMandSArray(MatrixP , MatrixP, int, int *);

int main(){
/* TESTING POSTFIX
    char expression[50] = "(A + B) / (C + D)";
    QueueP postfix1 = toPostfix(expression);
    printNewExpression(postfix1);
*/

    IntegerQueueP matrixDimensionsTmp = getMatrixDimensions();
    IntegerP numberOfMatrices = removeIntegerQueue(matrixDimensionsTmp);
    int matrixDimensionsSize = numberOfMatrices->num;
    MatrixP m = malloc(sizeof(struct Matrix));
    MatrixP s = malloc(sizeof(struct Matrix));

    int *matrixDimensions = integerQueueToArray(matrixDimensionsTmp);

    populateMandSArray(m, s, matrixDimensionsSize, matrixDimensions);

    char parensString[500];
    int p = 0;
    printf("1. Computing optimal parenthesization:\n");
    printOptimalParens(s, 1, matrixDimensionsSize, parensString, &p);
    parensString[p] = '\0';
    printf("\n");
    QueueP postfix = toPostfix(parensString);
    printf("2. Infix to postfix:\n");
    printNewExpression(postfix);
    return 0;
}

void printOptimalParens(MatrixP matrix, int i, int j, char *string, int *p){
    if(i == j){
        printf("A%i", i);
        string[(*p)++] = 'A';
        string[(*p)++] = i + '0';
        return;
    }
    printf("(");
    string[(*p)++] = '(';
    printOptimalParens(matrix, i, matrix->matrix[i][j], string, p);
    printf("*");
    string[(*p)++] = '*';
    printOptimalParens(matrix, matrix->matrix[i][j] + 1, j, string, p);
    printf(")");
    string[(*p)++] = ')';
    return;

}

void populateMandSArray(MatrixP m, MatrixP s, int matrixDimensionsSize, int *matrixDimensions){
    int n = matrixDimensionsSize;
    int i;
    for(i = 1; i <= n; i++)
        m->matrix[i][i] = 0;
    int L;
    for(L = 2; L <= n; L++){
        for(i = 1; i <= n - L + 1; i++){
            int j = i + L - 1;
            m->matrix[i][j] = INT_MAX;
            int k;
            for(k = i; k <= j - 1; k++){
                int q = m->matrix[i][k] + m->matrix[k+1][j] + matrixDimensions[i-1] * matrixDimensions[k] * matrixDimensions[j];
                if(q < m->matrix[i][j]){
                    m->matrix[i][j] = q;
                    s->matrix[i][j] = k;
                }
            }
        }
    }
    return;
}



