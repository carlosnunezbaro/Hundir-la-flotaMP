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




int Imprimr_Tablero_1(int fila, int columnas, char **tablero1);
int Imprimir_Tablero_2(int filas, int columnas, char **tablero2);
int Intentar_Colocar_1(int filas, int columnas, char **tablero1, Barco *barco);
int Colocar_Barcos_1(int filas, int columnas, char **tablero1, Barco *barco);
int Barcos_Pegados_1(int filas, int columnas, char **tablero1, Barco *barco);
int Intentar_Colocar_Tablero2(int filas, int columnas, char **tablero2, Barco *barco);
int Colocar_Barcos_Tablero_2(int filas, int columnas, char **tablero2, Barco *barco);
int Barcos_Pegados_Tablero_2(int filas, int columnas, char **tablero2, Barco *barco);


int_Imprimir_Tablero_2(int filas, int columnas, char **tablero2) {
    int i,j;
    for(i=0; i<filas; i++) {
        for (j=0; j<columnas; j++)
        printf("%c", tablero2[i][j]);
    }
}


int Imprimr_Tablero_1(int filas, int columnas, char **tablero1) {

    int i,j;

    for (i=0; i<filas; i++){
        for (j=0; j<columnas; j++)
        printf("%c", tablero1[i][j]);

    }
    printf("\n");
}

int Intentar_Colocar_2(int filas, int columnas, char **tablero2, Barco *barco) {
    int i,j;

    // Horizontal (izquierda derecha)
    if (barco->orientacion == 'H') {
        if (barco->y + barco->longitud > columnas) {
            printf("!No se ha podido colocar un barco en esa posicion!\n");
            return 0;
        }
        for( i= 0; i< barco->longitud; i++) {
            if(tablero2[barco->x][barco->y + i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion\n");
                return 0;
            }
        }
    } 
    else if (barco->orientacion == 'H-') {
        if (barco->y - barco->longitud < 0) {
            printf("!No se ha podido colocar el barco!\n");
            return 0;
        }
        for (i=0; i < barco->longitud; i++){
            if(tablero2[i][j !=0]) {
                printf("!No se ha podido colocar el barco!\n");
                return 0;
            }
        }
    }
    else if (barco->orientacion == 'V') {
        if (barco->x + barco->longitud > filas){
            printf("!No se ha podido colocar el barco!\n");
            return 0;
        }
        for (i=0; i < filas; i++) {
            if(tablero2[i][j] != 0){
                printf("!No se ha podido colocar el barco!\n");
            }
        }
    }
    else if (barco->orientacion == 'V-') {
        if (barco->x - barco->longitud < 0) {
            printf("!No se ha podido colocar el barco!\n");
            return 0;
        }
        for (i=0; i < filas ; i++) {
            if (tablero2[i][j]= !0) {
                printf("!No se ha podido colocar el barco!\n");
                return 0;
            }
        }
    }
    // Diagonal  (izq-arriba  der-abajo)
    else if (barco->orientacion == 'D') {
        if (barco->x + barco->longitud > filas || barco->y + barco->longitud > columnas) {
            printf("!No se ha podido colocar un barco en esa posicion!\n");
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero2[barco->x + i][barco->y + i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }
    else if (barco->orientacion == 'D-') {
        if (barco->x - barco->longitud < 0 || barco->y - barco->longitud < 0) {  // 
            printf("!No se ha podido colocar un barco en esa posicion!\n"); 
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero2[barco->x - i][barco->y - i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }

    return 1; // El barco se ha colocado correctamente
}   


int Intentar_Colocar_1(int filas, int columnas, char **tablero1, Barco *barco) {
    int i;

    // Horizontal (izquierda  derecha)
    if (barco->orientacion == 'H') {
        if (barco->y + barco->longitud > columnas) {
            printf("!No se ha podido colocar un barco en esa posicion!\n"); 
            return 0;
        }
        for (i = 0; i < barco->longitud; i++)
            if (tablero1[barco->x][barco->y + i] != 0) {
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
            if (tablero1[barco->x][barco->y - i] != 0) {
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
            if (tablero1[barco->x + i][barco->y] != 0) {
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
            if (tablero1[barco->x - i][barco->y] != 0) {
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
            if (tablero1[barco->x + i][barco->y + i] != 0) {
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
            if (tablero1[barco->x - i][barco->y - i] != 0) {
                printf("!No se ha podido colocar un barco en esa posicion!\n");
                return 0;
            }
    }

    return 1; // El barco se ha colocado correctamente
}


int Colocar_Barco_1(int filas, int columnas, char **tablero1, Barco *barco) {
    int i;
    
    if (Intentar_Colocar_1(filas, columnas, tablero1, barco)) {
        if (barco->orientacion == 'H') {  
            for (i = 0; i < barco->longitud; i++)
                tablero1[barco->x][barco->y + i] = 1;
        } 
        else if (barco->orientacion == 'H-') {  
            for (i = 0; i < barco->longitud; i++)
                tablero1[barco->x][barco->y - i] = 1;
        } 
        else if (barco->orientacion == 'V') {  
            for (i = 0; i < barco->longitud; i++)
                tablero1[barco->x + i][barco->y] = 1;
        } 
        else if (barco->orientacion == 'V-') {  
            for (i = 0; i < barco->longitud; i++)
                tablero1[barco->x - i][barco->y] = 1;
        } 
        else if (barco->orientacion == 'D') {  
            for (i = 0; i < barco->longitud; i++)
                tablero1[barco->x + i][barco->y + i] = 1;
        } 
        else if (barco->orientacion == 'D-') {  
            for (i = 0; i < barco->longitud; i++)
                tablero1[barco->x - i][barco->y - i] = 1;
        }

        return 1;  // Barco colocado con exito
    }

    printf("No se ha podido colocar el barco\n");
    return 0;
}

    


int Barcos_Pegados_1(int filas, int columnas, char **tablero1, Barco *barco) {
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
            if (tablero1[i][j] != 0) {
                printf("No puedes colocar un barco al lado de otro.\n");
                return 0;  // No se puede colocar el barco
            }
        }
    }

    return 1;  // Se puede colocar el barco
}
