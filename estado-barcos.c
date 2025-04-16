#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "configuracion_inicial.h"
#include "estado-barcos.h"

typedef struct {
    int longitud;
    char orientacion[3];
    int x;
    int y;
    int impactos;
} Barco;

int Imprimir_Tablero(int filas, int columnas, char **tablero);
int Intentar_Colocar(int filas, int columnas, char **tablero, Barco *barco);
int Colocar_Barco(int filas, int columnas, char **tablero, Barco *barco);
int Barcos_Pegados(int filas, int columnas, char **tablero, Barco *barco);
int Colocar_Barcos_BOT(int filas, int columnas, char **tablero, int flota_total, Barco *barcos);

int Imprimir_Tablero(int filas, int columnas, char **tablero) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int Intentar_Colocar(int filas, int columnas, char **tablero, Barco *barco) {
    if (strcmp(barco->orientacion, "H") == 0) {
        if (barco->y + barco->longitud > columnas) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x][barco->y + i] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "H-") == 0) {
        if (barco->y - barco->longitud < 0) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x][barco->y - i] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "V") == 0) {
        if (barco->x + barco->longitud > filas) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x + i][barco->y] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "V-") == 0) {
        if (barco->x - barco->longitud < 0) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x - i][barco->y] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "D") == 0) {
        if (barco->x + barco->longitud > filas || barco->y + barco->longitud > columnas) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x + i][barco->y + i] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "D-") == 0) {
        if (barco->x - barco->longitud < 0 || barco->y - barco->longitud < 0) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x - i][barco->y - i] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "D1") == 0) {
        if (barco->x + barco->longitud > filas || barco->y - barco->longitud < 0) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x + i][barco->y - i] != '-') return 0;
        }
    } else if (strcmp(barco->orientacion, "D1-") == 0) {
        if (barco->x - barco->longitud < 0 || barco->y + barco->longitud > columnas) return 0;
        for (int i = 0; i < barco->longitud; i++) {
            if (tablero[barco->x - i][barco->y + i] != '-') return 0;
        }
    }
    return 1;
}

int Colocar_Barco(int filas, int columnas, char **tablero, Barco *barco) {
    if (Intentar_Colocar(filas, columnas, tablero, barco)) {
        for (int i = 0; i < barco->longitud; i++) {
            if (strcmp(barco->orientacion, "H") == 0) tablero[barco->x][barco->y + i] = 'B';
            else if (strcmp(barco->orientacion, "H-") == 0) tablero[barco->x][barco->y - i] = 'B';
            else if (strcmp(barco->orientacion, "V") == 0) tablero[barco->x + i][barco->y] = 'B';
            else if (strcmp(barco->orientacion, "V-") == 0) tablero[barco->x - i][barco->y] = 'B';
            else if (strcmp(barco->orientacion, "D") == 0) tablero[barco->x + i][barco->y + i] = 'B';
            else if (strcmp(barco->orientacion, "D-") == 0) tablero[barco->x - i][barco->y - i] = 'B';
            else if (strcmp(barco->orientacion, "D1") == 0) tablero[barco->x + i][barco->y - i] = 'B';
            else if (strcmp(barco->orientacion, "D1-") == 0) tablero[barco->x - i][barco->y + i] = 'B';
        }
        return 1;
    }
    printf("No se ha podido colocar el barco\n");
    return 0;
}

