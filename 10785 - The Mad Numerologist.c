/*-------------------------------------------------------
 *
 * Actividad de programación: Problema 10785 de UVA
 * Fecha: 7/nov/2017
 * Autor: A01207504 Joaquín Herrera Ramos
 *
 *------------------------------------------------------*/

 #include<stdio.h>
 #include<stdlib.h>


int compare(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

 int isVowel(int ch){
    int c = toupper(ch);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}


 int main(){
     int i,j,cont=0;
     char numer[9][3];
     for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            if(cont==26)
                break;
            numer[j][i]='A'+cont;
            cont++;
        }
     }
     int N,n,vowel,conts=0,ik=0,jk=1,contp;
     char cons;
     char rc[106],vc[106];
     scanf("%i",&N);
     for(i=0;i<N;i++){
        scanf("%i",&n);
        contp=0;
        printf("Case %i: ",i+1);
        /*A numer[0][0],U numer[2][2],E numer[4][0],O numer[5][1],I numer[8][0]*/
        for(j=0;j<n;j++){
            if(j%2==0){
                vowel=j/42+1;
                switch(vowel){
                    case 1:
                        vc[j-contp]='A';
                        break;
                    case 2:
                        vc[j-contp]='U';
                        break;
                    case 3:
                        vc[j-contp]='E';
                        break;
                    case 4:
                        vc[j-contp]='O';
                        break;
                    case 5:
                        vc[j-contp]='I';
                        break;
                }
            }
            else{
                contp++;
                if(conts%5==0&&conts>0){
                    if(jk<2)
                        jk++;
                    else{
                        jk=0;
                        ik++;
                    }
                    if(isVowel(numer[ik][jk])){
                        if(jk<2)
                            jk++;
                        else{
                            jk=0;
                            ik++;
                        }
                    }
                    conts=0;
                }
                rc[j-contp]=numer[ik][jk];
                conts++;
            }

        }
        qsort(rc,n/2,sizeof(char),compare);
        if(n%2==0)
            qsort(vc,n/2,sizeof(char),compare);
        else
            qsort(vc,n/2+1,sizeof(char),compare);
        contp=0;
        int ix;
        for(ix=0;ix<n;ix++){
            if(ix%2==0)
                printf("%c",vc[ix-contp]);
            else{
                contp++;
                printf("%c",rc[ix-contp]);
            }

        }
        ik=0;
        jk=1;
        conts=0;
        printf("\n");

     }
     return 0;

 }
