#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int charToInt(char* val)
{
	int count = 0;
	while(*(val) != '\0')
	{
		
		val += 1;
		count += 1;
	}
	val -= 1;
	int num = 0;
	int multiply = 1;
	for (int i = 0; i < count; i++)
	{
		num += (*val-48) * multiply;
		multiply *= 10;
		val -= 1;
	}
	return num;
}


int main(int agrc, char** argv)
{

	clock_t start, end;
    double time_taken;
	start = clock();
	int STEPS = charToInt(argv[1]); // Number of Steps int i, count = 0;
	FILE *fptr1, *fptr2, *fptr3;
    fptr1 = fopen("timesteps.txt","a");
    fptr3 = fopen("steps.txt","a");
    fptr2 = fopen("pi.txt","a");
	double x, y, z, pi;
	int count;
	for (int i = 0; i <= STEPS; i++)
	{
		x = rand()/(double)RAND_MAX;
		y = rand()/(double)RAND_MAX;
		z = x*x + y*y;
		if (z <= 1)
			count++;
	}
	pi = (double)count/STEPS*4;

	fprintf(fptr1,"%d", STEPS);
	fprintf(fptr3,"%d", STEPS);
	fprintf(fptr2,"%f", pi);
	// printf("N = %d\t", STEPS);
	// printf("Pi = %.20f\n", pi);
	fprintf(fptr2,"%s", "	\n");
	fprintf(fptr3,"%s", "	\n");
	end = clock();
	time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("%f\n",time_taken);
	fprintf(fptr1,"%s", "		");
	fprintf(fptr1,"%f", time_taken);
	fprintf(fptr1,"%s", "	\n");
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}