int Barcos_Pegados(int filas, int columnas, char **tablero, Barco *barco) {
    int inicial_x, inicial_y, final_x, final_y;

    if (strcmp(barco->orientacion, "H") == 0) {
        inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
        inicial_y = (barco->y > 0) ? barco->y - 1 : 0;
        final_x = (barco->x < filas - 1) ? barco->x + 1 : filas - 1;
        final_y = (barco->y + barco->longitud < columnas) ? barco->y + barco->longitud : columnas - 1;
    } else if (strcmp(barco->orientacion, "H-") == 0) {
        inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
        inicial_y = (barco->y - barco->longitud > 0) ? barco->y - barco->longitud : 0;
        final_x = (barco->x < filas - 1) ? barco->x + 1 : filas - 1;
        final_y = (barco->y < columnas - 1) ? barco->y + 1 : columnas - 1;
    } else if (strcmp(barco->orientacion, "V") == 0) {
        inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
        inicial_y = (barco->y > 0) ? barco->y - 1 : 0;
        final_x = (barco->x + barco->longitud < filas) ? barco->x + barco->longitud : filas - 1;
        final_y = (barco->y < columnas - 1) ? barco->y + 1 : columnas - 1;
    } else if (strcmp(barco->orientacion, "V-") == 0) {
        inicial_x = (barco->x - barco->longitud > 0) ? barco->x - barco->longitud : 0;
        inicial_y = (barco->y > 0) ? barco->y - 1 : 0;
        final_x = (barco->x < filas - 1) ? barco->x + 1 : filas - 1;
        final_y = (barco->y < columnas - 1) ? barco->y + 1 : columnas - 1;
    } else if (strcmp(barco->orientacion, "D") == 0) {
        inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
        inicial_y = (barco->y > 0) ? barco->y - 1 : 0;
        final_x = (barco->x + barco->longitud < filas) ? barco->x + barco->longitud : filas - 1;
        final_y = (barco->y + barco->longitud < columnas) ? barco->y + barco->longitud : columnas - 1;
    } else if (strcmp(barco->orientacion, "D-") == 0) {
        inicial_x = (barco->x - barco->longitud > 0) ? barco->x - barco->longitud : 0;
        inicial_y = (barco->y - barco->longitud > 0) ? barco->y - barco->longitud : 0;
        final_x = (barco->x < filas - 1) ? barco->x + 1 : filas - 1;
        final_y = (barco->y < columnas - 1) ? barco->y + 1 : columnas - 1;
    } else if (strcmp(barco->orientacion, "D1") == 0) {
        inicial_x = (barco->x > 0) ? barco->x - 1 : 0;
        inicial_y = (barco->y - barco->longitud > 0) ? barco->y - barco->longitud : 0;
        final_x = (barco->x + barco->longitud < filas) ? barco->x + barco->longitud : filas - 1;
        final_y = (barco->y < columnas - 1) ? barco->y + 1 : columnas - 1;
    } else if (strcmp(barco->orientacion, "D1-") == 0) {
        inicial_x = (barco->x - barco->longitud > 0) ? barco->x - barco->longitud : 0;
        inicial_y = (barco->y > 0) ? barco->y - 1 : 0;
        final_x = (barco->x < filas - 1) ? barco->x + 1 : filas - 1;
        final_y = (barco->y + barco->longitud < columnas) ? barco->y + barco->longitud : columnas - 1;
    } else {
        return 0; // Orientación no válida
    }

    // Verificar el área alrededor del barco
    for (int i = inicial_x; i <= final_x; i++) {
        for (int j = inicial_y; j <= final_y; j++) {
            if (tablero[i][j] != ' ') return 0;
        }
    }
    return 1;
}


int Colocar_Barcos_BOT(int filas, int columnas, char **tablero, int flota_total, Barco *barcos) {
    srand(time(NULL));
    for (int i = 0; i < flota_total; i++) {
        Barco *barco = &barcos[i];
        int colocado = 0;
        int intentos = 0; // Contador de intentos
        const int max_intentos = 100; // Límite máximo de intentos para evitar bucles infinitos

        while (!colocado && intentos < max_intentos) {
            intentos++;
            barco->x = rand() % filas;
            barco->y = rand() % columnas;
            const char *orientaciones[] = {"H", "H-", "V", "V-", "D", "D-", "D1", "D1-"};
            strcpy(barco->orientacion, orientaciones[rand() % 8]);

            if (Intentar_Colocar(filas, columnas, tablero, barco) && Barcos_Pegados(filas, columnas, tablero, barco)) {
                Colocar_Barco(filas, columnas, tablero, barco);
                colocado = 1;
            }
        }

        if (intentos >= max_intentos) {
            return 0; // Retorna 0 si no se pudo colocar un barco
        }
    }
    return 1; // Retorna 1 si todos los barcos fueron colocados exitosamente
}