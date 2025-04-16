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

            if(j2_Flota[i][j]=='B'||j2_Flota[i][j]!='*'){
                        printf("tocado");
                        j2_Flota[i][j]='T';
                        j2_Oponente[i][j]='T';
                        printf("%d",j2_Oponente[i][j]);
                        chequeoH(j2_Flota[i][j],j2_Oponente[i][j],barcosJ2,nbJ2);
                        printf("%d",j2_Oponente[i][j]);
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
                }while(j2_Flota[i][j]=='B'||j2_Flota[i][j]!='*' )

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

            if(j1_Flota[i][j]=='B'||j1_Flota[i][j]!='*'){
                        printf("tocado");
                        j1_Flota[i][j]='T';
                        j1_Oponente[i][j]='T';
                        printf("%d",j1_Oponente[i][j]);
                        chequeoH(j1_Flota[i][j],j1_Oponente[i][j],barcosJ1,nbJ1);
                        printf("%d",j1_Oponente[i][j]);
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
                     }
                }while(j1_Flota[i][j]=='B'||j1_Flota[i][j]!='*' )

        }

    turnos++;
    if(nbJ1=0){
        fin = 0;
    }
}


void disparoIA(char **j_Flota, char **j_Oponente, int filas, int columnas, int *turnos, Barcos *barcosJ, int *nbJ, int *fin){
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
        j_Flota[i][j] = j1_Flota[i][j];
        j_Oponente[i][j] = j1_oponente[i][j];
        *nbj = *nbJ1;
        *disparosJ1 =  *disparosJ1+1;
    }else{
        j_Flota[i][j] = j2_Flota[i][j];
        j_Oponente[i][j] = j2_oponente[i][j];
        *nbj = *nbJ2;
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
                    chequeoH(j_Flota[i][j],j_Oponente[i][j],barcosJ,nbJ);
                    printf("%d",j_Oponente[i][j]);
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
                if(j_Flota[i][j]=='B'||j_Flota[i][j]=!'*'){
                    printf("tocado");
                    j_Flota[i][j]='T';
                    j_Oponente[i][j]='T';
                    printf("%d",j_Oponente[i][j]);
                    chequeoH(j_Flota[i][j],j_Oponente[i][j],barcosJ,nbJ);
                    printf("%d",j_Oponente[i][j]);
                   }
                }else{
                    printf("fallo");
                    j_Flota[i][j]='*';
                    j_Oponente[i][j]='*';
                    printf("%d",j_Oponente[i][j]);
                }
                
                }
            }while(j_Flota[i][j]=='B'||j_Flota[i][j]=!'*')

            }
        }

    }
    turnos++;
    if(nbJ=0){
        fin = 0;
    }
}
void chequeoH(int i, int j, char **j_Flota, char **j_Oponente, Barcos *barcos, int *nBar) {
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
