#include "Time.h"

#define NUM_TIMES 5

int main()
{
	Time t1, t2;
	Time times[NUM_TIMES];
	int incr_secs, diff_sec;
	scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	t2 = t1;
	printf("Input time t1 = ");
	printTime(&t1);
	printf("input seconds to increment : ");
	scanf("%d", &incr_secs);
	incrementTime(&t2, incr_secs);
	printf("After incrementing %d secs, t2 = ", incr_secs);
	printTime(&t2);
	diff_sec = compareTime(&t1, &t2);
	printf("Difference between t1 and t2 is %d secs\n", diff_sec);
	times[0] = { 23, 59, 59 };
	times[1] = { 9, 0, 5 };
	times[2] = { 13, 30, 0 };
	times[3] = { 3, 59, 59 };
	times[4] = { 0, 0, 0 };

	printf("\nBefore sorting times : \n");
	for (int i = 0; i < NUM_TIMES; i++)
	{
		printf("times[%d] = ", i); printTime(&times[i]);
	}
	selectSortTime(times, NUM_TIMES);
	
	printf("After selection sorting of times : \n");
	for (int i = 0; i < NUM_TIMES; i++)
	{
		printf("times[%d] = ", i); printTime(&times[i]);
	}
}