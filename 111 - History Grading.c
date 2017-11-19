/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 111 de UVA
 * Fecha: 18/noviembre/2017
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

int LCS(int n,int a[n],int b[n]){
    int mat[25][25]={};
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
                mat[i][j]=maxi(mat[i-1][j],mat[i][j-1]);
        }

    }
    return mat[n][n];

}

int main(){
    int x;
    char c;
    int n,i,a[20],b[20];
    scanf("%i",&n);
    while(1){
        for(i=0;i<n;i++){
            scanf("%d", &x);
            x--;
            a[x] = i;

        }
        while(1){
            for(i=0;i<n;i++){
                if(scanf("%i%c",&x,&c)==EOF){
                    return 0;
                }
                x--;
                b[x]=i;
                if(c=='\n'&&i<2){
                    n=b[i];
                    break;
                }
            }
            if(i<2)
                break;
            else{
                printf("%i\n",LCS(n,a,b));
            }
        }

    }

}
