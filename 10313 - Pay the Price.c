/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 10313 de UVA
 * Fecha: 19/noviembre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#define N 300
/*sigue en wrong answer*/

int main(){
    int i,j,v[N];
    for(i=0;i<N;i++){
        v[i]=i+1;
    }
    long long unsigned int sol[N+1][N+1];

    for (i = 0; i <= N; i++) {
        sol[i][0] = 1;
    }
    for (i = 1; i <= N; i++) {
        sol[0][i] = 0;
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            if(v[i-1]<=j){
                sol[i][j]=sol[i-1][j]+sol[i][j-v[i-1]];
            }
            else{
                sol[i][j]=sol[i-1][j];
            }
        }
    }
    int n,l1,l2;
    char c;
    while(scanf("%i%c",&n,&c)==2){
        if(c=='\n'){
            printf("%llu\n",sol[n][n]);
        }
        else{
            scanf("%i%c",&l1,&c);
            if(c=='\n'){
                if(l1>300)
                    l1=300;
                printf("%llu\n",sol[l1][n]);
            }
            else{
                scanf("%i",&l2);
                if(l2>300){
                    l2=300;
                }
                if(l1>n){
                    printf("0\n");
                }
                else{
                    if(l1==0){
                        printf("%llu\n",sol[l2][n]);
                    }
                    else
                        printf("%llu\n",sol[l2][n]-sol[l1-1][n]);
                }
            }
        }
    }
    return 0;
}
