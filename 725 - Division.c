/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 725 de UVA
 * Fecha: 26/agosto/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>

int diferentes(int m, int i){
    char n[10];
    int s[10]={0},j,aux;
    for(j=0;j<10;j++){
        n[j]=(m%10)+'0';
        m=m/10;
        if(j>4){
            n[j]=(i%10)+'0';
            i=i/10;
        }

        if(++s[n[j]-'0']==2)
            return 0;

    }
    return 1;
}

int main(){
    int n,i,m,cont=0,c=0;
    scanf("%i",&n);
    while(n>0){
        i=1234;
        while((i*n)<98765){
            m=i*n;
            if(diferentes(m,i)){
                if(i<9999)
                    printf("%i / 0%i = %i\n",m,i,n);
                else
                    printf("%i / %i = %i\n",m,i,n);
                cont++;
            }
            i++;
        }
        if (cont==0)
            printf("There are no solutions for %i.\n",n);
        cont=0;
        scanf("%i",&n);

        if(n==0)
            return 0;

        printf("\n");
    }
    return 0;



}
