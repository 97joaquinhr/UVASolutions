/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 102 de UVA
 * Fecha: 14/agosto/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
void print(char tr[6][3],int x, int min){
    int f, c;
    for(c=0;c<3;c++){
        printf("%c",tr[x][c]);
    }
    printf(" %i\n", min);
}


int min1(int c[6]){
   int min=2147483647,i;
   for(i=0;i<6;i++){
        if(c[i]<min)
            min=c[i];
    }
    return min;
}

int main(){
    int a[9],i, total=0,c[6],min,best;
    char tr[6][3]={{'B','C','G'},{'B','G','C'},{'C','B','G'},{'C','G','B'},{'G','B','C'},{'G','C','B'}};
    while (scanf("%i",&a[0])!= EOF)
    {

        total+=a[0];
        for(i=1;i<9;i++){
            scanf("%i",&a[i]);
            total+=a[i];
        }

        c[0]=total-a[0]-a[5]-a[7];/*bcg*/
        c[1]=total-a[0]-a[4]-a[8];/*bgc*/
        c[2]=total-a[2]-a[3]-a[7];/*cbg*/
        c[3]=total-a[2]-a[4]-a[6];/*cgb*/
        c[4]=total-a[1]-a[3]-a[8];/*gbc*/
        c[5]=total-a[1]-a[5]-a[6];/*gcb*/

        min=min1(c);

        for(i=0;i<6;i++){
            if(c[i]==min){
                best=i;
                break;
            }
        }

        print(tr,best,c[best]);
        total =0;

    }
    return 0;


}
