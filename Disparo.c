#include<stdio.h>
#include<stdlib.h>
#include "Disparo.h"
#include "estado-barcos.h"
#include "barcos.h"
#include "juego.h"


void inicializador(){
    int turnos = 1;
    int fin = 1;
    int *nbJ1 = *num_barcos;
    int *nbJ2 = *num_barcos;
}

void disparoJ1(int filas, int columnas, char **j2_Flota, char **j2_Oponente, int *turnos, Barcos *barcosJ2, int *nbJ2, int *fin){
    int i,j = 0;
    printf("introduce la posicion del disparo \n");
    do{
    printf("fila");
    scanf("%i \n",&i);
    printf("columna");
    scanf("%i \n",&j);
    }while(i<=filas||j<=columnas);
    if(j2_Flota[i][j]=='-'){
        printf("fallo");
        j2_Flota[i][j]='*';
        j2_Oponente[i][j]='*';
        *disparosJ1 = *disparosJ1+1;
        printf("%d",j2_Oponente[i][j]);   // imprime la matriz oponente con el efecto del disparo ya efectuado
    }else{
        do{
        printf("tocado");
        j2_Flota[i][j]='T'; 
        j2_Oponente[i][j]='T';
        printf("%d",j2_Oponente[i][j]);
        if(j2_Flota[i][j]=='s'){
            printf("hundido");
            (*nbJ2) = (*nbJ2) - 1;
            j2_Flota[i][j]='H';
            j2_Oponente[i][j]='H';
            *disparosJ1 = *disparosJ1+1;
            printf("%d",j2_Oponente[i][j]);
        }else{
        if(j2_Flota[i][j]=='a'||j2_Flota[i][j]=='d'||j2_Flota[i][j]=='f'){

                   if(j2_Flota[i][j]=='f'||j2_Flota[i][j]!='*'){
                        printf("tocado");
                        j2_Flota[i][j]='T';
                        j2_Oponente[i][j]='T';
                        printf("%d",j2_Oponente[i][j]);
                        chequeoH(j2_Flota[i][j],j2_Oponente[i][j],barcosJ2,nbJ2);
                        printf("%d",j2_Oponente[i][j]);
                   }
                   if(j2_Flota[i][j]=='d'||j2_Flota[i][j]!='*'){
                        printf("tocado");
                        j2_Flota[i][j]='T';
                        j2_Oponente[i][j]='T';
                        printf("%d",j2_Oponente[i][j]);
                        chequeoH(j2_Flota[i][j],j2_Oponente[i][j],barcosJ2,nbJ2);
                        printf("%d",j2_Oponente[i][j]);
                   }

                    if(j2_Flota[i][j]=='a'||j2_Flota![i][j]='*' ){
                       printf("tocado");
                        j2_Flota[i][j]='T';
                        j2_Oponente[i][j]='T';
                        printf("%d",j2_Oponente[i][j]);
                        chequeoH(j2_Flota[i][j],j2_Oponente[i][j],barcosJ2,nbJ2);
                        printf("%d",j2_Oponente[i][j]);
                    }
                if(j2_Flota[i][j]=='s'||j2_Flota![i][j]='*'){
                    printf("hundido");
                    (*nbJ2) = (*nbJ2) - 1;
                    j2_Flota[i][j]='H';
                    j2_Oponente[i][j]='H';
                    printf("%d",j2_Oponente[i][j]);
                }else{
                    printf("fallo");
                    j2_Flota[i][j]='*';
                    j2_Oponente[i][j]='*';
                    printf("%d",j2_Oponente[i][j]); 
                }

                printf("introduce la posicion del disparo \n");
                printf("fila");
                scanf("%i \n",&i);
                printf("columna");
                scanf("%i \n",&j);
                *disparosJ1 = *disparosJ1+1;
        }
        }
                }while(j2_Flota[i][j]=='a'||j2_Flota[i][j]=='d'||j2_Flota[i][j]=='f'||j2_Flota![i][j]='*' )

        }

    turnos++;
    if(nbJ2=0){
        fin = 0;
    }
}
void disparoJ2(int filas, int columnas, char **j1_Flota, char **j1_Oponente, int *turnos, Barcos *barcosJ1, int *nbJ1, int *fin){
    int i,j = 0;
    printf("introduce la posicion del disparo \n");
    do{
    printf("fila");
    scanf("%i \n",&i);
    printf("columna");
    scanf("%i \n",&j);
    }while(i<=filas||j<=columnas);
    if(j1_Flota[i][j]=='-'){
        printf("fallo");
        j1_Flota[i][j]='*';
        j1_Oponente[i][j]='*';
        *disparosJ2 = *disparosJ2+1;
        printf("%d",j1_Oponente[i][j]);   // imprime la matriz oponente con el efecto del disparo ya efectuado
    }else{
        do{
        printf("tocado");
        j1_Flota[i][j]='T';
        j1_Oponente[i][j]='T';
        printf("%d",j1_Oponente[i][j]);
        if(j1_Flota[i][j]=='s'){
            printf("hundido");
            BarcosJ1.submarino = 0;
            nbJ1=nbJ1-1;
            j1_Flota[i][j]='H';
            j1_Oponente[i][j]='H';
            *disparosJ2 = *disparosJ2+1;
            printf("%d",j1_Oponente[i][j]);
        }else{
        if(j1_Flota[i][j]=='a'||j1_Flota[i][j]=='d'||j1_Flota[i][j]=='f'){

                   if(j1_Flota[i][j]=='f'||j1_Flota[i][j]!='*'){
                        printf("tocado");
                        j1_Flota[i][j]='T';
                        j1_Oponente[i][j]='T';
                        printf("%d",j1_Oponente[i][j]);
                        chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                        printf("%d",j1_Oponente[i][j]);
                   }
                   if(j1_Flota[i][j]=='d'||j1_Flota[i][j]!='*'){
                        printf("tocado");
                        j1_Flota[i][j]='T';
                        j1_Oponente[i][j]='T';
                        printf("%d",j1_Oponente[i][j]);
                        chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                        printf("%d",j1_Oponente[i][j]);
                   }

                    if(j1_Flota[i][j]=='a'||j1_Flota!='*'){
                       printf("tocado");
                        j2_Flota[i][j]='T';
                        j1_Oponente[i][j]='T'
                        printf("%d",j1_Oponente[i][j]);
                        chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                        printf("%d",j1_Oponente[i][j]);
                    }
                if(j1_Flota[i][j]=='s'||j1_Flota!='*'){
                    printf("hundido");
                    BarcosJ1.submarino = 0;
                    nbJ1=nbJ1-1;
                    j2_Flota[i][j]='H';
                    j1_Oponente[i][j]='H';
                    printf("%d",j1_Oponente[i][j]);
                }else{
                    printf("fallo");
                    j1_Flota[i][j]='*';
                    j1_Oponente[i][j]='*';
                    printf("%d",j1_Oponente[i][j]);
                }

                printf("introduce la posicion del disparo \n");
                printf("fila");
                scanf("%i \n",&i);
                printf("columna");
                scanf("%i \n",&j);
                *disparosJ2 = *disparosJ2+1;
        }
        }
                }while(j1_Flota[i][j]=='a'||j1_Flota[i][j]=='d'||j1_Flota[i][j]=='f'||j1_Flota!='*')

        }

    turnos++;
    if(nbJ1=0){
        fin = 0;
    }


}


