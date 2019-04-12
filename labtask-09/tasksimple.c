#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start, end;
    double cpu_time_used;
    start = clock();
	int t;
	int arr1[10] = {5, 3, 8, 0, 5, 2, 3, 0, 3, 5};
	int arr2[10] = {10, 15, 3, 5, 7, 3, 11, 12, 0, 5};
	int arr3[10];
	for(t=0; t<10; t++)
	{
		arr3[t] = arr1[t] + arr2[t];
		printf("%d : %d \n", t, arr3[t] );
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", cpu_time_used );
	return 0;
}