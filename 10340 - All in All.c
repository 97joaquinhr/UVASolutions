/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 10340 de UVA
 * Fecha: 25/octubre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>
#include <string.h>
#define si 100000

void clearS(char str[si]){
    int i=0;
    while(str[i]!='\0'){
        str[i]='\0';
        i++;
    }

}
int main(){

    char s[si],t[si];
    int i,j,maxI,maxJ;
    while (scanf("%s %s",s,t)==2){
        i=0;
        j=0;
        maxI=strlen(s);
        maxJ=strlen(t);
        while(i<maxI && j<maxJ){
            if(s[i]==t[j]){
                i++;
            }
            j++;

        }
        if(i==maxI)
            printf("Yes");
        else
            printf("No");
        printf("\n");
        scanf("%*c");
        clearS(s);
        clearS(t);
    }
    return 0;
}

