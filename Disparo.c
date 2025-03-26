#include<stdio.h>
#include<stdlib.h>
#include "Disparo.h"
#include "estado-barcos.h"
#include "barcos.h"
int main(){
    int *historial;
    int turnos=1;
    int fin=1;
    int taboponente1[i][j];
    taboponente1[i][j]=tablero[i][j];        \\inicializamos los tableros de ambos jugadores
    int taboponente2[i][j];
    taboponente2[i][j]=tablero[i][j];
    do{
    printf("turno %i \n",turnos)
    if (turnos%2 !=0){
           disparoJ1(tablero,taboponente1,turnos,barcos*barco,fin);
    }else{
        disparoIA(tablero,turnos,barcos*barco,fin);
    }
    }while(fin !=0)
return 0;
}

}
int disparoJ1(int tablero,int taboponente1,int turnos,barcos*barco,int fin){
    int i,j = 0;
    printf("introduce la posicion del disparo \n");
    printf("fila");
    scanf("%i \n",&i);
    printf("columna");
    scanf("%i \n",&j);
    if(tablero[i][j]=='-'){
        printf("fallo");
        tablero[i][j]=0;
        taboponente1[i][j]='*';
        printf("%d",taboponente1[i][j]);   \\imprime la matriz oponente con el efecto del disparo ya efectuado
    }else{
        printf("tocado");
        tablero[i][j]= 1;
        taboponente1[i][j]='T';
        printf("%d",taboponente1[i][j]);
        if(tablero[i][j]=='s')
            printf("hundido");
            tablero[i][j]=2;
            taboponente1[i][j]='H';
            printf("%d",taboponente1[i][j]);
        if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'){
                do{
                   if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente1[i][j])
                    printf("tocado");
                    tablero[i][j]= 1;
                    taboponente1[i][j]='T';
                    printf("%d",taboponente1[i][j]);
                if(tablero[i][j]=='s'||tablero[i][j]=!taboponente1[i][j]){
                    printf("hundido");
                    tablero[i][j]=2;
                    taboponente1[i][j]='H';
                    printf("%d",taboponente1[i][j]);
                }else{
                printf("fallo");
                tablero[i][j]=0;
                taboponente1[i][j]='*';
                printf("%d",taboponente1[i][j]);
                }while(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente1[i][j])

        }
    }
    turnos++
    if(Nbarcosriv=0){
        fin = 0;
    }
}
int disparoIA(int tablero,int taboponente2,int turnos,barcos*barco,int fin){
int i,j,ci,cj;
i=0;
j=0;
n=0;
while(i==0||i>=10){    \\selecciona una posicion aleatoria de la matriz
    i=rand()%11;
}
while(j==0||j>=10){
    j=rand()%11;
}
 if(tablero[i][j]=='-'){
       printf("fallo");
        tablero[i][j]=0;
        taboponente2[i][j]='*';
        printf("%d",taboponente2[i][j]);
    }else{
        printf("tocado");
        tablero[i][j]= 1;
        taboponente2[i][j]='T';
        printf("%d",taboponente2[i][j]);
        if(tablero[i][j]=='s')
            printf("hundido");
            tablero[i][j]=2;
            taboponente2[i][j]='H';
            printf("%d",taboponente2[i][j]);
        if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'){
            do{
                    ci=i;
                    cj=j;
                    for(n=0;n<=100;n++){
                    while(ci<=i-1|ci==i|ci>=i+1){     \\selecciona una posicion aleatoria de un area de la matriz donde ha ocurrido un impacto
                        i=rand()%11;
                        }
                        while(cj<=j-1|cj==j|cj>=j+1){
                        j=rand()%11;
                        }

                if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente2[i][j])
                    printf("tocado");
                    tablero[i][j]= 1;
                    taboponente2[i][j]='T';
                    printf("%d",taboponente2[i][j]);
                if(tablero[i][j]=='s'||tablero[i][j]=!taboponente2[i][j]){
                    printf("hundido");
                    tablero[i][j]=2;
                    taboponente2[i][j]='H';
                    printf("%d",taboponente2[i][j]);
                }else{
                printf("fallo");
                tablero[i][j]=0;
                taboponente2[i][j]='*';
                printf("%d",taboponente2[i][j]);
                }
            }while(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente2[i][j])

            }
        }

    }
    turnos++;
    if(Nbarcosriv=0){
        fin = 0;
    }
}









}
