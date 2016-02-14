#include "functions.h"



QueueNode * makeNode(int customerNumber, int serviceTime)
{
	QueueNode *pMem = (QueueNode *)malloc(sizeof(Queue));

	if (pMem != NULL)
	{
		pMem->customerNumber = customerNumber;
		pMem->serviceTime = serviceTime;
		pMem->pNext = NULL;
	}

	return pMem;
}

isEmpty(Queue q)
{
	return (q.pHead == NULL);
}

int enqueue(Queue *pQ, int customerNumber, int serviceTime)
{
	QueueNode *pMem = makeNode(customerNumber, serviceTime);

	int success = 0;

	if (pMem != NULL)
	{
		//successful memory allocation
		success = 1;
		
		if (pQ->pHead != NULL)
		{
			//queue is not empty
			pQ->pTail->pNext = pMem;
			pQ->pTail = pMem;
		}
		else
		{
			//queue is empty
			pQ->pHead = pQ->pTail = pMem;
		}
	}
	return success;

}

void dequeue(Queue *pQ, int *customerNumber, int *serviceTime)
{
	QueueNode *pCur = pQ->pHead; //pCur = mem address of node 1
	*customerNumber = pCur->customerNumber;
	*serviceTime = pCur->serviceTime;
	
	//only one node
	if (pQ->pHead == pQ->pTail)
	{
		pQ->pHead = pQ->pTail = NULL;
	}
	else
	{
		//more than one node in queue
		pQ->pHead = pQ->pHead->pNext; //setting the pHead pointer to pNext, before removing node 1
	}

	customerNumber = pCur->customerNumber;
	serviceTime = pCur->serviceTime;
	free(pCur);

	 //returning pCur-data
}


