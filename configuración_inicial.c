//Configuración inicial que incluye datos de los barcos, jugadores y el tablero.
//También da el mensaje de bienvenida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void configuracion();
void jugar();
void salir();

//funciones dentro de configuración
void introducir_datos();
void mostrar();
void borrar();
void guardar();
void cargar();
void volver();

// Estructuras globales
typedef struct {
    char nombre[20];
    char disparo;   // A (automático) o M (manual)
    int num_disp;
    int ultimo_ganador; // 0 si ha perdido, 1 si ha ganado
    int id_jugador;
} Jugador;

typedef struct {
    char nombre[20];
    int tamaño;
    char id_barco; // 1 caracter
    int impactos;
    int x;
    int y;
    char orientacion;   // v (vertical), h (horizontal), d (diagonal)
} Barco;

Jugador jugador1, jugador2;
int tamaño_tablero;

int configuracion_inicial() {
    //Mensaje de bienvenida
    printf("Bienvenido al juego\n");
    printf("HUNDIR LA FLOTA\n");
    printf("-------------------\n\n");

    //Menú de configuración
    printf("Menú\n");
    printf("Hundir la flota\n");
    printf("-------------------\n");
    printf("1. Configuración\n");
    printf("2. Jugar\n");
    printf("3. Salir\n");

    int opcion; //Selección de la opción del menú
    do {
        printf("Introduce una opción: (1, 2 o 3) ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 3);

    switch (opcion) {
        case 1:
            configuracion();
            break;
        case 2:
            jugar();    //cambiar más tarde si la función no se llama así
            break;
        case 3:
            salir();
            break;
    }

    return 0;
}

//cabecera: void configuración()
//precondición: el usuario ha seleccionado 1
//postcondición: se ha configurado el juego con los datos de los barcos, jugadores y tablero
void configuracion() {
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
                introducir_datos();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                borrar();
                break;
            case 4:
                guardar();
                break;
            case 5:
                cargar();
                break;
            case 6:
                volver();
                break;
        }
    } while (opcion_configuracion < 1 || opcion_configuracion > 6);
}

//cabecera: void salir()
//precondición: el usuario ha seleccionado 3
//postcondición: se ha cerrado el juego
void salir() {
    printf("Gracias por jugar. ¡Hasta la próxima!\n");
    exit(0);
}

//funciones dentro de configuración

//cabecera: void introducir_datos ()
//precondición: el usuario ha seleccionado 1 en configuración
//postcondición: se han introducido los datos de los barcos, jugadores y tablero
void introducir_datos() { 
    //Recoger datos
    printf("Introduce el nombre del jugador 1: ");
    scanf("%s", jugador1.nombre);
    printf("Introduce el nombre del jugador 2: ");
    scanf("%s", jugador2.nombre);
    printf("Introduce el tipo de disparo del jugador 1 (A o M): ");
    do {
        scanf(" %c", &jugador1.disparo);
    } while (jugador1.disparo != 'A' && jugador1.disparo != 'M');
    printf("Introduce el tipo de disparo del jugador 2 (A o M): ");
    do {
        scanf(" %c", &jugador2.disparo);
    } while (jugador2.disparo != 'A' && jugador2.disparo != 'M');

    printf("Introduce el tamaño del tablero: ");
    scanf("%d", &tamaño_tablero);

    //Creación del tablero con matriz dinámica
    int **tablero = (int **)malloc(tamaño_tablero * sizeof(int *));    // Asignar memoria para un array de punteros

    if (tablero == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Asignar memoria para cada fila
        tablero[i] = (int *)malloc(tamaño_tablero * sizeof(int));
        if (tablero[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Inicializar la matriz con guiones (-)
        for (int j = 0; j < tamaño_tablero; j++) {
            tablero[i][j] = '-';
        }
    }

    //Guardar la configuración en un archivo .txt
    FILE *config = fopen("config.txt", "w");
    if (config == NULL) {
        printf("Error al abrir el archivo de configuración\n");
        return;
    }

    fprintf(config, "Jugador 1: %s\n", jugador1.nombre);                //Datos jugador 1
    fprintf(config, "Disparo: %c\n", jugador1.disparo);
    fprintf(config, "numero de disparos: %d\n", jugador1.num_disp);
    fprintf(config, "ultimo ganador: %d\n", jugador1.ultimo_ganador);
    fprintf(config, "id: %d\n", jugador1.id_jugador);
    fprintf(config, "Jugador 2: %s\n", jugador2.nombre);                //Datos jugador 2
    fprintf(config, "Disparo: %c\n", jugador2.disparo);
    fprintf(config, "numero de disparos: %d\n", jugador2.num_disp);
    fprintf(config, "ultimo ganador: %d\n", jugador2.ultimo_ganador);
    fprintf(config, "id: %d\n", jugador2.id_jugador);
    fprintf(config, "Tamaño del tablero: %d\n", tamaño_tablero);       //Datos del tablero

    fclose(config);
    printf("Configuración guardada correctamente.\n");
}

//cabecera: void mostrar()
//precondición: el usuario ha seleccionado 2 en configuración
//postcondición: se han mostrado los datos de los barcos, jugadores y tablero
void mostrar() {

    
    char *texto;
    int tamaño = 1024;

    //abrir el fichero:
    FILE *config = fopen("config.txt", "r");
    if (config == NULL) {
        printf("Error al abrir el archivo de configuración\n");
        return;
    }

    //Asignar memoria dinamica
    texto = (char *)malloc(sizeof(char)*tamaño);
    if (texto == NULL) {
        printf("Error al asignar espacio de memoria\n");
        fclose(config);
        return;
    }

    //Leer e imprimir en pantalla el contenido de config.txt
    while (fgets(texto, tamaño, config) != NULL) {
        printf("%s", texto);
    }

    //Liberar memoria y cerrar archivo
    free(texto);
    fclose(config);

}

//cabecera: void borrar()
//precondición: el usuario ha seleccionado 3 en configuración
//postcondición: se han borrado los datos de los barcos, jugadores y tablero
void borrar() {

    FILE *config = fopen("config.txt", "w"); //crea el archivo destruyendo el anterior y como no se va a escribir nada se queda en blanco
    if (config == NULL) {                    //verifica si se ha abiero bien
        printf("Error al abrir el archivo de configuración\n");
        return;
    }

    //cerrar el archivo
    fclose(config);

}

void guardar() {
    // Implementar la función guardar
}

//cabecera: void cargar()
//precondición: el usuario ha seleccionado 5 en configuración
//postcondición: se han cargado los datos de los barcos, jugadores y tablero
void cargar() {
    // Implementar la función cargar
}

//cabecera: void volver()
//precondición: el usuario ha seleccionado 6 en configuración
//postcondición: se ha vuelto al menú principal
void volver() {
    // Implementar la función volver
}
