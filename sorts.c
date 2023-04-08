#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define N 3000
int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
void bubble_sort(int vetor[], int n)
{
	int k, j, aux;
	for (k = 1; k < n; k += 1)
	{

		for (j = 0; j < n - 1; j += 1)
		{

			if (vetor[j] > vetor[j + 1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}
void insertionSort(int vetor[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i += 1)
	{
		key = vetor[i];
		j = i - 1;
		while (j >= 0 && vetor[j] > key)
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = key;
	}
}
void merge(int vetor[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i += 1)
		L[i] = vetor[l + i];
	for (j = 0; j < n2; j += 1)
		R[j] = vetor[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vetor[k] = L[i];
			i += 1;
		}
		else
		{
			vetor[k] = R[j];
			j += 1;
		}
		k += 1;
	}

	while (i < n1)
	{
		vetor[k] = L[i];
		i += 1;
		k += 1;
	}

	while (j < n2)
	{
		vetor[k] = R[j];
		j += 1;
		k += 1;
	}
}
void mergeSort(int vetor[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(vetor, l, m);
		mergeSort(vetor, m + 1, r);

		merge(vetor, l, m, r);
	}
}
void troca(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int vetor[], int n, int i)
{
	int maior = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && vetor[l] > vetor[maior])
		maior = l;

	if (r < n && vetor[r] > vetor[maior])
		maior = r;

	if (maior != i)
	{
		troca(&vetor[i], &vetor[maior]);
		heapify(vetor, n, maior);
	}
}
void heapSort(int vetor[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(vetor, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		troca(&vetor[0], &vetor[i]);

		heapify(vetor, i, 0);
	}
}
int binarySearch(int vetor[], int l, int r, int x)
{
	if (r >= l)
	{
		int meio = l + (r - l) / 2;

		if (vetor[meio] == x)
			return meio;

		if (vetor[meio] > x)
			return binarySearch(vetor, l, meio - 1, x);

		return binarySearch(vetor, meio + 1, r, x);
	}

	return -1;
}
int buscaSequencial(int vet[], int n, int chave)
{
	for (int i = 0; i < n; i += 1)
	{
		if (vet[i] == chave)
			return i;
	}
	return -1;
}
int main()
{
	FILE *f, *f2, *f3;
	f = fopen("bubbleSort.txt", "w+");
	for (int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime;
		unsigned long usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for (int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		bubble_sort(v, n);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f, "%lu%03lu\n",msecDiff, usecDiff % 1000);
	}
	fclose(f);
	f = fopen("insertionSort.txt", "w+");
	for (int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime;
		unsigned long usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for (int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		insertionSort(v, n);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f, "%lu%03lu\n",msecDiff, usecDiff % 1000);
	}
	fclose(f);
	f = fopen("quickSort.txt", "w+");
	f2 = fopen("buscaBinaria.txt", "w+");
	f3 = fopen("buscaSequencial.txt", "w+");
	for (int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime;
		unsigned long usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for (int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		qsort(v, n, sizeof(int), cmp);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f, "%lu%03lu\n",msecDiff, usecDiff % 1000);
		gettimeofday(&startTime, NULL);
		binarySearch(v, 0, n - 1, v[n] / 3);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f2, "%lu%03lu\n",msecDiff, usecDiff % 1000);
		gettimeofday(&startTime, NULL);
		buscaSequencial(v, n, v[n] / 3);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f3, "%lu%03lu\n",msecDiff, usecDiff % 1000);
	}
	fclose(f);
	fclose(f2);
	fclose(f3);
	f = fopen("mergeSort.txt", "w+");
	for (int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime;
		unsigned long usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for (int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		mergeSort(v, 0, n - 1);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f, "%lu%03lu\n",msecDiff, usecDiff % 1000);
	}
	fclose(f);
	f = fopen("heapSort.txt", "w+");
	for (int n = 0; n < N; n += 1)
	{
		int v[n];
		struct timeval startTime, endTime;
		unsigned long usecDiff, msecDiff, time_diff;
		srandom(time(NULL));
		for (int i = 0; i < n; i += 1)
		{
			v[i] = random();
		}
		gettimeofday(&startTime, NULL);
		heapSort(v, n);
		gettimeofday(&endTime, NULL);
		/* calcula a diferenca entre os tempos, em usec */
		time_diff = (1000000L * endTime.tv_sec + endTime.tv_usec) -
					(1000000L * startTime.tv_sec + startTime.tv_usec);
		/* converte para segundos + microsegundos (parte fracion�ria) */

		usecDiff = time_diff % 1000000L;

		/* converte para msec */
		msecDiff = time_diff / 1000;
		fprintf(f, "%lu%03lu\n",msecDiff, usecDiff % 1000);
	}
	fclose(f);
	return 0;
}
