#include<stdio.h>
#include<stdlib.h>
#include "Disparo.h"
#include "estado-barcos.h"
#include "barcos.h"


typedef struct{
    int fragata1=2;
    int fragata2=2;
    int fragata3=2;
    int acorazado=5;
    int destructor1=3;
    int destructor2=3;
    int submarino=1;
}BarcosJ1,BarcosJ2;


int main(){
    int turnos=1;
    int fin=1;
    int nbJ1,nbJ2=7;
    int taboponente1[i][j];
    taboponente1[i][j]=tablero[i][j];        \\inicializamos los tableros de ambos jugadores
    int taboponente2[i][j];
    taboponente2[i][j]=tablero[i][j];
    do{
    printf("turno %i \n",turnos)
    if (turnos%2 !=0){
           disparoJ1(tablero,taboponente1,turnos,BarcosJ2,fin);
    }else{
        disparoIA(tablero,turnos,BarcosJ1,fin);
    }
    }while(fin !=0)
return 0;
}


int disparoJ1(int tablero,int taboponente1,int turnos,BarcosJ2,int nbJ2,int fin){
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
        do{
        printf("tocado");
        tablero[i][j]= 4;
        taboponente1[i][j]='T';
        printf("%d",taboponente1[i][j]);
        if(tablero[i][j]=='s'){
            printf("hundido");
            BarcosJ2.submarino = 0;
            tablero[i][j]=7;
            nbJ2=nbJ2-1;
            taboponente1[i][j]='H';
            printf("%d",taboponente1[i][j]);
        }else{
        if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'){

                   if(tablero[i][j]=='f'||tablero[i][j]=!taboponente1[i][j]){
                    printf("tocado");
                        if(tablero[i][j]=BarcosJ2.fragata1)
                               BarcosJ2.fragata1= BarcosJ2.fragata1-1;
                        if(tablero[i][j]=BarcosJ2.fragata2)
                               BarcosJ2.fragata2= BarcosJ2.fragata2-1;
                        if(tablero[i][j]=BarcosJ2.fragata3)
                               BarcosJ2.fragata3= BarcosJ2.fragata3-1;
                        tablero[i][j]= 4;
                        taboponente1[i][j]='T';
                        printf("%d",taboponente1[i][j]);
                        if (BarcosJ2.fragata1 = 0){
                            printf("hundido");
                            nbJ2=nbJ2-1;
                            tablero[i][j]=7;
                            taboponente1[i][j]='H';
                        }
                          if (BarcosJ2.fragata2 = 0){
                            printf("hundido");
                            nbJ2=nbJ2-1;
                            tablero[i][j]=7;
                            taboponente1[i][j]='H';
                        }
                           if (BarcosJ2.fragata3 = 0){
                            printf("hundido");
                            nbJ2=nbJ2-1;
                            tablero[i][j]=7;
                            taboponente1[i][j]='H';
                        }
                   }
                   if(tablero[i][j]=='d'||tablero[i][j]=!taboponente1[i][j]){
                    printf("tocado");
                        if(tablero[i][j]=BarcosJ2.destructor1)
                               BarcosJ2.destructor1= BarcosJ2.destructor1-1;
                        if(tablero[i][j]=BarcosJ2.destructor2)
                               BarcosJ2.destructor2= BarcosJ2.destructor2-1;
                        tablero[i][j]= 4;
                        taboponente1[i][j]='T';
                        printf("%d",taboponente1[i][j]);
                        if (BarcosJ2.destructor1 = 0){
                            printf("hundido");
                            nbJ2=nbJ2-1;
                            tablero[i][j]=7;
                            taboponente1[i][j]='H';
                        }
                          if (BarcosJ2.destructor2 = 0){
                            printf("hundido");
                            nbJ2=nbJ2-1;
                            tablero[i][j]=7;
                            taboponente1[i][j]='H';
                        }
                   }

                    if(tablero[i][j]=='a'||tablero[i][j]=!taboponente1[i][j]){
                        printf("tocado");
                        if(tablero[i][j]=BarcosJ2.acorazado){
                               BarcosJ2.acorazado= BarcosJ2.acorazado-1;
                                tablero[i][j]= 4;
                                taboponente1[i][j]='T';
                                printf("%d",taboponente1[i][j]);
                        if (BarcosJ2.acorazado = 0){
                            printf("hundido");
                            nbJ2=nbJ2-1;
                            tablero[i][j]=7;
                            taboponente1[i][j]='H';
                        }
                        }
                    }
                if(tablero[i][j]=='s'||tablero[i][j]=!taboponente1[i][j]){
                    printf("hundido");
                    BarcosJ2.submarino = 0;
                    nbJ2=nbJ2-1;
                    tablero[i][j]=7;
                    taboponente1[i][j]='H';
                    printf("%d",taboponente1[i][j]);
                }else{
                    printf("fallo");
                    tablero[i][j]=0;
                    taboponente1[i][j]='*';
                    printf("%d",taboponente1[i][j]);
                }

                printf("introduce la posicion del disparo \n");
                printf("fila");
                scanf("%i \n",&i);
                printf("columna");
                scanf("%i \n",&j);
        }
        }
                }while(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente1[i][j])

        }

    turnos++
    if(nbJ2=0){
        fin = 0;
    }
}
int disparoIA(int tablero,int taboponente2,int turnos,BarcosJ2,int nbJ1,int fin){
int i,j,ci,cj;
i=0;
j=0;
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
        tablero[i][j]= 4;
        taboponente2[i][j]='T';
        printf("%d",taboponente2[i][j]);
        do{
        if(tablero[i][j]=='s')
            printf("hundido");
            BarcosJ1.submarino = 0;
            tablero[i][j]=7;
            nbJ1=nbJ1-1;
            taboponente1[i][j]='H';
            printf("%d",taboponente2[i][j]);
        }else{
        if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'){
                    ci=i;
                    cj=j;
                    for(n=0;n<=100;n++){
                    while(ci<=i-1|ci==i|ci>=i+1){     \\selecciona una posicion aleatoria de un area de la matriz donde ha ocurrido un impacto
                        i=rand()%11;
                        }
                        while(cj<=j-1|cj==j|cj>=j+1){
                        j=rand()%11;
                        }

                if(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente2[i][j]){
                   if(tablero[i][j]=='f'||tablero[i][j]=!taboponente2[i][j]){
                    printf("tocado");
                        if(tablero[i][j]=BarcosJ1.fragata1)
                               BarcosJ1.fragata1= BarcosJ1.fragata1-1;
                        if(tablero[i][j]=BarcosJ1.fragata2)
                               BarcosJ1.fragata2= BarcosJ1.fragata2-1;
                        if(tablero[i][j]=BarcosJ1.fragata3)
                               BarcosJ1.fragata3= BarcosJ1.fragata3-1;
                        tablero[i][j]= 4;
                        taboponente2[i][j]='T';
                        printf("%d",taboponente2[i][j]);
                        if (BarcosJ1.fragata1 = 0){
                            printf("hundido");
                            nbJ1=nbJ1-1;
                            tablero[i][j]=7;
                            taboponente2[i][j]='H';
                        }
                          if (BarcosJ1.fragata2 = 0){
                            printf("hundido");
                            nbJ1=nbJ1-1;
                            tablero[i][j]=7;
                            taboponente2[i][j]='H';
                        }
                           if (BarcosJ1.fragata3 = 0){
                            printf("hundido");
                            nbJ1=nbJ1-1;
                            tablero[i][j]=7;
                            taboponente2[i][j]='H';
                        }
                   }
                   if(tablero[i][j]=='d'||tablero[i][j]=!taboponente2[i][j]){
                    printf("tocado");
                        if(tablero[i][j]=BarcosJ1.destructor1)
                               BarcosJ1.destructor1= BarcosJ1.destructor1-1;
                        if(tablero[i][j]=BarcosJ1.destructor2)
                               BarcosJ1.destructor2= BarcosJ1.destructor2-1;
                        tablero[i][j]= 4;
                        taboponente2[i][j]='T';
                        printf("%d",taboponente2[i][j]);
                        if (BarcosJ1.destructor1 = 0){
                            printf("hundido");
                            nbJ1=nbJ1-1;
                            tablero[i][j]=7;
                            taboponente2[i][j]='H';
                        }
                          if (BarcosJ1.destructor2 = 0){
                            printf("hundido");
                            nbJ1=nbJ1-1;
                            tablero[i][j]=7;
                            taboponente2[i][j]='H';
                        }
                   }

                    if(tablero[i][j]=='a'||tablero[i][j]=!taboponente2[i][j]){
                        printf("tocado");
                        if(tablero[i][j]=BarcosJ1.acorazado){
                               BarcosJ1.acorazado= BarcosJ1.acorazado-1;
                                tablero[i][j]= 4;
                                taboponente1[i][j]='T';
                                printf("%d",taboponente2[i][j]);
                        if (BarcosJ1.acorazado = 0){
                            printf("hundido");
                            nbJ1=nbJ1-1;
                            tablero[i][j]=7;
                            taboponente2[i][j]='H';
                        }
                        }
                    }
                if(tablero[i][j]=='s'||tablero[i][j]=!taboponente2[i][j]){
                    printf("hundido");
                    BarcosJ1.submarino = 0;
                    nbJ1=nbJ1-1;
                    tablero[i][j]=7;
                    taboponente1[i][j]='H';
                    printf("%d",taboponente2[i][j]);
                }else{
                    printf("fallo");
                    tablero[i][j]=0;
                    taboponente1[i][j]='*';
                    printf("%d",taboponente2[i][j]);
                }
                }
            }while(tablero[i][j]=='a'||tablero[i][j]=='d'||tablero[i][j]=='f'||tablero[i][j]=!taboponente2[i][j])

            }
        }

    }
    turnos++;
    if(nbJ1=0){
        fin = 0;
    }
}
