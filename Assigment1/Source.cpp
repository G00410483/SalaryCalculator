//Procedural Programming, Assignment 1
//Name: David Vlasic
//Student number: G00410483

#include<stdio.h>

void main()
{
	int input = 0;
	int hoursWorked;
	float payRate;
	float salary = 0;
	int maxHours = 0;
	int maxInput = 0;
	int overTime = 0;
	int totalOverTime = 0;
	float totalWages = 0;

	while (input != -1)
	{
		printf("Please enter the employee number or -1 to exit:\n");
		scanf("%d", &input);

		if (input != -1)
		{
			printf("Enter the total number of hours employee worked this week:\n");
			scanf("%d", &hoursWorked);

			printf("Enter the employee pay rate:\n");
			scanf("%f", &payRate);

			//Counting the salary and over time hours
			if (hoursWorked <= 39)
			{
				salary = payRate * hoursWorked;
			}
			else if (hoursWorked > 39 && hoursWorked <= 50)
			{
				salary = (payRate * 39) + (1.5 * payRate * (hoursWorked - 39));
				overTime = hoursWorked - 39;
			}
			else if (hoursWorked > 50)
			{
				salary = (payRate * 39) + (2 * payRate * (hoursWorked - 50) + (1.5 * payRate * 11));
				totalOverTime = hoursWorked - 39;
			}
			//Display total weekly salary
			printf("\n\tEmployee number %d has a total weekly salary of: %.2f\n\n\n", input, salary);
			printf("---------------------------------------------------------------------\n");
			
			//Employee with max number of hours  
			if (maxHours < hoursWorked)
			{
				maxHours = hoursWorked;
				maxInput = input;//Saves employee number 
			}
			//Counts total overtime hours and total weekly wages 
			totalOverTime = totalOverTime + overTime;
			totalWages = totalWages + salary;
		}
	}
	//Displays when user input is -1
	printf("\n---------------------------------------------------------------------\n");
	printf("Total company wages for this week: %.2f\n", totalWages);
	printf("Total number of over time hours for this week %d h\n", totalOverTime);
	printf("The employee %d worked most hours this week (%d h)\n", maxInput, maxHours);
	printf("---------------------------------------------------------------------\n");
}