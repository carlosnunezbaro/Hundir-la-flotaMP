#include<stdio.h>
#include<stdlib.h>
#include "Disparo.h"
#include "estado-barcos.h"
#include "juego.h"
#include "configuracion_inicial.h"


void inicializador(){
    int *num_barcos;
    int fin = 1;
    int *nbJ1 = *num_barcos;
    int *nbJ2 = *num_barcos;
}

void disparoJ1(int filas, int columnas, char **tablero_jugador2, int *disparos_realizados_jugador1,int *nbJ2, int *partida_finalizada){
    int i,j = 0;
    // Declarar matrices locales j2_Flota y j2_Oponente basadas en tablero_jugador2 y disparos_realizados_jugador1
    char **j2_Flota = tablero_jugador2;
    char **j2_Oponente = tablero_jugador2;
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
        disparos_realizados_jugador1 = disparos_realizados_jugador1+1;
        printf("%d",j2_Oponente[i][j]);   // imprime la matriz oponente con el efecto del disparo ya efectuado
    }else{
        do{
            if(j2_Flota[i][j]=='B'||j2_Flota[i][j]!='*'){
                        printf("tocado");
                        j2_Flota[i][j]='T';
                        j2_Oponente[i][j]='T';
                        printf("%d",j2_Oponente[i][j]);
                        chequeoH(i,j,j2_Flota[i][j],j2_Oponente[i][j],nbJ2);
                        printf("%d",j2_Oponente[i][j]);
                        if(j2_Oponente == 'H'){
                           nbJ2 =  nbJ2-1;
                               }
                         do{
                            printf("fila");
                            scanf("%i \n",&i);
                            printf("columna");
                            scanf("%i \n",&j);
                            }while(i<=filas||j<=columnas);
                   }else{
                    printf("fallo");
                    j2_Flota[i][j]='*';
                    j2_Oponente[i][j]='*';
                    printf("%d",j2_Oponente[i][j]);
                     }
                }while(j2_Flota[i][j]=='B'||j2_Flota[i][j]!='*');

        }

    if(nbJ2=0){
        partida_finalizada = 0;
    }
}
void disparoJ2(int filas, int columnas, char **tablero_jugador1, int *disparos_realizados_jugador2,int *nbJ1, int *partida_finalizada) {
    int i,j = 0;
    // Declarar matrices locales j2_Flota y j2_Oponente basadas en tablero_jugador2 y disparos_realizados_jugador1
    char **j1_Flota = tablero_jugador1;
    char **j1_Oponente = tablero_jugador1;

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
        *disparos_realizados_jugador2 = *disparos_realizados_jugador2+1;
        printf("%d",j1_Oponente[i][j]);   // imprime la matriz oponente con el efecto del disparo ya efectuado
    }else{
        do{

            if(j1_Flota[i][j]=='B'||j1_Flota[i][j]!='*'){
                        printf("tocado");
                        j1_Flota[i][j]='T';
                        j1_Oponente[i][j]='T';
                        printf("%d",j1_Oponente[i][j]);
                        chequeoH(i,j,j1_Flota[i][j],j1_Oponente[i][j],nbJ1);
                        printf("%d",j1_Oponente[i][j]);
                        if(j1_Oponente == 'H'){
                           nbJ1 =  nbJ1-1;
                               }
                         do{
                            printf("fila");
                            scanf("%i \n",&i);
                            printf("columna");
                            scanf("%i \n",&j);
                            }while(i<=filas||j<=columnas);
                   }else{
                    printf("fallo");
                    j1_Flota[i][j]='*';
                    j1_Oponente[i][j]='*';
                    printf("%d",j1_Oponente[i][j]);
                     };
                }while(j1_Flota[i][j]=='B'||j1_Flota[i][j]!='*');

        }

    if(nbJ1=0){
        partida_finalizada = 0;
    }
}


