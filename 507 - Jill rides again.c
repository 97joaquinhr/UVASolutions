/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 507 de UVA
 * Fecha: 19/noviembre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

int maxi(int a, int b){
    if(a<=b)
        return b;
    else
        return a;
}
int main(){
    int b,r,res,i,cont=1,temp;
    int sum=0,ans=0,inicio=1,fin=0,maxInicio;
    scanf("%i",&b);
    while(b){
        scanf("%i",&r);
        r--;
        for(i=0;i<r;i++){
            scanf("%i",&temp);
            sum+=temp;
            if(ans<sum||(sum==ans&&(fin-maxInicio<i-inicio))){
                ans=sum;
                maxInicio=inicio;
                fin=i+1;
            }
            if(sum<0){
                sum=0;
                inicio=i+2;
            }
        }
        if(ans<=0){
            printf("Route %i has no nice parts\n",cont);
        }
        else{
            fin++;
            printf("The nicest part of route %i is between stops %i and %i\n",cont,maxInicio,fin);
        }
        maxInicio=0;
        inicio=1;
        fin=0;
        ans=0;
        sum=0;
        cont++;
        b--;
    }
    return 0;
}

