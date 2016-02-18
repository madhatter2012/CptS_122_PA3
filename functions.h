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
}QueueNode; //alt name for "struct queueNode"

typedef struct queue
{
	QueueNode *pHead; //QueueNode pointers to head & tail
	QueueNode *pTail;
}Queue;

QueueNode *makeNode(int customerNumber, int serviceTime);

int enqueue(Queue *pQ, int customerNumber, int serviceTime);

void dequeue(Queue *pQ, int customerNumber, int serviceTime);

int isEmpty(Queue q);

void printQueue();

#endif