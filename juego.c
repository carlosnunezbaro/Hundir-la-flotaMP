#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "estado_barcos.h"
#include "Disparo.h"

// Inicializa el estado del juego con el número de filas y columnas especificado
void inicializar_juego(EstadoJuego *estado_juego, const ConfiguracionJuego *configuracion) {
    int filas = configuracion->tamano_tablero;
    int columnas = configuracion->tamano_tablero;
    
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
void reiniciar_juego(EstadoJuego *estado_juego, const ConfiguracionJuego *configuracion) {
    for (int i = 0; i < estado_juego->filas; i++) {
        free(estado_juego->tablero_jugador1[i]);
        free(estado_juego->tablero_jugador2[i]);
    }
    free(estado_juego->tablero_jugador1);
    free(estado_juego->tablero_jugador2);
    inicializar_juego(estado_juego, configuracion);
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
        for (int j = 0; j < estado_juego->columnas; i++) {
            printf("%d ", estado_juego->tablero_jugador1[i][j]);
        }
        printf("\n");
    }

    printf("\nTablero Jugador 2:\n");
    for (int i = 0; i < estado_juego->filas; i++) {
        for (int j = 0; i < estado_juego->columnas; i++) {
            printf("%d ", estado_juego->tablero_jugador2[i][j]);
        }
        printf("\n");
    }
}

// Ejecuta la lógica del juego, permitiendo al jugador realizar disparos y actualizando el estado del juego en consecuencia
void jugar(EstadoJuego *estado_juego) {
    int x, y;
    char continuar = 's';

    printf("La partida ha comenzado. Pulsa la barra espaciadora para abrir el menú de pausa.\n");

    while (continuar == 's' || continuar == 'S') {
        // Verificar si hay una tecla pulsada
        if (kbhit()) {
            char tecla = getch(); // Capturar la tecla pulsada

            // Si la tecla es la barra espaciadora
            if (tecla == ' ') {
                menu_pausa(estado_juego);
            }
        }

        // Turno del jugador 1
        printf("Turno del jugador 1.\n");
        printf("Introduce las coordenadas para disparar (fila columna): ");
        scanf("%d %d", &x, &y);

        // Llama a la lógica de disparo del jugador 1
        disparoJ1(estado_juego->filas, estado_juego->columnas, estado_juego->tablero_jugador2,
                  estado_juego->disparos_realizados_jugador1, estado_juego->barcos_hundidos_jugador2,
                  estado_juego->partida_finalizada);

        // Verificar si el jugador 1 ha ganado
        if (estado_juego->barcos_hundidos_jugador2 == 0) {
            printf("¡El jugador 1 ha ganado la partida!\n");
            break;
        }

        // Turno del jugador 2 o IA
        printf("Turno del jugador 2.\n");

        if (estado_juego->contra_ia) {
            // Si es contra IA, llama a disparoIA
            disparoIA(estado_juego->tablero_jugador1, estado_juego->disparos_realizados_jugador2,
                      estado_juego->barcos_hundidos_jugador1, estado_juego->partida_finalizada);
        } else {
            // Si es contra otro jugador, captura las coordenadas
            printf("Introduce las coordenadas para disparar (fila columna): ");
            scanf("%d %d", &x, &y);

            // Llama a la lógica de disparo del jugador 2
            disparoJ2(estado_juego->filas, estado_juego->columnas, estado_juego->tablero_jugador1,
                      estado_juego->disparos_realizados_jugador2, estado_juego->barcos_hundidos_jugador1,
                      estado_juego->partida_finalizada);
        }

        // Verificar si el jugador 2 (o IA) ha ganado
        if (estado_juego->barcos_hundidos_jugador1 == 0) {
            printf("¡El jugador 2 ha ganado la partida!\n");
            break;
        }

        // Preguntar si se quiere continuar jugando
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);
    }
}
// Muestra el menú principal del juego, permitiendo al usuario seleccionar opciones como jugar, reiniciar, mostrar resumen, cargar el juego o salir
void mostrar_menu(EstadoJuego *estado_juego) {
    int opcion;
    ConfiguracionJuego configuracion;
    
    do {
        printf("Menu:\n");
        printf("1. Jugar\n");
        printf("2. Cargar partida\n");
        printf("3. Resumen de la partida\n");
        printf("4. Reiniciar partida\n");
        printf("5. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                // Permite cambiar la configuración y reiniciar la partida desde cero
                introducir_datos(&configuracion);
                inicializar_juego(estado_juego, &configuracion);
                jugar(estado_juego);
                break;
            case 2:
                cargar_juego(estado_juego, "partida_guardada.csv");
                break;
            case 3:
                mostrar_resumen(estado_juego);
                break;
            case 4:
                // Inicia una nueva partida con la configuración existente, permitiendo nueva colocación de barcos
                reiniciar_juego(estado_juego, &configuracion);
                jugar(estado_juego);
                break;
            case 5:
                printf("Saliendo del juego...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 5);
}

// Abre un menú durante la partida al pulsar la barra espaciadora, permitiendo guardar la partida, continuar jugando o salir al menú principal
void menu_pausa(EstadoJuego *estado_juego) {
    int opcion;
    char guardar;
    do {
        printf("Menu de Pausa:\n");
        printf("1. Volver a la partida\n");
        printf("2. Guardar partida\n");
        printf("3. Salir al menu principal\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                return;
            case 2:
                printf("Introduce el nombre del archivo para guardar la partida: ");
                char nombre_archivo[100];
                scanf("%s", nombre_archivo);
                guardar_juego(estado_juego, nombre_archivo);
                break;
            case 3:
                printf("¿Quieres guardar la partida antes de salir al menú principal? (s/n): ");
                scanf(" %c", &guardar);
                if (guardar == 's' || guardar == 'S') {
                    printf("Introduce el nombre del archivo para guardar la partida: ");
                    scanf("%s", nombre_archivo);
                    guardar_juego(estado_juego, nombre_archivo);
                }
                printf("Saliendo al menú principal...\n");
                return;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while (1);
}