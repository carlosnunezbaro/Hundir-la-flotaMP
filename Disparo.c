#include<stdio.h>
#include<stdlib.h>
#include "Disparo.h"
#include "estado-barcos.h"
#include "barcos.h"


typedef struct{
    int fragata=3;
    int acorazado=1;
    int destructor=2;
    int submarino=1;
}BarcosJ1,BarcosJ2;


void inicializador(){
    int turnos=1;
    int fin=1;
    int nbJ1,nbJ2=7;
    }

void disparoJ1(int filas,int columnas,char **tablero2,int turnos,BarcosJ2,int nbJ2,int fin){// la dimensión de la matriz (1 porque es cuadrada
    int i,j = 0;
    printf("introduce la posicion del disparo \n");
    do{
    printf("fila");
    scanf("%i \n",&i);
    printf("columna");
    scanf("%i \n",&j);
    }while(i<=filas||j<=columnas);
    if(tablero2[i][j]=='-'){
        printf("fallo");
        tablero2[i][j]='*';
        printf("%d",tablero2[i][j]);   \\imprime la matriz oponente con el efecto del disparo ya efectuado
    }else{
        do{
        printf("tocado");
        tablero2[i][j]='T';
        printf("%d",tablero2[i][j]);
        if(tablero2[i][j]=='s'){
            printf("hundido");
            BarcosJ2.submarino = 0;
            nbJ2=nbJ2-1;
            tablero2[i][j]='H';
            printf("%d",tablero2[i][j]);
        }else{
        if(tablero2[i][j]=='a'||tablero2[i][j]=='d'||tablero2[i][j]=='f'){

                   if(tablero2[i][j]=='f'||tablero2[i][j]!='*'){
                        printf("tocado");
                        tablero2[i][j]='T';
                        printf("%d",tablero2[i][j]);
                        chequeoH(tablero2[i][j],barcosJ2,nbJ2);
                        printf("%d",tablero2[i][j]);
                   }
                   if(tablero2[i][j]=='d'||tablero2[i][j]!='*'){
                        printf("tocado");
                        tablero2[i][j]='T';
                        printf("%d",tablero2[i][j]);
                        chequeoH(tablero2[i][j],barcosJ2,nbJ2);
                        printf("%d",tablero2[i][j]);
                   }

                    if(tablero2[i][j]=='a'||tablero2!='*'){
                       printf("tocado");
                        tablero2[i][j]='T';
                        printf("%d",tablero2[i][j]);
                        chequeoH(tablero2[i][j],barcosJ2,nbJ2);
                        printf("%d",tablero2[i][j]);
                    }
                if(tablero2[i][j]=='s'||tablero2!='*'){
                    printf("hundido");
                    BarcosJ2.submarino = 0;
                    nbJ2=nbJ2-1;
                    tablero2[i][j]='H';
                    printf("%d",tablero2[i][j]);;
                }else{
                    printf("fallo");
                    tablero2[i][j]='*';
                    printf("%d",tablero2[i][j]); 
                }

                printf("introduce la posicion del disparo \n");
                printf("fila");
                scanf("%i \n",&i);
                printf("columna");
                scanf("%i \n",&j);
        }
        }
                }while(tablero2[i][j]=='a'||tablero2[i][j]=='d'||tablero2[i][j]=='f'||tablero2!='*')

        }

    turnos++
    if(nbJ2=0){
        fin = 0;
    }
}
void disparoIA(char **tablero1,int turnos,BarcosJ2,int nbJ1,int fin){
int i,j,ci,cj;
i=0;
j=0;
while(i==0||i>=10){    \\selecciona una posicion aleatoria de la matriz
    i=rand()%11;
}
while(j==0||j>=10){
    j=rand()%11;
}
 if(tablero1[i][j]=='-'){
       printf("fallo");
        tablero1[i][j]='*'; 
        printf("%d",tablero1[i][j]);
    }else{
        printf("tocado");
        tablero1[i][j]='T';
        printf("%d",tablero1[i][j]);
        do{
        if(tablero[i][j]=='s')
            printf("hundido");
            BarcosJ1.submarino = 0;
            tablero1[i][j]='H'
            nbJ1=nbJ1-1;
            printf("%d",tablero1[i][j]);
        }else{
        if(tablero1[i][j]=='a'||tablero1[i][j]=='d'||tablero1[i][j]=='f'){
                    ci=i;
                    cj=j;
                    for(n=0;n<=100;n++){
                    while(ci<=i-1|ci==i|ci>=i+1){     \\selecciona una posicion aleatoria de un area de la matriz donde ha ocurrido un impacto
                        i=rand()%11;
                        }
                        while(cj<=j-1|cj==j|cj>=j+1){
                        j=rand()%11;
                        }

                if(tablero1[i][j]=='a'||tablero1[i][j]=='d'||tablero1[i][j]=='f'||tablero1[i][j]=!'*'){
                   if(tablero1[i][j]=='f'||tablero1[i][j]=!'*'){
                    printf("tocado");
                    tablero1[i][j]='T';
                    printf("%d",tablero1[i][j]);
                    chequeoH(tablero1[i][j],barcosJ1,nbJ1);
                    printf("%d",tablero1[i][j]);
                   }
                   if(tablero1[i][j]=='d'||tablero1[i][j]=!'*'){
                    printf("tocado");
                    tablero1[i][j]='T';
                    printf("%d",tablero1[i][j]);
                    chequeoH(tablero1[i][j],barcosJ1,nbJ1);
                    printf("%d",tablero1[i][j]);
                   }

                    if(tablero1[i][j]=='a'||tablero1[i][j]='*'){
                    printf("tocado");
                    tablero1[i][j]='T';
                    printf("%d",tablero1[i][j]);
                    chequeoH(tablero1[i][j],barcosJ1,nbJ1);
                    printf("%d",tablero1[i][j]);
                    }
                if(tablero1[i][j]=='s'||tablero1[i][j]=!'*'){
                    printf("hundido");
                    BarcosJ1.submarino = 0;
                    nbJ1=nbJ1-1;
                    tablero1[i][j]='H';
                    printf("%d",tablero1[i][j]);
                }else{
                    printf("fallo");
                    tablero1[i][j]='*';
                    printf("%d",tablero1[i][j]);
                }
                }
            }while(tablero1[i][j]=='a'||tablero1[i][j]=='d'||tablero1[i][j]=='f'||tablero1[i][j]=!'*')

            }
        }

    }
    turnos++;
    if(nbJ1=0){
        fin = 0;
    }
}
void chequeoH(char **tablero[i][j],int nBar,Barcos){
    int h,l,cont;
    cont=0;
        for(h=i-1,h<=i+1,h++){
            for(l=j-1,l<=j+1,l++){
                if(tablero[h][l]='f'||tablero[h][l]!=tablero[i][j]{
                    tablero[i][j]='H';
                    tablero[h][l]='H';
                    Barcos.fragatas=Barcos.fragatas-1;
                    nBar=nbar-1;
                }
                if(tablero[h][l]='d'||tablero[h][l]!=tablero[i][j]){
                    tablero[h][l]='T';
                    cont=cont+1;
                        if(cont=2){
                            for(h=i-1,h<=i+1,h++){
                                for(l=j-1,l<=j+1,l++){
                                    if(tablero[h][l]='T'||tablero[h][l]!=tablero[i][j]{
                                        tablero[i][j]='H';
                                        tablero[h][l]='H';
                                        Barcos.destructores=Barcos.destructores-1;
                                        nBar=nbar-1;
                                    }
                                }
                            }
                    }
                }
                 if(tablero[h][l]='a'||tablero[h][l]!=tablero[i][j]){
                    tablero[h][l]='T';
                    cont=cont+1;  
                    if(cont=3){
                        for(h=i-2,h<=i+2,h++){
                            for(l=j-2,l<=j+2,l++){
                                if(tablero[h][l]='T'||tablero[h][l]!=tablero[i][j]){
                                    tablero[i][j]='H';
                                    tablero[h][l]='H';
                                    Barcos.acorazado=Barcos.acorazado-1;
                                    nBar=nbar-1;
                                }
                                }
                            }
                    }
                 }
            }
        }
}
