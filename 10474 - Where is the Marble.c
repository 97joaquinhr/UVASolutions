/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 10474 de UVA
 * Fecha: 3/septiembre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>


void search(int n,int a[n],int q){
    int i,j,aux,flag;
    for(i=0;i<q;i++){
        scanf("%i",&aux);
        flag=0;
        for(j=0;j<n;j++){
            if(aux==a[j]){
                printf("%i found at %i\n",aux,j+1);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("%i not found\n",aux);
    }
}
void swap(int n,int a[n],int i,int aux){
    int temp;
    temp=a[i];
    a[i]=aux;
    a[i+1]=temp;

}
int main(){
    int cont=1;
    while(1){
        int n,q;
        scanf("%i %i",&n,&q);
        if(n==0 && q==0)
            break;
        else{
            int a[n],i,aux,j;
            scanf("%i",&a[0]);
            for(i=1;i<n;i++){
                scanf("%i",&aux);
                if(a[i-1]>aux){
                    j=i;
                    while(a[j-1]>aux){
                        swap(n,a,j-1,aux);
                        if(j>1)
                            j--;
                    }
                }
                else{
                    a[i]=aux;
                }
            }

            printf("CASE# %i:\n",cont);
            search(n,a,q);

        }
        cont++;

    }
    return 0;

}
