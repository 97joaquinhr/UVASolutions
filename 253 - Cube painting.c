/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 253 de UVA
 * Fecha: 19/agosto/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>


int sum(int c[6]){
    int sum=0,i;
    for(i=0;i<6;i++){
            sum+=c[i];
    }
    return sum;

}


int main(){
    char k[12];
    int a[12];
    int b[6];
    int i,j;
    while (scanf("%s",&k)!= EOF)
    {

        for(i=0;i<12;i++){
            a[i]=k[i];
        }
        b[0]=a[0]+a[5];
        b[1]=a[1]+a[4];
        b[2]=a[2]+a[3];
        b[3]=a[6]+a[11];
        b[4]=a[7]+a[10];
        b[5]=a[8]+a[9];
        for(j=0;j<3;j++){
            for(i=3;i<6;i++){
                if(b[j]==b[i]){
                    b[j]=0;
                    b[i]=0;
                }

            }
        }

        if(sum(b)==0)
            printf("TRUE");
        else
            printf("FALSE");
        printf("\n");
    }
    return 0;


}
