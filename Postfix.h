//
// Created by Alex on 11/26/2015.
//

#ifndef MATRIXMULTIPLICATION_POSTFIX_H
#define MATRIXMULTIPLICATION_POSTFIX_H

#include "Queue.h"



QueueP toPostfix(char *);
int getPriority(char);
void removeSpaces(char *);
void printNewExpression(QueueP);


#endif //MATRIXMULTIPLICATION_POSTFIX_H
