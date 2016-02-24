#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //string
#include <time.h> //time

typedef struct queueNode
{
	int customerNumber; /*Unique identifier; starts at 1; after 24 hours
						should be reset to 1 */
	int serviceTime; //random time; varies between express and normal

	int totalTime; /* totalTime = serviceTime + sum of serviceTimes of customers
					in line before this customer; units in minutes*/

	struct queueNode *pNext;
}Node; //alt name for "struct queueNode"

typedef struct queue
{
	Node * pHead; //Node pointers to head & tail
	Node * pTail;
}Queue;

Node *makeNode(int customerNumber, int serviceTime);

int enqueue(Node *pQ, int customerNumber, int serviceTime);

void dequeue(Node *pQ, int customerNumber, int serviceTime);

int isEmpty(Queue q);

void printQueue();

#endif