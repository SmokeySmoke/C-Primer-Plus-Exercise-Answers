/* Rewrite mall.c (Listing 17.9) so that it simulates a double booth having two queues */
// mall.c -- use the Queue interface
// compile with mall_queue.c
#include <stdio.h>
#include <stdlib.h>	// for rand() and srand()
#include <time.h>	// for time()
#include "mall_queue.h"	// change Item typedef
#define MIN_PER_HR 60.0

bool newcustomer(double x);	// is there a new customer?
Item customertime(long when);	// set customer parameters

int main(void)
{
	Queue line1, line2;
	Item temp;		// new customer data
	int hours;		// hours of simulation
	int perhour;		// average # of arrivals per hour
	long cycle, cyclelimit;	// loop counter, limit
	long turnaways = 0;	// turned away by full queue
	long customers = 0;	// joined the queue
	long servedL1 = 0;	// served in queue 1 during the simulation
	long servedL2 = 0;	// served in queue 2 during the simulation
	long sum_line1 = 0;	// cumulative line1 length
	long sum_line2 = 0;	// cumulative line2 length
	int wait_timeL1 = 0;	// time until booth1 is available
	int wait_timeL2 = 0;	// time until booth2 is available
	double min_per_cust;	// average time between arrivals
	long line1_wait = 0;	// cumulative time in line1
	long line2_wait = 0;	// cumulative time in line2

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int) time(0));	// random initializing of rand()
	puts("Case Study: Sigmund Lander's Advice Booths");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line1) && QueueIsFull(&line2))
				turnaways++;
			else
			{
				customers++;
				temp = customertime(cycle);
				if (QueueItemCount(&line1) < QueueItemCount(&line2))
					EnQueue(temp, &line1);
				else
					EnQueue(temp, &line2);
			}
		}
		if (wait_timeL1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp, &line1);
			wait_timeL1 = temp.processtime;
			line1_wait += cycle - temp.arrive;
			servedL1++;
		}
		if (wait_timeL2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp, &line2);
			wait_timeL2 = temp.processtime;
			line2_wait += cycle - temp.arrive;
			servedL2++;
		}

		if (wait_timeL1 > 0)
			wait_timeL1--;
		if (wait_timeL2 > 0)
			wait_timeL2--;
		sum_line1 += QueueItemCount(&line1);
		sum_line2 += QueueItemCount(&line2);

	}
	double avgQsizeL1 = (double) sum_line1 / cyclelimit;
	double avgQsizeL2 = (double) sum_line2 / cyclelimit;
	double avgWaitTimeL1 = (double) line1_wait / servedL1;
	double avgWaitTimeL2 = (double) line2_wait / servedL2;
	if (customers > 0)
	{
		printf("customers accepted: %ld\n\n", customers);

		printf("customers served in queue 1: %ld\n", servedL1);
		printf("customers served in queue 2: %ld\n", servedL2);
		printf("customers served overall: %ld\n\n", servedL1 + servedL2);

		printf("turnaways: %ld\n\n", turnaways);

		printf("average queue size of queue 1: %.2f\n", avgQsizeL1);
		printf("average queue size of queue 2: %.2f\n", avgQsizeL2);
		printf("average queue size overall: %.2f\n\n", (avgQsizeL1 + avgQsizeL2) / 2);

		printf("average wait time of queue 1: %.2f minutes\n", avgWaitTimeL1);
		printf("average wait time of queue 2: %.2f minutes\n", avgWaitTimeL2);
		printf("average wait time overall:    %.2f minutes\n\n", (avgWaitTimeL1 + avgWaitTimeL2) / 2);
	}
	else
		puts("No customers!");

	EmptyTheQueue(&line1);

	puts("Bye!");

	return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range of 1-3
Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
