
//Grocery Store Simulation by Cornell Michael Smith
//Cpts 122 Spring 2016 of the year of our lord


#include "functions.h"

int main(void)
{
	srand(time(NULL)); //seeding rand() with time


	int customerNumber = 0; // customer number
	int expressTime_A = rand() % 5 + 1; // range 1-5
	int normalTime_A = rand() % 6 + 3; // range 3-8
	int expressTime_S = rand() % 5 + 1; //service time
	int normalTime_S = rand() % 6 + 3;
	int totalTime = 0; //total time elapsed variable
	int serviceTime = 0; //time for service
	int normalService = 0;
	int expressService = 0;
	int n = 0;//user input runtime

	Queue express = { NULL, NULL }; //Initializing Queue pointers
	Queue normal = { NULL, NULL };

	printf("Enter runtime: "); //prompting & accepting runtime request
	scanf("%d\n", n);

	while (n != totalTime)
	{
		
		
		
		
		expressTime_A--; //decrementing express time

		if (expressTime_A == 0)
		{
			printf("At %d minutes Customer %d arrived in the express line.\n", totalTime, customerNumber);
			
			expressTime_A = rand() % 5 + 1; // range 1-5

			expressService = rand() % 5 + 1; //range 1-5
			serviceTime;

			customerNumber++;
		}

		if (expressService == 0)
		{
			printf("At %d minutes Customer %d left the express lane with a wait time of %d minutes.\n", totalTime, customerNumber, serviceTime);
		}
		
		expressService--; //decrementing express service time
		
		normalTime_A--; //decrementing normal time

		if (normalTime_A == 0)
		{
			normalTime_A = rand() % 6 + 3; // range 3-8
			printf("At %d minutes Customer %d arrived in the normal line.\n", totalTime, customerNumber);

			normalService = rand() % 6 + 3; //range 1-5

			customerNumber++;
		}

		if (normalService == 0)
		{
			printf("At %d minutes Customer %d left the normal lane with a wait time of %d minutes.\n", totalTime, customerNumber, serviceTime);
		}
		
		totalTime++; //incrementing total time +1
	} 

	return 0;
}