#include <pthread.h>
#include <stdio.h>


int arr1[10] = {5, 3, 8, 0, 5, 2, 3, 0, 3, 5};
int arr2[10] = {10, 15, 3, 5, 7, 3, 11, 12, 0, 5};
int arr3[10];

void *PrintHello(void *threadid)
{
	int index = threadid;
	int total = arr1[index];
	total += arr2[index];
	arr3[index] = total;
	pthread_exit(NULL);
}


int main()
{
	clock_t start, end;
    double cpu_time_used;
    start = clock();
	pthread_t threads[10];
	int rc;
	int t;
	for(t=0; t<10; t++)
	{
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		pthread_join(threads[t], NULL );
		printf("%d: %d \n", t, arr3[t]);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", cpu_time_used );
	return 0;
}