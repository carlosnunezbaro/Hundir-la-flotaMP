#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "estado-barcos.h"


typedef struct {

    int longitud;
    char orientacion[3];
    int x;
    int y;
    int impactos;

} Barco ;




int Imprimr_Tablero(int fila, int columnas, char **tablero);
int Intentar_Colocar(int filas, int columnas, char **tablero, int *flota_total, Barco *barco);
int Colocar_Barcos(int filas, int columnas, char **tablero, Barco *barco);
int Barcos_Pegados(int filas, int columnas, char **tablero, Barco *barco);
int Colocar_Barcos_BOT(int filas, int columnas, char **tablero, int *flota_total, Barco *barco);


// Implementación de funciones
int Imprimir_Tablero(int filas, int columnas, char **tablero) {
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%c ", tablero[i][j]); // Imprime con un espacio opcional
        }
        printf("\n");  // Añadir salto de línea después de cada fila
    }
    return 0;  // Añadir un valor de retorno
}

int Intentar_Colocar(int filas, int columnas, char **tablero1, int *flota_total, Barco *barco) {
    int i;
    int colocado = 0;

    while (colocado<flota_total) {
        if (strcmp(barco->orientacion, "H") == 0) {  // Horizontal
            if (barco->y + barco->longitud > columnas) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x][barco->y + i] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "H-") == 0) {  // Horizontal inverso
            if (barco->y - barco->longitud < 0) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x][barco->y - i] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "V") == 0) {  // Vertical
            if (barco->x + barco->longitud > filas) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x + i][barco->y] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "V-") == 0) {  // Vertical inverso
            if (barco->x - barco->longitud < 0) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x - i][barco->y] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "D") == 0) {  // Diagonal (abajo-derecha)
            if (barco->x + barco->longitud > filas || barco->y + barco->longitud > columnas) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x + i][barco->y + i] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "D-") == 0) {  // Diagonal (arriba-izquierda)
            if (barco->x - barco->longitud < 0 || barco->y - barco->longitud < 0) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x - i][barco->y - i] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "D1") == 0) {  // Diagonal (abajo-izquierda)
            if (barco->x + barco->longitud > filas || barco->y - barco->longitud < 0) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x + i][barco->y - i] != ' ') return 0;
            }
        } else if (strcmp(barco->orientacion, "D1-") == 0) {  // Diagonal (arriba-derecha)
            if (barco->x - barco->longitud < 0 || barco->y + barco->longitud > columnas) return 0;
            for (i = 0; i < barco->longitud; i++) {
                if (tablero1[barco->x - i][barco->y + i] != ' ') return 0;
            }
        }
    
        return 1;  // El barco puede ser colocado

    }
    
}
int Colocar_Barco(int filas, int columnas, char **tablero, Barco *barco) {
    int i;

    if (Intentar_Colocar(filas, columnas, tablero, flota_total, barco)) {
        if (strcmp(barco->orientacion, "H") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x][barco->y + i] = 'B';
            }
        } else if (strcmp(barco->orientacion, "H-") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x][barco->y - i] = 'B';
            }
        } else if (strcmp(barco->orientacion, "V") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x + i][barco->y] = 'B';
            }
        } else if (strcmp(barco->orientacion, "V-") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x - i][barco->y] = 'B';
            }
        } else if (strcmp(barco->orientacion, "D") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x + i][barco->y + i] = 'B';
            }
        } else if (strcmp(barco->orientacion, "D-") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x - i][barco->y - i] = 'B';
            }
        } else if (strcmp(barco->orientacion, "D1") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x + i][barco->y - i] = 'B';
            }
        } else if (strcmp(barco->orientacion, "D1-") == 0) {
            for (i = 0; i < barco->longitud; i++) {
                tablero[barco->x - i][barco->y + i] = 'B';
            }
        }

        return 1;  // Barco colocado con éxito
    }

    printf("No se ha podido colocar el barco\n");
    return 0;

}

int Colocar_Barcos_BOT(int filas, int columnas, char **tablero, int *flota_total, Barco *barcos) {
    srand(time(NULL));  // Inicializar la semilla del generador de números aleatorios

    for (int i = 0; i < flota_total; i++) {
        Barco *barco = &barcos[i];
        int colocado = 0;

        while (!colocado) {
            // Generar aleatoriamente posición, orientación y longitud
            barco->x = rand() % filas;
            barco->y = rand() % columnas;

            // Seleccionar orientación aleatoria entre las 8 posibles
            const char *orientaciones[] = {"H", "H-", "V", "V-", "D", "D-", "D1", "D1-"};
            strcpy(barco->orientacion, orientaciones[rand() % 8]);

            // Comprobar si se puede colocar el barco
            if (Intentar_Colocar(filas, columnas, tablero, flota_total, barco) && Barcos_Pegados(filas, columnas, tablero, barco)) {
                Colocar_Barco(filas, columnas, tablero, barco);
                colocado = 1;  // Marcar como colocado
            }
        }
    }

    return 1;  // Todos los barcos colocados con éxito
}