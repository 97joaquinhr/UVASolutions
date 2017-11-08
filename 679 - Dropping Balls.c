/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 679 de UVA
 * Fecha: 4/septiembre/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


int main(){
    int t,n,x;
    scanf("%d",&t);
    while(t>0){
        scanf("%d %d",&n,&x);
        int c=pow(2,n-1);
        if(x==1){
            printf("%i\n",c);
        }
        else if(x==c){
            int res=pow(2,n)-1;
            printf("%i\n",res);
        }
        else{
            int res=1,i;
            for(i=0;i<n-1;i++){
                if(x%2==0){
                    res=res*2+1;
                    x/=2;
                }
                else{
                    res=res*2;
                    x=(x+1)/2;
                }
            }
            printf("%i\n",res);
        }
        t--;
    }


    return 0;

}
