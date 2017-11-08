/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 10763 de UVA
 * Fecha: 29/octubre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>
#include <stdlib.h>


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place*/
        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n,i,flag=1;
    int *a,*b;
    a = malloc (sizeof(int) * 500000);
    b = malloc (sizeof(int) * 500000);
    while(1){
        scanf("%i",&n);
        flag=1;

        if(n==0){
            free(a);
            free(b);
            return 0;
        }
        for(i=0;i<n;i++){
            scanf("%i %i",&a[i],&b[i]);
        }
        quickSort(a,0,n);
        quickSort(b,0,n);
        for(i=0;i<n;i++){
            if(a[i]!=b[i]){
                printf("NO\n");
                flag=0;
                break;
            }
        }
        if(flag)
            printf("YES\n");

    }
    free(a);
    free(b);
    return 0;

}
