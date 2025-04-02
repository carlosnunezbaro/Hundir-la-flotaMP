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

    // Horizontal (izquierda  derecha)
    if (barco->orientacion == 'H') {
        if (barco->y + barco->longitud > columnas) {
            printf("!No se ha podido colocar un barco en esa posicion!\n"); 
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero[barco->x][barco->y + i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }
    // Horizontal inverso (derecha  izquierda)
    else if (barco->orientacion == 'H-') {
        if (barco->y - barco->longitud < 0) {  //
            printf("!No se ha podido colocar un barco en esa posicion!\n"); 
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero[barco->x][barco->y - i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }
    // Vertical (arriba  abajo)
    else if (barco->orientacion == 'V') {
        if (barco->x + barco->longitud > filas) {
            printf("!No se ha podido colocar un barco en esa posicion!\n");
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero[barco->x + i][barco->y] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }
    // Vertical inverso (abajo  arriba)
    else if (barco->orientacion == 'V-') {
        if (barco->x - barco->longitud < 0) {  // 
            printf("!No se ha podido colocar un barco en esa posicion!\n"); 
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero[barco->x - i][barco->y] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }
    // Diagonal  (izq-arriba  der-abajo)
    else if (barco->orientacion == 'D') {
        if (barco->x + barco->longitud > filas || barco->y + barco->longitud > columnas) {
            printf("!No se ha podido colocar un barco en esa posicion!\n");
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero[barco->x + i][barco->y + i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }
    // Diagonal inversa (der-arriba izq-abajo)
    else if (barco->orientacion == 'D-') {
        if (barco->x - barco->longitud < 0 || barco->y - barco->longitud < 0) {  // 
            printf("!No se ha podido colocar un barco en esa posicion!\n"); 
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero[barco->x - i][barco->y - i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }

    return 1; // El barco se ha colocado correctamente
}


int Colocar_Barco(int filas, int columnas, int tablero[filas][columnas], Barco *barco) {
    int i;
    
    if (Intentar_Colocar(filas, columnas, tablero, barco)) {
        if (barco->orientacion == 'H') {  
            for (i = 0; i < barco->longitud; i++)
                tablero[barco->x][barco->y + i] = 1;
        } 
        else if (barco->orientacion == 'H-') {  
            for (i = 0; i < barco->longitud; i++)
                tablero[barco->x][barco->y - i] = 1;
        } 
        else if (barco->orientacion == 'V') {  
            for (i = 0; i < barco->longitud; i++)
                tablero[barco->x + i][barco->y] = 1;
        } 
        else if (barco->orientacion == 'V-') {  
            for (i = 0; i < barco->longitud; i++)
                tablero[barco->x - i][barco->y] = 1;
        } 
        else if (barco->orientacion == 'D') {  
            for (i = 0; i < barco->longitud; i++)
                tablero[barco->x + i][barco->y + i] = 1;
        } 
        else if (barco->orientacion == 'D-') {  
            for (i = 0; i < barco->longitud; i++)
                tablero[barco->x - i][barco->y - i] = 1;
        }

        return 1;  // Barco colocado con exito
    }

    printf("No se ha podido colocar el barco\n");
    return 0;
}

    


int Barcos_Pegados(int filas, int columnas, int tablero[filas][columnas], Barco *barco) {
    int inicial_x, inicial_y, final_x, final_y, i, j;

    // Limites iniciales del barco
    inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
    inicial_y = (barco->y > 0) ? barco->y - 1 : 0;

    // Ajustar los limites segun la orientacion del barco
    if (barco->orientacion == 'V') {
        final_x = barco->x + barco->longitud;
        final_y = barco->y + 1;
    } else if (barco->orientacion == 'V-') {  // Abajo a Arriba
        final_x = barco->x - barco->longitud;
        final_y = barco->y + 1;
    } else if (barco->orientacion == 'H') {
        final_x = barco->x + 1;
        final_y = barco->y + barco->longitud;
    } else if (barco->orientacion == 'H-') {  // Derecha a Izquierda
        final_x = barco->x + 1;
        final_y = barco->y - barco->longitud;
    } else if (barco->orientacion == 'D') {  // Diagonal  (Superior Izquierda a Inferior Derecha)
        final_x = barco->x + barco->longitud;
        final_y = barco->y + barco->longitud;
    } else if (barco->orientacion == 'D-') {  // Diagonal  (Superior Derecha a Inferior Izquierda)
        final_x = barco->x - barco->longitud;
        final_y = barco->y - barco->longitud;
   
    }

    // Limites del tablero
    if (final_x >= filas) final_x = filas - 1;
    if (final_x < 0) final_x = 0;
    if (final_y >= columnas) final_y = columnas - 1;
    if (final_y < 0) final_y = 0;

    // Recorrer la zona y verificar si hay barcos cercanos
    for (i = inicial_x; i <= final_x; i++) {
        for (j = inicial_y; j <= final_y; j++) {
            if (tablero[i][j] != 0) {
                printf("No puedes colocar un barco al lado de otro.\n");
                return 0;  // No se puede colocar el barco
            }
        }
    }

    return 1;  // Se puede colocar el barco
}
