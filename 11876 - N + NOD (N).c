/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 11876 de UVA
 * Fecha: 24/septiembre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
#define SIZE 64726


int countDivisors(int n){
    int i;
    int cnt = 0;
    for (i=1; i<=sqrt(n); i++)
    {
         if (n%i==0)
         {
            if (n/i == i)
               cnt++;

            else
                cnt = cnt+2;
         }
     }
    return cnt;
}
void llenar(int arr[SIZE]){
    int i;
    for(i=1;i<SIZE;i++){
        arr[i]=arr[i-1]+countDivisors(arr[i-1]);
    }
}
void imprimir(int arr[SIZE]){
    int i;
    for(i=0;i<SIZE;i++){
        printf("%i ",arr[i]);
    }
}
int binarySearch(int a[SIZE], int length, int value)
{
    if (a[0] > value)
        return -1;

    int low = 0;
    int high = length-1;

    while (low<=high)
    {
        int mid = low+((high-low)/2);

        if(a[mid] >= value)
            high = mid-1;
        else
            low = mid+1;
    }

    return low;
}

int main(){
    int t,cont=1;
    int max[SIZE],a,b,resa,resb;
    max[0]=1;
    llenar(max);
    scanf("%i",&t);
    while(t>0){
        scanf("%i %i",&a,&b);
        resa=binarySearch(max,SIZE,a);
        resb=binarySearch(max,SIZE,b);
        if(max[resb]==b)
            resb++;
        printf("Case %i: %i",cont,resb-resa);
        cont++;

        printf("\n");
        t--;
    }





    return 0;




}
