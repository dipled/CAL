#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define N 3000
void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {

        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
void insertionSort(int vetor[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}
 
int main()
{
	FILE *f;
	f = fopen("bubbleSort.txt","w+");
	for(int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime; 
		unsigned long secDiff, usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for(int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		bubble_sort(v,n);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
			(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */
		secDiff = time_diff / 1000000L;
		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f,"(%d,%lu.%03lu)\n",n, msecDiff, usecDiff % 1000);
	}
	fclose(f);
	f=fopen("insertionSort.txt","w+");
	for(int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime; 
		unsigned long secDiff, usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for(int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		insertionSort(v,n);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
			(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */
		secDiff = time_diff / 1000000L;
		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f,"(%d,%lu.%03lu)\n",n, msecDiff, usecDiff % 1000);
	}
	fclose(f);
}
