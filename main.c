
//Grocery Store Simulation


#include "functions.h"

int main(void)
{
	srand(time(NULL)); //seeding rand() with time

	int expressTime_A = rand() % 5 + 1; // range 1-5
	int normalTime_A = rand() % 6 + 3; // range 3-8
	int expressTime_S = rand() % 5 + 1; //service time
	int normalTime_S = rand() % 6 + 3;
	int totalTime = 0; //total time elapsed variable
	int n = 0;//user input runtime

	printf("Enter runtime: ");
	scanf("%d\n", n);


//printf("%d \n %d \n", expressTime, normalTime); //test random number gen

	Queue express = { NULL, NULL }; //Initializing Queue pointers
	Queue normal = { NULL, NULL };

	while (n != totalTime)
	{
		expressTime_A--;

		if (expressTime_A == 0)
		{
			expressTime_A = rand() % 5 + 1; // range 1-5
			expressTime_A = rand() % 5 + 1; // range 1-5
		}

		normalTime_A--;
		if (normalTime_A == 0)
		{
			normalTime_A = rand() % 6 + 3; // range 3-8
		}


		int expressTime_S = rand() % 5 + 1;
		int normalTime_S = rand() % 6 + 3;


		n++;


	} 

	return 0;
}