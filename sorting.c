#include "sorting.h"
#include <stdlib.h>

//pega o maior valor da tabela para determinar o maior expoente
static int getMax(int arr[], int n)
{
	int max = arr[0];

	for(int i = 1; i < n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

// exp é o expoente que está sendo verificado atualmente	
static void countSort(int arr[], int n, int exp)
{
	int *output = (malloc(sizeof(int) * n));//array do tamanho da tabela
	int i, count[10] = {0};					//10 porque é base 10!

	for(i = 0; i < n; i++)					//para cada elemento da tabela	
	{
		count[ (arr[i] / exp) % 10 ]++;		//incrementa a quantidade de elementos com tal expoente no array count
	}

	for(i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];			//acumula valores
	}

	for(i = n - 1; i >= 0; i--)				//constroi o array final(do expoente atual)	
	{
		output[ count [ (arr[i] / exp) % 10 ] - 1] = arr[i];
		count [ (arr[i] / exp) % 10 ]--;
	}

	for(i = 0; i < n; i++)					//copia output para array
	{
		arr[i] = output[i];
	}
}

//Radix Sort principal
void radixSort(int arr[], int n)
{
	int max = getMax(arr, n);				//acha maior valor

	for(int exp = 1; max/exp > 0; exp *= 10)//chama o sorting para aquele expoente, depois tenta ir para o próximo
	{
		countSort(arr, n, exp);
	}
}

//Counting Sort
void countingSort(int arr[], int n)
{
	int max = getMax(arr, n);				//valor máximo da tabela

	int *output = malloc(sizeof(int) * n);	//array do tamanho da tabela
	int *count = malloc(sizeof(int) * (1+max));//array que conta o número de vees que cada número aparece
	memset(count, 0, sizeof(count));
	int i;									

	for(i = 0; i < n; i++)					//para cada elemento da tabela	
	{
		count[ arr[i] ]++;					//incrementa a quantidade de elementos com tal expoente no array count
	}

	for(i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];			//acumula valores
	}

	for(i = 0; i < n; i++)					//constroi o array final	
	{
		output[ count [ arr[i] ] - 1] = arr[i];
		count [ arr[i] ]--;
	}

	for(i = 0; i < n; i++)					//copia output para array
	{
		arr[i] = output[i];
	}
}