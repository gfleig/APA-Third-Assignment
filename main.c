#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

#define AR_SIZE 20

int scrambled[AR_SIZE] = { 20, 8, 1, 9, 18, 15, 7, 11, 6, 3,
12, 4, 2, 10, 19, 5, 13, 16, 14, 17};

void printArray(int ar[], int n)
{
    printf("[");
    int i;
    for( i = 0; i < n; i++)
    {
        if( i == n - 1)
        {
            printf("%d", ar[i]);
            continue;
        }
        printf("%4d, ", ar[i]);
    }
    printf("]\n");
}

int main()
{    
    int txtElements;        //número de elementos no arquivo          
    int index;              //índice do array desordenado
    
    FILE *stream; 
    stream = fopen("couting.txt", "r");     

    fscanf(stream, "%d", &txtElements); //lê primeiro elemento inteiro do arquivo

    int *table = malloc(sizeof(int) * txtElements); //cria lista dos elementos desoldenados

    for(index = 0; index < txtElements; index++)
    {         
        fscanf(stream, "%d", &table[index]);        //coloca os elementos na lista, desordenadamente
    }
    
    clock_t begin, end;     //variável do tempo inicial e final
    double timeSpent;
    int choice;             //variável de escolha de algoritmo

    printf(",.~* Welcome to Gabriel Fleig's Single Source File Sorting Realm! *~., \n\n");
    printf("Choose the sorting method to be used:\n\t1)Radix Sort\n\t2)Counting Sort\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:            
            //printArray(table, txtElements);
            begin = clock();

            radixSort(table, txtElements);

            end = clock();
            timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
            
            printArray(table, txtElements);

            printf("Tempo gasto: %5.1f microssegundos\n", 1000000 * timeSpent);

            break;
        case 2:
            //printArray(table, txtElements);
            begin = clock();

            countingSort(table, txtElements);

            end = clock();
            timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

            printArray(table, txtElements);

            printf("Tempo gasto: %5.1f microssegundos\n", 1000000 * timeSpent);

            break;        
        default:
            printf("\nI wonder if Fleig actually implemented separated \nsorting methods or this is just a pretty facade.\n\n");
            break;
    }

    fclose(stream);

    return 0;
}
