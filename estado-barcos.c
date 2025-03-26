#include <stdio.h>  
#include <stdlib.h>
#include "estado-barcos.h"

typedef struct {

    int longitud;
    char orientacion;
    int x;
    int y;
    int impactos;

} Barco ;




int Imprimr_Tablero(int filas, int columnas, int tablero[filas][columnas]);
int Intentar_Colocar(int filas, int columnas, int tablero[filas][columnas], Barco *barco);
int Colocar_Barcos(int filas, int columnas, int tablero[filas][columnas], Barco *barco);
int Barcos_Pegados(int filas, int columnas, int yablero[filas][columnas], Barco *barco);





int Imprimr_Tablero(int filas, int columnas, int tablero[filas][columnas]) {

    int i,j;

    for (i=0; i<filas; i++){
        for (j=0; j<columnas; j++)
        printf("%d ", tablero[i][j]);

    }
    printf("\n");
}

int Intentar_Colocar(int filas, int columnas, int tablero[filas][columnas], Barco *barco) {
    int i;
    if(barco->orientacion == 'H') {
        if  (barco->y + barco->longitud > columnas) //Si el barco se sale del tablero, no se podrá colocar
        return 0;
        for (i=0; i<barco->longitud; i++)
            if (tablero[barco->x][barco->y+i] !=0) {
        printf("!No se ha podido colocar un barco en esa posición!\n"); // Si el espacio ya esta ocupado, no se podrá poner otro barco
        return 0;
        
        
      }
}
    else if (barco->orientacion == 'V') {
        if (barco->x + barco->longitud > filas) // Si el barco se sale del tablero, no se podrá colocar 
        return 0;
    for (i=0; i < barco->longitud; i++)
        if (tablero[barco->y][barco->x +i] !=0) {
         
            printf("!No se ha podido colocar un barco en esa posición!\n");
            return 0;
        }
        
    else if (barco->orientacion == 'D') {
        if (barco->x + barco->longitud > filas || barco->y + barco->longitud > columnas) 
        return 0;
    for (i=0; i<barco->longitud;i++)    
        if (tablero[barco->x + i][barco->y + i] !=0) {
            printf("!No se ha podido colocar un barco en esa posición!\n"); // De forma diagonal 
            return 0;
           
         } 
     }  


    } 
return 1; // Si se han podido colocar los barcos
     
}

Colocar_Barco(int filas, int columnas, int tablero[filas][columnas], Barco *barco) {
    int i;
    if(Intentar_Colocar(filas,columnas,tablero,barco)) {
        if(barco->orientacion == 'H') {
            for(i=0; i < barco->longitud; i++)
                tablero[barco->x][barco->y+i] = 1;
        }
        else if (barco->orientacion == 'V') {
            for(i=0;i<barco->longitud; i++)
                tablero[barco->x+i][barco->y] = 1;
        }
        else if (barco->orientacion == 'D') {
            for(i=0; i< barco->longitud; i++)
            tablero[barco->x+i][barco->y+i] = 1;
        }

    return 1;

    }

printf("No se ha podido colocoar el barco\n");
return 0;
    
}

int Barcos_Pegados(int filas, int columnas, int yablero[filas][columnas], Barco *barco) {

    int inicial_x, inicial_y, final_x, final_y, i,j;

    inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
    inicial_y = (barco->y > 0) ? barco->y - 1 : 0;
    final_x = (barco->orientacion == 'V') ? barco->x + barco->longitud : barco->x + 1;
    final_y = (barco->orientacion == 'H') ? barco->y + barco->longitud : barco->y + 1;

    // Esta comprobacion tiene que estar acorde con los limites del tablero

    if (final_x >= filas)
        final_x = filas -1;
    if (final_y >= columnas)
        final_y = columnas - 1;

    // Recorrer la zona que esta alrededor del barco y comprobar si hay otro barco

    for (i = inicial_x; i <= final_x; i++) {
        for (j = inicial_y; j<= final_y; j++)
        if (tablero[i][j] !=0){
            printf("No puedes colocar un barco al lado de otro \n");
            return 0;
        }
      return 1; // Si se ha podido colocar el barco
    }
}



