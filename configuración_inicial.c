// Archivo: configuracion_inicial.c
// Implementación de las funciones para la configuración inicial

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion_inicial.h"
#include "juego.h"

// Función para inicializar el juego
int configuracion_inicial() {
    // Inicializar estructuras y variables necesarias
    Jugador jugador1 = {0};
    Jugador jugador2 = {0};
    Barco *flota = NULL;
    int num_barcos = 0;
    int flota_total = 0;
    int tamano_tablero = 0;
    
    // Tableros
    char **j1_Flota = NULL;
    char **j1_Oponente = NULL;
    char **j2_Flota = NULL;
    char **j2_Oponente = NULL;
    
    // Asignar IDs a los jugadores
    jugador1.Id_jugador = 1;
    jugador2.Id_jugador = 2;

    //Estructura para juego.h
    EstadoJuego estado_juego;
    ConfiguracionJuego configuracion;

    // Mensaje de bienvenida
    printf("Bienvenido al juego\n");
    printf("HUNDIR LA FLOTA\n");
    printf("-------------------\n\n");

    // Menú de configuración
    printf("Menú\n");
    printf("Hundir la flota\n");
    printf("-------------------\n");
    printf("1. Configuración\n");
    printf("2. Jugar\n");
    printf("3. Salir\n");

    int opcion; // Selección de la opción del menú
    do {
        printf("Introduce una opción: (1, 2 o 3) ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 3);

    switch (opcion) {
        case 1:
            configuracion(&jugador1, &jugador2, &flota, &num_barcos, &flota_total, 
                         &j1_Flota, &j1_Oponente, &j2_Flota, &j2_Oponente, &tamano_tablero);
            break;
        case 2:
            inicializar_juego(&estado_juego, &configuracion);
            break;
        case 3:
            salir();
            break;
    }

    // Liberar memoria cuando se termine el juego
    if (flota != NULL) {
        free(flota);
    }
    
    // Liberar memoria de los tableros si han sido inicializados
    if (j1_Flota != NULL) {
        for (int i = 0; i < tamano_tablero; i++) {
            free(j1_Flota[i]);
        }
        free(j1_Flota);
    }
    
    if (j1_Oponente != NULL) {
        for (int i = 0; i < tamano_tablero; i++) {
            free(j1_Oponente[i]);
        }
        free(j1_Oponente);
    }
    
    if (j2_Flota != NULL) {
        for (int i = 0; i < tamano_tablero; i++) {
            free(j2_Flota[i]);
        }
        free(j2_Flota);
    }
    
    if (j2_Oponente != NULL) {
        for (int i = 0; i < tamano_tablero; i++) {
            free(j2_Oponente[i]);
        }
        free(j2_Oponente);
    }

    return 0;
}

//cabecera: void configuracion(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero)
//precondición: el usuario ha seleccionado 1
//postcondición: se ha configurado el juego con los datos de los barcos, jugadores y tablero
void configuracion(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, 
                  char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero) {
    int opcion_configuracion;
    do {
        printf("Menú\n");
        printf("Configuración\n");
        printf("-------------------\n");
        printf("1. Introducir datos\n");
        printf("2. Mostrar\n");
        printf("3. Borrar\n");
        printf("4. Guardar\n");
        printf("5. Cargar\n");
        printf("6. Volver\n");

        scanf("%d", &opcion_configuracion);

        switch (opcion_configuracion) {
            case 1:
                introducir_datos(jugador1, jugador2, flota, num_barcos, flota_total, 
                                j1_Flota, j1_Oponente, j2_Flota, j2_Oponente, tamano_tablero, &configuracion, &estado_juego);
                break;
            case 2:
                mostrar(*jugador1, *jugador2, *tamano_tablero);
                break;
            case 3:
                borrar(*j1_Flota, *j1_Oponente, *j2_Flota, *j2_Oponente, 
                      *tamano_tablero, *flota, *num_barcos, jugador1, jugador2);
                // Reiniciar variables después de borrar
                *tamano_tablero = 0;
                *num_barcos = 0;
                *flota_total = 0;
                break;
            case 4:
                guardar(*flota, *num_barcos, *flota_total,
                      *jugador1, *jugador2,
                      *tamano_tablero,
                      *j1_Flota, *j1_Oponente,
                      *j2_Flota, *j2_Oponente);
                break;
            case 5:
                cargar(flota, num_barcos, flota_total, 
                     jugador1, jugador2, 
                     tamano_tablero, 
                     j1_Flota, j1_Oponente, 
                     j2_Flota, j2_Oponente);
                break;
            case 6:
                volver(jugador1, jugador2, flota, num_barcos, flota_total, 
                      j1_Flota, j1_Oponente, j2_Flota, j2_Oponente, tamano_tablero);
                break;
        }
    } while (opcion_configuracion < 1 || opcion_configuracion > 6);
}

void salir() {
    printf("Gracias por jugar. ¡Hasta la próxima!\n");
    exit(0);
}

//cabecera: void introducir_datos(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero)
//precondición: el usuario ha seleccionado 1 en configuración
//postcondición: se han introducido los datos de los barcos, jugadores y tablero
void introducir_datos(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, 
                     char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero,
                     ConfiguracionJuego *configuracion,EstadoJuego *estado_juego) {
    
    //Estructuras para el módulo "juego"
    EstadoJuego estado_juego;
    ConfiguracionJuego configuracion;

    //Recoger datos
    printf("Introduce el nombre del jugador 1: ");
    scanf("%s", jugador1->Nomb_jugador);
    strcpy(jugador1->Nomb_jugador, configuracion->nombre_jugador1);
    printf("Introduce el nombre del jugador 2: ");
    scanf("%s", jugador2->Nomb_jugador);
    strcpy(jugador2->Nomb_jugador, configuracion->nombre_jugador2);
    printf("Introduce el tipo de disparo del jugador 1 (A o M): ");
    do {
        scanf(" %c", &jugador1->disparo);
    } while (jugador1->disparo != 'A' && jugador1->disparo != 'M');
    jugador1->disparo = configuracion->disparo_jugador1;
    printf("Introduce el tipo de disparo del jugador 2 (A o M): ");
    do {
        scanf(" %c", &jugador2->disparo);
    } while (jugador2->disparo != 'A' && jugador2->disparo != 'M');
    jugador2->disparo = configuracion->disparo_jugador2;

    printf("Introduce el tamaño del tablero: ");
    scanf("%d", tamano_tablero);
    configuracion->tamano_tablero = *tamano_tablero;

    //Barcos
    int seguir = 1;
    int capacidad = 2; //capacidad inicial del vector
    *flota = (Barco *)malloc(capacidad * sizeof(Barco));
    if (*flota == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    
    *num_barcos = 0;
    char continuar;
    
    do {
        //Redimensionar
        if (*num_barcos >= capacidad) {
            capacidad *= 2;
            Barco *temp = realloc(*flota, capacidad * sizeof(Barco));
            if (temp == NULL) {
                printf("Error al asignar memoria.\n");
                free(*flota);
                *flota = NULL;
                return;
            }
            *flota = temp;
        }
        
        printf("Introduce el nombre del barco: ");
        scanf("%s", (*flota)[*num_barcos].Nomb_barco);

        printf("Introduce el ID del barco (1 caracter): ");
        scanf(" %c", &(*flota)[*num_barcos].Id_barco); // espacio para limpiar el buffer

        printf("Introduce el tamaño del barco: ");
        scanf("%d", &(*flota)[*num_barcos].Tam_barco);

        printf("Introduce la cantidad de ese tipo: ");
        scanf("%d", &(*flota)[*num_barcos].cantidad);

        // Inicializamos los demás campos
        (*flota)[*num_barcos].impactos = 0;
        (*flota)[*num_barcos].x = 0;
        (*flota)[*num_barcos].y = 0;
        strcpy((*flota)[*num_barcos].orientacion, "h"); // valor por defecto

        (*num_barcos)++;

        printf("¿Deseas introducir otro barco? (pulsa s o S si la respuesta es si, si no, otro caracter): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Calcular total de barcos
    *flota_total = 0;
    for (int i = 0; i < *num_barcos; i++) {
        *flota_total += (*flota)[i].cantidad;
    }
    printf("Total de barcos en la flota: %d\n", *flota_total);

    // Guardar en archivo
    FILE *archivo = fopen("Barcos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        free(*flota);
        *flota = NULL;
        return;
    }

    for (int i = 0; i < *num_barcos; i++) {
        fprintf(archivo, "%s-%c-%d\n",
                (*flota)[i].Nomb_barco,
                (*flota)[i].Id_barco,
                (*flota)[i].Tam_barco);
    }

    fclose(archivo);
    printf("\nLos barcos han sido guardados en 'Barcos.txt'.\n");

    //Que jugador empieza (1 0 2)
    jugador1->empieza = 1;
    jugador2->empieza = 0;
    char quien_empieza;
    do {
        printf("Por defecto empieza el jugador 1, ¿Quieres que empieze el jugador 2? Si (s), No (n): ");
        scanf(" %c", &quien_empieza);
    } while (quien_empieza != 's' && quien_empieza != 'n' && quien_empieza != 'S' && quien_empieza != 'N');

    if (quien_empieza == 's' || quien_empieza == 'S') {
        jugador1->empieza = 0;
        jugador2->empieza = 1;
    }

    // Crear e inicializar tableros
    // Liberar memoria previa si existía
    if (*j1_Flota != NULL) {
        for (int i = 0; i < *tamano_tablero; i++) {
            free((*j1_Flota)[i]);
        }
        free(*j1_Flota);
    }
    
    // Crear nuevos tableros
    // j1_Flota
    *j1_Flota = (char **)malloc(*tamano_tablero * sizeof(char *));
    if (*j1_Flota == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < *tamano_tablero; i++) {
        (*j1_Flota)[i] = (char *)malloc(*tamano_tablero * sizeof(char));
        if ((*j1_Flota)[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
        for (int j = 0; j < *tamano_tablero; j++) {
            (*j1_Flota)[i][j] = '-';
        }
    }

    // j1_Oponente
    *j1_Oponente = (char **)malloc(*tamano_tablero * sizeof(char *));
    if (*j1_Oponente == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < *tamano_tablero; i++) {
        (*j1_Oponente)[i] = (char *)malloc(*tamano_tablero * sizeof(char));
        if ((*j1_Oponente)[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
        for (int j = 0; j < *tamano_tablero; j++) {
            (*j1_Oponente)[i][j] = '-';
        }
    }

    // j2_Flota
    *j2_Flota = (char **)malloc(*tamano_tablero * sizeof(char *));
    if (*j2_Flota == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < *tamano_tablero; i++) {
        (*j2_Flota)[i] = (char *)malloc(*tamano_tablero * sizeof(char));
        if ((*j2_Flota)[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
        for (int j = 0; j < *tamano_tablero; j++) {
            (*j2_Flota)[i][j] = '-';
        }
    }

    // j2_Oponente
    *j2_Oponente = (char **)malloc(*tamano_tablero * sizeof(char *));
    if (*j2_Oponente == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < *tamano_tablero; i++) {
        (*j2_Oponente)[i] = (char *)malloc(*tamano_tablero * sizeof(char));
        if ((*j2_Oponente)[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
        for (int j = 0; j < *tamano_tablero; j++) {
            (*j2_Oponente)[i][j] = '-';
        }
    }

    // Volver al menú de configuración
    configuracion(jugador1, jugador2, flota, num_barcos, flota_total, 
                 j1_Flota, j1_Oponente, j2_Flota, j2_Oponente, tamano_tablero);
}

//cabecera: mostrar(Jugador jugador1, Jugador jugador2, int tamano_tablero)
//precondición: el usuario ha seleccionado 2 en configuración
//postcondición: se han mostrado los datos de los barcos, jugadores y tablero
void mostrar(Jugador jugador1, Jugador jugador2, int tamano_tablero) {
    // Mostrar información de los jugadores
    printf("Nombre del jugador 1: %s\n", jugador1.Nomb_jugador);
    printf("Nombre del jugador 2: %s\n", jugador2.Nomb_jugador);
    printf("Tipo de disparo del jugador 1 (A -> automático, M -> manual): %c\n", jugador1.disparo);
    printf("Tipo de disparo del jugador 2 (A -> automático, M -> manual): %c\n", jugador2.disparo);
    
    // Mostrar información del tablero
    printf("Tamaño del tablero: %d\n", tamano_tablero);
    
    // Abrir y leer el archivo de barcos
    FILE *archivo = fopen("Barcos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo Barcos.txt.\n");
        return;
    }
    
    printf("\nBarcos en la flota:\n");
    printf("------------------\n");
    
    char nombre[50];
    char id;
    int tam;
    
    // Mostrar información de cada barco desde el archivo
    while (fscanf(archivo, "%[^-]-%c-%d\n", nombre, &id, &tam) == 3) {
        printf("Nombre: %s, ID: %c, Tamaño: %d\n", nombre, id, tam);
    }
    
    fclose(archivo);
}

//cabecera: void borrar(char **j1_Flota, char **j1_Oponente, char **j2_Flota, char **j2_Oponente, int tamano_tablero, Barco *flota, int num_barcos, Jugador *jugador1, Jugador *jugador2)
//precondición: el usuario ha seleccionado 3 en configuración
//postcondición: se han borrado los datos de los barcos, jugadores y tablero
void borrar(char **j1_Flota, char **j1_Oponente, char **j2_Flota, char **j2_Oponente, 
           int tamano_tablero, Barco *flota, int num_barcos, Jugador *jugador1, Jugador *jugador2) {
    // Liberar matrices dinámicas de jugador 1
    for (int i = 0; i < tamano_tablero; i++) {
        free(j1_Flota[i]);
        free(j1_Oponente[i]);
    }
    free(j1_Flota);
    free(j1_Oponente);

    // Liberar matrices dinámicas de jugador 2
    for (int i = 0; i < tamano_tablero; i++) {
        free(j2_Flota[i]);
        free(j2_Oponente[i]);
    }
    free(j2_Flota);
    free(j2_Oponente);

    // Liberar vector dinámico de barcos
    if (flota != NULL) {
        free(flota);
    }

    // Reiniciar estructuras
    jugador1->Nomb_jugador[0] = '\0';
    jugador2->Nomb_jugador[0] = '\0';
    jugador1->disparo = ' ';
    jugador2->disparo = ' ';
    jugador1->empieza = 0;
    jugador2->empieza = 0;
    
    // Eliminar los archivos .txt
    if (remove("Barcos.txt") != 0) {
        printf("No se pudo eliminar el archivo Barcos.txt o no existe.\n");
    }

    if (remove("Juego.txt") != 0) {
        printf("No se pudo eliminar el archivo Juego.txt o no existe.\n");
    }

    printf("Todos los datos han sido eliminados correctamente.\n");
}

//cabecera: guardar(Barco *flota, int num_barcos, int flota_total,Jugador jugador1, Jugador jugador2,int tamano_tablero,char **j1_Flota, char **j1_Oponente,char **j2_Flota, char **j2_Oponente)
//precondición: el usuario ha seleccionado 4 en configuración
//postcondición: se han guardado los datos de los barcos, jugadores y tablero
void guardar(Barco *flota, int num_barcos, int flota_total,
           Jugador jugador1, Jugador jugador2,
           int tamano_tablero,
           char **j1_Flota, char **j1_Oponente,
           char **j2_Flota, char **j2_Oponente) {

    //Crear fichero Juego.txt
    FILE *archivo = fopen("Juego.txt", "w");
    if (archivo == NULL) {
        printf("No se ha podido abrir el archivo Juego.txt\n");
        return;
    }

    //Datos generales
    fprintf(archivo, "%d-%d-%d\n", tamano_tablero, flota_total, num_barcos);
    
    // Lista de tipos de barcos
    for (int i = 0; i < num_barcos; i++) {
        fprintf(archivo, "%c-%d\n", flota[i].Id_barco, flota[i].cantidad);
    }
    
    
    // Jugador 1
    fprintf(archivo, "1-%s-0-%c-0\n", jugador1.Nomb_jugador, jugador1.disparo);
    imprimir_tablero(archivo, j1_Flota, tamano_tablero);
    imprimir_tablero(archivo, j1_Oponente, tamano_tablero);

    // Jugador 2
    fprintf(archivo, "2-%s-0-%c-0\n", jugador2.Nomb_jugador, jugador2.disparo);
    imprimir_tablero(archivo, j2_Flota, tamano_tablero);
    imprimir_tablero(archivo, j2_Oponente, tamano_tablero);

    fclose(archivo);
    printf("Archivo 'Juego.txt' guardado correctamente.\n");
}

//cabecera: void cargar()
//precondición: el usuario ha seleccionado 5 en configuración
//postcondición: se han cargado los datos de los barcos, jugadores y tablero
void cargar(Barco **flota, int *num_barcos, int *flota_total,
          Jugador *jugador1, Jugador *jugador2,
          int *tamano_tablero,
          char ***j1_Flota, char ***j1_Oponente,
          char ***j2_Flota, char ***j2_Oponente) {

    FILE *archivo = fopen("Juego.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo Juego.txt\n");
        return;
    }

    // Leer datos generales
    fscanf(archivo, "%d-%d-%d\n", tamano_tablero, flota_total, num_barcos);

    // Liberar memoria previa si existía
    if (*flota != NULL) {
        free(*flota);
    }
    
    // Leer flota
    *flota = (Barco *)malloc((*num_barcos) * sizeof(Barco));
    for (int i = 0; i < *num_barcos; i++) {
        fscanf(archivo, "%c-%d\n", &((*flota)[i].Id_barco), &((*flota)[i].cantidad));
        (*flota)[i].impactos = 0;
        (*flota)[i].x = 0;
        (*flota)[i].y = 0;
        strcpy((*flota)[i].orientacion, "h");
    }

    // Leer datos jugador 1
    int idx, disparos, ganador;
    char tipo;
    fscanf(archivo, "%d-%[^-]-%d-%c-%d\n", &idx, jugador1->Nomb_jugador, &disparos, &tipo, &ganador);
    jugador1->Id_jugador = idx;
    jugador1->Num_disp = disparos;
    jugador1->disparo = tipo;
    jugador1->ultimo_ganador = ganador;

    // Liberar memoria previa si existía
    if (*j1_Flota != NULL) {
        for (int i = 0; i < *tamano_tablero; i++) {
            free((*j1_Flota)[i]);
        }
        free(*j1_Flota);
    }
    
    // Matriz Flota jugador 1
    *j1_Flota = (char **)malloc((*tamano_tablero) * sizeof(char *));
    for (int i = 0; i < *tamano_tablero; i++) {
        (*j1_Flota)[i] = (char *)malloc((*tamano_tablero) * sizeof(char));
        for (int j = 0; j < *tamano_tablero; j++) {
            fscanf(archivo, " %c", &((*j1_Flota)[i][j]));
        }
        fscanf(archivo, "\n");
    }

    // Liberar memoria previa si existía
    if (*j1_Oponente != NULL) {
        for (int i = 0; i < *tamano_tablero; i++) {
            free((*j1_Oponente)[i]);
        }
        free(*j1_Oponente);
    }
    
    // Matriz Oponente jugador 1
    *j1_Oponente = (char **)malloc((*tamano_tablero) * sizeof(char *));
    for (int i = 0; i < *tamano_tablero; i++) {
        (*j1_Oponente)[i] = (char *)malloc((*tamano_tablero) * sizeof(char));
        for (int j = 0; j < *tamano_tablero; j++) {
            fscanf(archivo, " %c", &((*j1_Oponente)[i][j]));
        }
        fscanf(archivo, "\n");
    }

    // Leer datos jugador 2
    fscanf(archivo, "%d-%[^-]-%d-%c-%d\n", &idx, jugador2->Nomb_jugador, &disparos, &tipo, &ganador);
    jugador2->Id_jugador = idx;
    jugador2->Num_disp = disparos;
    jugador2->disparo = tipo;
    jugador2->ultimo_ganador = ganador;

    // Liberar memoria previa si existía
    if (*j2_Flota != NULL) {
        for (int i = 0; i < *tamano_tablero; i++) {
            free((*j2_Flota)[i]);
        }
        free(*j2_Flota);
    }
    
    // Matriz Flota jugador 2
    *j2_Flota = (char **)malloc((*tamano_tablero) * sizeof(char *));
    for (int i = 0; i < *tamano_tablero; i++) {
        (*j2_Flota)[i] = (char *)malloc((*tamano_tablero) * sizeof(char));
        for (int j = 0; j < *tamano_tablero; j++) {
            fscanf(archivo, " %c", &((*j2_Flota)[i][j]));
        }
        fscanf(archivo, "\n");
    }

    // Liberar memoria previa si existía
    if (*j2_Oponente != NULL) {
        for (int i = 0; i < *tamano_tablero; i++) {
            free((*j2_Oponente)[i]);
        }
        free(*j2_Oponente);
    }
    
    // Matriz Oponente jugador 2
    *j2_Oponente = (char **)malloc((*tamano_tablero) * sizeof(char *));
    for (int i = 0; i < *tamano_tablero; i++) {
        (*j2_Oponente)[i] = (char *)malloc((*tamano_tablero) * sizeof(char));
        for (int j = 0; j < *tamano_tablero; j++) {
            fscanf(archivo, " %c", &((*j2_Oponente)[i][j]));
        }
        fscanf(archivo, "\n");
    }
}
//cabecera: void volver()
//precondición: el usuario ha seleccionado 6 en configuración
//postcondición: se ha vuelto al menú principal
void volver(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, 
    char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero) {
    configuracion_inicial();
}

// Función para imprimir tableros
void imprimir_tablero(FILE *f, char **tablero, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            fprintf(f, "%c ", tablero[i][j]);
        }
        fprintf(f, "\n");
    }
}
