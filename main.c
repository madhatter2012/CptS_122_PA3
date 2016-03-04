
//Grocery Store Simulation by Cornell Michael Smith
//Cpts 122 Spring 2016 of the year of our lord


#include "functions.h"

int main(void)
{
	srand((unsigned int)time(NULL)); //seeding rand() with time, CORRECTLY.

	int customerNumber = 0; // customer number
	int expressArrival = rand() % 5 + 1; // range 1-5 arrival time for express lines
	int normalArrival = rand() % 6 + 3; // range 3-8 arrival time for normal line
	int expressService = 0; //service time for express lines.
	int normalService = 0; //service time for normal lines
	//int elapsedTime = 0; //total time elapsed variable
	int expressTotal = 0;
	int normalTotal = 0;
	int totalTime = 0; //totalTime
	int custNum = 0; // variable for customer number that i can use when i don't want to use customer number


	int n = 0;//user input runtime

	Queue express = {NULL, NULL}; //Initializing Queue pointers
	Queue normal = {NULL, NULL};
	Node *pCur = NULL;

	printf("Enter runtime: "); //prompting & accepting runtime request
	scanf("%d", &n);
	printf("Your runtime selection is: %d\n", n);
	printf("If you can see this, good job!\n");

	//enque first 2 cust
	expressService = rand() % 5 + 1; //service time for express lines.
	normalService = rand() % 6 + 3; //service time for normal lines


	//while total time does not equal the user input
	while (n != totalTime)
	{
		//if express arrival time expires enqueue another customer, generate a express service time
		//set new express arrival time for next customer
		if (expressArrival == 0)
		{
			customerNumber++;

			 expressService = rand() % 5 + 1; //service time

			 expressTotal = expressTotal + expressService;
			
			 /*if (express.pHead != NULL)
			 {
				 pCur = express.pHead;

				 while (pCur != NULL)
				 {
					 totalTime = pCur->serviceTime;
					 pCur = pCur->pNext;
				 }

				 totalTime = totalTime + expressService;
			 }*/

			enqueue(&express, customerNumber, expressService, expressTotal);
			printf("At %d minutes Customer %d arrived in the express line.\n", totalTime, customerNumber);
			
			 expressArrival = rand() % 5 + 1; // range 1-5
		}

		//if normal arrival time expires enqueue another customer, generate a normal service time
		//set new normal arrival time for next customer
		if (normalArrival == 0)
		{
			customerNumber++;//incrementing customer number

			normalService = rand() % 6 + 3; //service time for normal lane
			
			normalTotal = normalTotal + normalService;

			enqueue(&normal, customerNumber, normalService, normalTotal);
			printf("At %d minutes Customer %d arrived in the normal line.\n", totalTime, customerNumber);

			normalArrival = rand() % 6 + 3; // range 3-8, arrival time for normal lane
		}
		
		//if express service time expires dequeue express line
		if (express.pHead != NULL)
		{
			if (express.pHead->serviceTime == 0)
			{
				custNum = express.pHead->customerNumber; //<--wtf???

				dequeue(&express, customerNumber, expressService, expressTotal);
				printf("At %d minutes Customer %d left the express line with a service time of %d.\n", totalTime, custNum, expressService);
			}
		}
		//if normal service time expires dequeue normal line
		if (normal.pHead != NULL)
		{
			if (normal.pHead->serviceTime == 0)
			{
				custNum = normal.pHead->customerNumber;

				dequeue(&express, customerNumber, normalService, normalTotal);
				printf("At %d minutes Customer %d left the normal line with a service time of %d .\n", totalTime, custNum, normalService);
			}
		}
	
		//decrementing express & normal service time
		if (express.pHead != NULL)//if some in que then  
		{
			express.pHead->serviceTime--;
				//expressService--;
		}
		if (normal.pHead != NULL)
		{
			normal.pHead->serviceTime--;
		}
		// decrementing express & normal arrival time
		expressArrival--;
		normalArrival--;
		
		// incrementing total time
		totalTime++;


		//printing the queue every 10 minutes
		if (totalTime % 10 == 0)
		{
			printf("Here's the Express Queue: \n");
			if (express.pHead != NULL)
			{
				pCur = express.pHead;

				while (pCur != NULL)
				{
					printf("Customer: %d Total Time: %d\n", pCur->customerNumber, pCur->totalTime);
					pCur = pCur->pNext;
				}
			}
			printf("Here's the Normal Queue: \n");
			if (normal.pHead != NULL)
			{
				pCur = normal.pHead;

				while (pCur != NULL)
				{
					printf("Customer: %d Total Time: %d\n", pCur->customerNumber, pCur->totalTime);
					pCur = pCur->pNext;
				}
			}
		}
	} 

	printf("Runtime of %d minutes ended. Simulation Complete. \n", n);
	return 0;
}