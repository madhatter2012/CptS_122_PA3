
#include "functions.h"



Node * makeNode(int customerNumber, int serviceTime, int totalTime)
{
	Node *pMem; //creating memory pointer variable
	//typecasting memory to QueueNode memory type
	pMem= (Node *)malloc(sizeof(Queue));

	if (pMem != NULL)
	{
		pMem->customerNumber = customerNumber;
		pMem->serviceTime = serviceTime;
		pMem->totalTime = totalTime;
		pMem->pNext = NULL;
	}

	return pMem;
}

int isEmpty(Queue q)
{
	return (q.pHead == NULL); //return is int because 1 = true, 0 false
}

int enqueue(Queue *pQ, int customerNumber, int serviceTime, int totalTime)
{
	//creating new node
	Node *pMem = makeNode(customerNumber, serviceTime, totalTime);

	int success = 0;

	if (pMem != NULL)
	{
		//successful memory allocation
		success = 1;
		
		if (pQ->pHead != NULL)
		{
			//queue is not empty
			(pQ->pTail)->pNext = pMem;
			pQ->pTail = pMem; //now tail is pointing to new node
		}
		else
		{
			//queue is empty
			pQ->pHead = pQ->pTail = pMem; //if the queue is empty, the only 
										//element in the queue is the new node you just created
		}
	}
	return success;
}

void dequeue(Queue *pQ, int customerNumber, int serviceTime, int totalTime)//changed from * to regular, was this correct?
{
	Node *pCur = pQ->pHead; //pCur = mem address of node 1
	customerNumber = pCur->customerNumber;
	serviceTime = pCur->serviceTime;
	totalTime = pCur->totalTime;
	
	//only one node
	if (pQ->pHead == pQ->pTail)
	{
		pQ->pHead = pQ->pTail = NULL;
	}
	else
	{
		//more than one node in queue
		pQ->pHead = (pQ->pHead)->pNext; //setting the pHead pointer to pNext, before removing node 1
	}

	customerNumber = pCur->customerNumber;
	serviceTime = pCur->serviceTime;
	totalTime = pCur->totalTime;
	free(pCur);
}

void printQueue(Queue *myQueue)
{
	Node *temp = myQueue->pHead; //creating a pointer, temp, pointing to head of queue

	while (temp != NULL) //looping until temp is NULL & queue is ended
	{
	
	//printing by access the temp pointers to structs members
		printf("At %d minutes: \n Normal Lane: Customer %d\n Express Lane: Customer %d\n", temp->totalTime, temp->customerNumber, temp->customerNumber);

	//setting temp to temp->pNext
	temp = temp->pNext; //use a pointer because pNext is outside the function

	}
}