void disparoIA(char **j1_Flota, char **j1_Oponente, int filas, int columnas, int *turnos, Barcos *barcosJ1, int *nbJ1, int *fin){
int i,j,ci,cj;
i=0;
j=0;
while(i==0||i>=10){    \\ selecciona una posicion aleatoria de la matriz
    i=rand()%11;
}
while(j==0||j>=10){
    j=rand()%11;
}
    if(jugador1.disparo='A'){
        *disparosJ1 =  *disparosJ1+1;
    }else{
        *disparosJ2 =  *disparosJ2+1;
    }
 if(j1_Flota[i][j]=='-'){
       printf("fallo");
        j1_Flota[i][j]='*'; 
        j1_Oponente[i][j]='*';
        if(jugador1.disparo='A'){
        *disparosJ1 =  *disparosJ1+1;
    }else{
        *disparosJ2 =  *disparosJ2+1;
    }
        printf("%d",j1_Oponente[i][j]);
    }else{
        printf("tocado");
        j1_Flota[i][j]='T';
        j1_Oponente[i][j]='T';
        printf("%d",j1_Oponente[i][j]);
        do{
        if(j1_Flota[i][j]=='s')
            printf("hundido");
            BarcosJ1.submarino = 0;
            j1_Flota[i][j]='H'
            nbJ1=nbJ1-1;
            j1_Oponente[i][j]='H';
            if(jugador1.disparo='A'){
            *disparosJ1 =  *disparosJ1+1;
                }else{
            *disparosJ2 =  *disparosJ2+1;
                }
            printf("%d",j1_Oponente[i][j]);
        }else{
        if(j1_Flota[i][j]=='a'||j1_Flota[i][j]=='d'||j1_Flota[i][j]=='f'){
                    ci=i;
                    cj=j;
                    for(n=0;n<=100;n++){
                    while(ci<=i-1||ci==i||ci>=i+1){     \\ selecciona una posicion aleatoria de un area de la matriz donde ha ocurrido un impacto
                        i=rand()%11;
                        }
                        while(cj<=j-1||cj==j||cj>=j+1){
                        j=rand()%11;
                        }
                        if(jugador1.disparo='A'){
                        *disparosJ1 =  *disparosJ1+1;
                            }else{
                        *disparosJ2 =  *disparosJ2+1;
                            }
                if(j1_Flota[i][j]=='a'||j1_Flota[i][j]=='d'||j1_Flota[i][j]=='f'||j1_Flota[i][j]=!'*'){
                   if(j1_Flota[i][j]=='f'||j1_Flota[i][j]=!'*'){
                    printf("tocado");
                    j1_Flota[i][j]='T';
                    j1_Oponente[i][j]='T';
                    printf("%d",j1_Oponente[i][j]);
                    chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                    printf("%d",j1_Oponente[i][j]);
                   }
                   if(j1_Flota[i][j]=='d'||j1_Flota[i][j]=!'*'){
                    printf("tocado");
                    j1_Flota[i][j]='T';
                    j1_Oponente[i][j]='T';
                    printf("%d",j1_Oponente[i][j]);
                    chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                    printf("%d",j1_Oponente[i][j]);
                   }

                    if(j1_Flota[i][j]=='a'||j1_Flota[i][j]=!'*'){
                    printf("tocado");
                    j1_Flota[i][j]='T';
                    j1_Oponente[i][j]='T';
                    printf("%d",j1_Oponente[i][j]);
                    chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                    printf("%d",j1_Oponente[i][j]);
                    }
                if(j1_Flota[i][j]=='s'||j1_Flota[i][j]=!'*'){
                    printf("hundido");
                    BarcosJ1.submarino = 0;
                    nbJ1=nbJ1-1;
                    j1_Flota[i][j]='H';
                    j1_Oponente[i][j]='H';
                    printf("%d",j1_Oponente[i][j]);
                }else{
                    printf("fallo");
                    j1_Flota[i][j]='*';
                    j1_Oponente[i][j]='*';
                    printf("%d",j1_Oponente[i][j]);
                }
                
                }
            }while(j1_Flota[i][j]=='a'||j1_Flota[i][j]=='d'||j1_Flota[i][j]=='f'||j1_Flota[i][j]=!'*')

            }
        }

    }
    turnos++;
    if(nbJ1=0){
        fin = 0;
    }
}
void chequeoH(int i, int j, char **j_Flota, char **j_Oponente, Barcos *barcos, int *nBar){
    int h,l,cont;
    cont=0;
        for(h=i-1,h<=i+1,h++){
            for(l=j-1,l<=j+1,l++){
                if(j1_Flota[h][l]=='f'||j1_Flota[h][l]!=j1_Flota[i][j]{
                    j1_Flota[i][j]='H';
                    j1_Flota[h][l]='H';
                    j1_Oponente[i][j]='H';
                    j1_Oponente[h][l]='H';
                     (*nBar)--;
                }
                if(j1_Flota[h][l]=='d'||j1_Flota[h][l]!=j1_Flota[i][j]){
                    j1_Flota[h][l]='T';
                    cont=cont+1;
                        if(cont=2){
                            for(h=i-1,h<=i+1,h++){
                                for(l=j-1,l<=j+1,l++){
                                    if(j1_Flota[h][l]='T'||j1_Flota[h][l]!=j1_Flota[i][j]{
                                        j1_Flota[i][j]='H';
                                        j1_Flota[h][l]='H';
                                        j1_Oponente[i][j]='H';
                                        j1_Oponente[h][l]='H';
                                         (*nBar)--;
                                    }
                                }
                            }
                    }
                }
                 if(j1_Flota[h][l]=='a'||j1_Flota[h][l]!=j1_Flota[i][j]){
                    j1_Flota[h][l]='T';
                    cont=cont+1;  
                    if(cont=3){
                        for(h=i-2,h<=i+2,h++){
                            for(l=j-2,l<=j+2,l++){
                                if(j1_Flota[h][l]='T'||j1_Flota[h][l]!=j1_Flota[i][j]){
                                    j1_Flota[i][j]='H';
                                    j1_Flota[h][l]='H';
                                    j1_Oponente[i][j]='H';
                                    j1_Oponente[h][l]='H';
                                     (*nBar)--;    
                                }
                                }
                            }
                    }
                 }
            }
        }
}