void disparoIA(int filas, int columnas, char **tablero_jugador, int *disparos_realizados_jugador,int *nbJ, int *partida_finalizada) {
int i,j,ci,cj,n;
i=0;
j=0;
while(i==0||i>=10){    // selecciona una posicion aleatoria de la matriz
    i=rand()%11;
}
while(j==0||j>=10){
    j=rand()%11;
}
    if(jugador1.disparo='A'){
        tablero_jugador = tablero_jugador2;
        char **j_Flota = tablero_jugador;
        char **j_Oponente = tablero_jugador;
        *nbJ = *nbJ2;
        disparos_realizados_jugador=  disparos_realizados_jugador+1;
    }else{
        tablero_jugador = tablero_jugador1;
        char **j_Flota = tablero_jugador;
        char **j_Oponente = tablero_jugador;
        *nbJ = *nbJ1;
        *disparosJ2 =  *disparosJ2+1;
    }
 if(j_Flota[i][j]=='-'){
       printf("fallo");
        j_Flota[i][j]='*';
        j_Oponente[i][j]='*';
        printf("%d",j_Oponente[i][j]);
    }else{
        if(j_Flota[i][j]=='B'||j_Flota[i][j]!='*'){
                    printf("tocado");
                    j_Flota[i][j]='T';
                    j_Oponente[i][j]='T';
                    printf("%d",j_Oponente[i][j]);
                    chequeoH(i,j,j_Flota[i][j],j_Oponente[i][j],nbJ);
                    printf("%d",j_Oponente[i][j]);
                    if(j_Oponente == 'H'){
                           nbJ =  nbJ-1;
                               }
                    ci=i;
                    cj=j;
                    for(n=0;n<=100;n++){
                    while(ci<=i-1||ci==i||ci>=i+1){     // selecciona una posicion aleatoria de un area de la matriz donde ha ocurrido un impacto
                        i=rand()%11;
                        }
                        while(cj<=j-1||cj==j||cj>=j+1){
                        j=rand()%11;
                        if(jugador1.disparo='A'){
                        *disparos_realizados_jugador1 =  *disparos_realizados_jugador1+1;
                            }else{
                        *disparos_realizados_jugador2 =  *disparos_realizados_jugador2+1;
                            }
                        }
                if(j_Flota[i][j]=='B'){
                    if(j_Flota[i][j]=!'*'){
                        printf("tocado");
                        j_Flota[i][j]='T';
                        j_Oponente[i][j]='T';
                        printf("%d",j_Oponente[i][j]);
                        chequeoH(i,j,j_Flota[i][j],j_Oponente[i][j],nbJ);
                        printf("%d",j_Oponente[i][j]);
                        if(j_Oponente == 'H'){
                           nbJ =  nbJ-1;
                               }
                    }else{
                        printf("fallo");
                        j_Flota[i][j]='*';
                        j_Oponente[i][j]='*';
                        printf("%d",j_Oponente[i][j]);
                   }
                }

                }
            }while(j_Flota[i][j]=='B'|| j_Flota[i][j]=!'*');

            }
    if(nbJ=0){
        partida_finalizada= 0;
    }

void chequeoH(int i, int j, char **j_Flota, char **j_Oponente, int *nBar){
    int h, l;
    int hay_B = 0;

    // Primera pasada: Buscar y reemplazar 'B' con 'T' dentro del área 3x3
    for (h = i - 1; h <= i + 1; h++) {
        for (l = j - 1; l <= j + 1; l++) {
            if (h >= 0 && l >= 0 && j_Flota[h] != NULL && j_Flota[h][l] != '\0') {
                if (j_Flota[h][l] == 'B') {
                    j_Flota[h][l] = 'T';
                    hay_B = 1;
                }
            }
        }
    }

    // Si no se encontraron más 'B', reemplazar todas las 'T' por 'H' en el área 3x3
    if (!hay_B) {
        for (h = i - 1; h <= i + 1; h++) {
            for (l = j - 1; l <= j + 1; l++) {

                if (h >= 0 && l >= 0 && j_Flota[h] != NULL && j_Flota[h][l] != '\0') {
                    if (j_Flota[h][l] == 'T') {
                        j_Flota[h][l] = 'H';
                        j_Oponente[h][l] = 'H';
                        (*nBar)--;
                    }
                }
            }
        }
    }
}

