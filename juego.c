#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "estado-barcos.h"
#include "disparo.h"

// Inicializa el estado del juego con el número de filas y columnas especificado
void inicializar_juego(EstadoJuego *estado_juego, int filas, int columnas) {
    estado_juego->filas = filas;
    estado_juego->columnas = columnas;

    estado_juego->tablero_jugador1 = (int **)malloc(filas * sizeof(int *));
    estado_juego->tablero_jugador2 = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        estado_juego->tablero_jugador1[i] = (int *)malloc(columnas * sizeof(int));
        estado_juego->tablero_jugador2[i] = (int *)malloc(columnas * sizeof(int));
        memset(estado_juego->tablero_jugador1[i], 0, columnas * sizeof(int));
        memset(estado_juego->tablero_jugador2[i], 0, columnas * sizeof(int));
    }

    estado_juego->barcos_hundidos_jugador1 = 0;
    estado_juego->barcos_hundidos_jugador2 = 0;
    estado_juego->disparos_realizados_jugador1 = 0;
    estado_juego->disparos_realizados_jugador2 = 0;
    estado_juego->partida_finalizada = 0;

    // Llamar a la función para colocar los barcos para ambos jugadores
    Colocar_Barcos(filas, columnas, estado_juego->tablero_jugador1);
    Colocar_Barcos(filas, columnas, estado_juego->tablero_jugador2);
}

// Reinicia el juego liberando la memoria del tablero actual y re-inicializando el tablero con las mismas dimensiones
void reiniciar_juego(EstadoJuego *estado_juego) {
    for (int i = 0; i < estado_juego->filas; i++) {
        free(estado_juego->tablero_jugador1[i]);
        free(estado_juego->tablero_jugador2[i]);
    }
    free(estado_juego->tablero_jugador1);
    free(estado_juego->tablero_jugador2);
    inicializar_juego(estado_juego, estado_juego->filas, estado_juego->columnas);
}

// Guarda el estado actual del juego en un archivo con el nombre especificado, en formato CSV
void guardar_juego(const EstadoJuego *estado_juego, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para guardar");
        return;
    }

    // Guardar las dimensiones del tablero
    fprintf(archivo, "%d,%d\n", estado_juego->filas, estado_juego->columnas);
    
    // Guardar el tablero del Jugador 1
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; j < estado_juego->columnas; j++) {
            fprintf(archivo, "%d", estado_juego->tablero_jugador1[i][j]);
            if (j < estado_juego->columnas - 1) {
                fprintf(archivo, ",");
            }
        }
        fprintf(archivo, "\n");
    }

    // Guardar el tablero del Jugador 2
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; j < estado_juego->columnas; j++) {
            fprintf(archivo, "%d", estado_juego->tablero_jugador2[i][j]);
            if (j < estado_juego->columnas - 1) {
                fprintf(archivo, ",");
            }
        }
        fprintf(archivo, "\n");
    }

    // Guardar el número de barcos hundidos y disparos realizados para ambos jugadores
    fprintf(archivo, "%d,%d\n", estado_juego->barcos_hundidos_jugador1, estado_juego->disparos_realizados_jugador1);
    fprintf(archivo, "%d,%d\n", estado_juego->barcos_hundidos_jugador2, estado_juego->disparos_realizados_jugador2);

    // Guardar el estado de la partida
    fprintf(archivo, "%d\n", estado_juego->partida_finalizada);
    
    fclose(archivo);
}

// Carga el estado del juego desde un archivo con el nombre especificado, en formato CSV
void cargar_juego(EstadoJuego *estado_juego, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para cargar");
        return;
    }

    // Leer las dimensiones del tablero
    fscanf(archivo, "%d,%d\n", &estado_juego->filas, &estado_juego->columnas);

    // Reservar memoria para los tableros
    estado_juego->tablero_jugador1 = (int **)malloc(estado_juego->filas * sizeof(int *));
    estado_juego->tablero_jugador2 = (int **)malloc(estado_juego->filas * sizeof(int *));
    for (int i = 0; i < estado_juego->filas; i++) {
        estado_juego->tablero_jugador1[i] = (int *)malloc(estado_juego->columnas * sizeof(int));
        estado_juego->tablero_jugador2[i] = (int *)malloc(estado_juego->columnas * sizeof(int));
    }

    // Leer el tablero del Jugador 1
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; j < estado_juego->columnas; j++) {
            fscanf(archivo, "%d", &estado_juego->tablero_jugador1[i][j]);
            if (j < estado_juego->columnas - 1) {
                fgetc(archivo); // Leer la coma
            }
        }
        fgetc(archivo); // Leer el salto de línea
    }

    // Leer el tablero del Jugador 2
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; j < estado_juego->columnas; j++) {
            fscanf(archivo, "%d", &estado_juego->tablero_jugador2[i][j]);
            if (j < estado_juego->columnas - 1) {
                fgetc(archivo); // Leer la coma
            }
        }
        fgetc(archivo); // Leer el salto de línea
    }

    // Leer el número de barcos hundidos y disparos realizados para ambos jugadores
    fscanf(archivo, "%d,%d\n", &estado_juego->barcos_hundidos_jugador1, &estado_juego->disparos_realizados_jugador1);
    fscanf(archivo, "%d,%d\n", &estado_juego->barcos_hundidos_jugador2, &estado_juego->disparos_realizados_jugador2);

    // Leer el estado de la partida
    fscanf(archivo, "%d\n", &estado_juego->partida_finalizada);
    
    fclose(archivo);
}

