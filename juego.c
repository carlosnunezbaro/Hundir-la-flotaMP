#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "estado-barcos.h"

void inicializar_juego(EstadoJuego *estado_juego, int filas, int columnas) {
    estado_juego->filas = filas;
    estado_juego->columnas = columnas;
    estado_juego->tablero = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        estado_juego->tablero[i] = (int *)malloc(columnas * sizeof(int));
        memset(estado_juego->tablero[i], 0, columnas * sizeof(int));
    }
    estado_juego->barcos_hundidos = 0;
    estado_juego->disparos_realizados = 0;

    // Llamar a la función para colocar los barcos
    Colocar_Barcos(filas, columnas, estado_juego->tablero);
}

void reiniciar_juego(EstadoJuego *estado_juego) {
    for (int i = 0; i < estado_juego->filas; i++) {
        free(estado_juego->tablero[i]);
    }
    free(estado_juego->tablero);
    inicializar_juego(estado_juego, estado_juego->filas, estado_juego->columnas);
}

void guardar_juego(const EstadoJuego *estado_juego, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para guardar");
        return;
    }
    fwrite(&estado_juego->filas, sizeof(int), 1, archivo);
    fwrite(&estado_juego->columnas, sizeof(int), 1, archivo);
    for (int i = 0; i < estado_juego->filas; i++) {
        fwrite(estado_juego->tablero[i], sizeof(int), estado_juego->columnas, archivo);
    }
    fwrite(&estado_juego->barcos_hundidos, sizeof(int), 1, archivo);
    fwrite(&estado_juego->disparos_realizados, sizeof(int), 1, archivo);
    fclose(archivo);
}

void cargar_juego(EstadoJuego *estado_juego, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para cargar");
        return;
    }
    fread(&estado_juego->filas, sizeof(int), 1, archivo);
    fread(&estado_juego->columnas, sizeof(int), 1, archivo);
    estado_juego->tablero = (int **)malloc(estado_juego->filas * sizeof(int *));
    for (int i = 0; i < estado_juego->filas; i++) {
        estado_juego->tablero[i] = (int *)malloc(estado_juego->columnas * sizeof(int));
        fread(estado_juego->tablero[i], sizeof(int), estado_juego->columnas, archivo);
    }
    fread(&estado_juego->barcos_hundidos, sizeof(int), 1, archivo);
    fread(&estado_juego->disparos_realizados, sizeof(int), 1, archivo);
    fclose(archivo);
}

void mostrar_resumen(const EstadoJuego *estado_juego) {
    printf("Resumen de la partida:\n");
    printf("Barcos hundidos: %d\n", estado_juego->barcos_hundidos);
    printf("Disparos realizados: %d\n", estado_juego->disparos_realizados);
    // Mostrar estado del tablero u otra información si es necesario
}

void jugar(EstadoJuego *estado_juego) {
    int x, y;
    char continuar;
    do {
        printf("Introduce las coordenadas para disparar (x y): ");
        scanf("%d %d", &x, &y);
        estado_juego->disparos_realizados++;
        if (estado_juego->tablero[x][y] == 1) {
            printf("¡Tocado!\n");
            estado_juego->tablero[x][y] = 2; // Marcar como tocado
            estado_juego->barcos_hundidos++;
        } else {
            printf("Agua...\n");
        }
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

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
                guardar_juego(estado_juego, "partida_guardada.dat");
                break;
            case 5:
                cargar_juego(estado_juego, "partida_guardada.dat");
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
        free(estado_juego->tablero[i]);
    }
    free(estado_juego->tablero);

    return 0;
}