// Muestra un resumen del juego, incluyendo el número de barcos hundidos y disparos realizados
void mostrar_resumen(const EstadoJuego *estado_juego) {
    printf("Resumen de la partida:\n");

    if (!estado_juego->partida_finalizada) {
        printf("Sin datos definitivos, por favor acaba con la flota enemiga.\n");
        return;
    }

    printf("Barcos hundidos Jugador 1: %d\n", estado_juego->barcos_hundidos_jugador1);
    printf("Disparos realizados Jugador 1: %d\n", estado_juego->disparos_realizados_jugador1);

    printf("Barcos hundidos Jugador 2: %d\n", estado_juego->barcos_hundidos_jugador2);
    printf("Disparos realizados Jugador 2: %d\n", estado_juego->disparos_realizados_jugador2);

    printf("\nTablero Jugador 1:\n");
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; j < estado_juego->columnas; j++) {
            printf("%d ", estado_juego->tablero_jugador1[i][j]);
        }
        printf("\n");
    }

    printf("\nTablero Jugador 2:\n");
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; j < estado_juego->columnas; j++) {
            printf("%d ", estado_juego->tablero_jugador2[i][j]);
        }
        printf("\n");
    }
}

// Ejecuta la lógica del juego, permitiendo al jugador realizar disparos y actualizando el estado del juego en consecuencia
void jugar(EstadoJuego *estado_juego) {
    int x, y;
    char continuar;
    do {
        printf("Introduce las coordenadas para disparar (fila columna): ");
        scanf("%d %d", &x, &y);
        int resultado = disparoJ1(estado_juego->tablero_jugador2, estado_juego->disparos_realizados_jugador1, estado_juego->barcos_hundidos_jugador1, estado_juego->partida_finalizada);
        if (resultado == 1) {
            estado_juego->barcos_hundidos_jugador1++;
            printf("¡Tocado!\n");
        } else if (resultado == 0) {
            printf("Agua...\n");
        }
        estado_juego->disparos_realizados_jugador1++;
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

// Muestra el menú principal del juego, permitiendo al usuario seleccionar opciones como jugar, reiniciar, mostrar resumen, guardar y cargar el juego, o salir
void mostrar_menu(EstadoJuego *estado_juego) {
    int opcion;
    do {
        printf("Menu:\n");
        printf("1. Jugar\n");
        printf("2. Reiniciar partida\n");
        printf("3. Resumen de la partida\n");
        printf("4. Guardar partida\n");
        printf("5. Cargar partida\n");
        printf("6. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                jugar(estado_juego);
                break;
            case 2:
                reiniciar_juego(estado_juego);
                break;
            case 3:
                mostrar_resumen(estado_juego);
                break;
            case 4:
                guardar_juego(estado_juego, "partida_guardada.csv");
                break;
            case 5:
                cargar_juego(estado_juego, "partida_guardada.csv");
                break;
            case 6:
                printf("Saliendo del juego...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 6);
}

int main() {
    int filas, columnas;
    printf("Introduce el tamaño del tablero (filas columnas): ");
    scanf("%d %d", &filas, &columnas);

    EstadoJuego estado_juego;
    inicializar_juego(&estado_juego, filas, columnas);
    mostrar_menu(&estado_juego);

    // Liberar memoria al final del programa
    for (int i = 0; i < estado_juego.filas; i++) {
        free(estado_juego->tablero_jugador1[i]);
        free(estado_juego->tablero_jugador2[i]);
    }
    free(estado_juego->tablero_jugador1);
    free(estado_juego->tablero_jugador2);

    return 0;
}