//Configuración inicial que incluye datos de los barcos, jugadores y el tablero.
//También da el mensaje de bienvenida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion_inicial.h"
#include "juego.h"

// Estructuras globales
typedef struct {
    int Id_jugador;
    char Nomb_jugador[20];
    char disparo;   // A (automático) o M (manual)
    int Num_disp;
    int ultimo_ganador; // 0 si ha perdido, 1 si ha ganado
    int empieza;
} Jugador;

typedef struct {
    char Nomb_barco[20];
    int Tam_barco;
    char Id_barco; // 1 caracter
    int impactos;
    int x;
    int y;
    char orientacion[3];
    int cantidad;   // v (vertical), h (horizontal), d (diagonal)
} Barco;

Jugador jugador1, jugador2;

int configuracion_inicial() {
    jugador1.Id_jugador = 1;
    jugador2.Id_jugador = 2;
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
            inicializar_juego();    //cambiar más tarde si la función no se llama así
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
                mostrar(jugador1, jugador2, tamaño_tablero);
                break;
            case 3:
                borrar(j1_Flota, j1_Oponente, j2_Flota, j2_Oponente, tamaño_tablero, flota, num_barcos);
                break;
            case 4:
            guardar(flota, num_barcos, flota_total,
                jugador1, jugador2,
                tamaño_tablero,
                j1_Flota, j1_Oponente,
                j2_Flota, j2_Oponente);
                break;
            case 5:
                cargar(&flota, &num_barcos, &flota_total, &jugador1, &jugador2, &tamaño_tablero, &j1_Flota, &j1_Oponente, &j2_Flota, &j2_Oponente);
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
    int tamaño_tablero = 0;
    printf("Introduce el nombre del jugador 1: ");
    scanf("%s", jugador1.Nomb_jugador);
    printf("Introduce el nombre del jugador 2: ");
    scanf("%s", jugador2.Nomb_jugador);
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

    //Barcos
    int seguir = 1;
    Barco *flota = NULL;
    int num_barcos = 0;
    int capacidad = 2; //capacidad inicial del vector
    flota = (Barco *)malloc(capacidad * sizeof(Barco));
    if (flota == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    do {
        //Redimensionar
        if (num_barcos >= capacidad) {
            capacidad *= 2;
            Barco *temp = realloc(flota, capacidad * sizeof(Barco));
            if (temp == NULL) {
                printf("Error al asignar memoria.\n");
                free(flota);
                return;
            }
            flota = temp;
        }
        
        printf("Introduce el nombre del barco: ");
        scanf("%s", flota[num_barcos].Nomb_barco);

        printf("Introduce el ID del barco (1 caracter): ");
        scanf(" %c", &flota[num_barcos].Id_barco); // espacio para limpiar el buffer

        printf("Introduce el tamaño del barco: ");
        scanf("%d", &flota[num_barcos].Tam_barco);

        printf("Introduce la cantidad de ese tipo: ");
        scanf("%d", &flota[num_barcos].cantidad);

        // Inicializamos los demás campos
        flota[num_barcos].impactos = 0;
        flota[num_barcos].x = 0;
        flota[num_barcos].y = 0;
        flota[num_barcos].orientacion = 'h'; // valor por defecto

        num_barcos++;

        printf("¿Deseas introducir otro barco? (pulsa s o S si la respuesta es si, si no, otro caracter): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S')

    int *flota_total = 0;
    for (int i = 0; i < num_barcos; i++) {
        flota_total += flota[i].cantidad;
    }
    printf("Total de barcos en la flota: %d\n", flota_total);

    // Guardar en archivo
    FILE *archivo = fopen("Barcos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        free(flota);
        return 1;
    }

    for (int i = 0; i < num_barcos; i++) {
        fprintf(archivo, "%s-%c-%d\n",
                flota[i].Nomb_barco,
                flota[i].Id_barco,
                flota[i].Tam_barco);
    }

    fclose(archivo);
    printf("\nLos barcos han sido guardados en 'Barcos.txt'.\n");

    //Que jugador empieza (1 0 2)
    jugador1.empieza = 1;
    jugador2.empieza = 0;
    char quien_empieza;
    do {
        printf("Por defecto empieza el jugador 1, ¿Quieres que empieze el jugador 2? Si (s), No (n)");
        scanf("%c", &quien_empieza);
    } while (quien_empieza != 's' && quien_empieza != 'n' && quien_empieza != 'S' && quien_empieza != 'N');

    //Creación del tablero flota 1 con matriz dinámica
    char **j1_Flota = (char **)malloc(tamaño_tablero * sizeof(char *));    // Asignar memoria para un array de punteros

    if (j1_Flota == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Asignar memoria para cada fila
        j1_Flota[i] = (char *)malloc(tamaño_tablero * sizeof(char));
        if (j1_Flota[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Inicializar la matriz con guiones (-)
        for (int j = 0; j < tamaño_tablero; j++) {
            j1_Flota[i][j] = '-';
        }
    }

    //Creación del tablero oponente 2 con matriz dinámica
    char **j1_Oponente = (char **)malloc(tamaño_tablero * sizeof(char *));    // Asignar memoria para un array de punteros

    if (j1_Oponente == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Asignar memoria para cada fila
        j1_Oponente[i] = (char *)malloc(tamaño_tablero * sizeof(char));
        if (j1_Oponente[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Inicializar la matriz con guiones (-)
        for (int j = 0; j < tamaño_tablero; j++) {
            j1_Oponente[i][j] = '-';
        }
    }

    //Creación del tablero flota 2 con matriz dinámica
    char **j2_Flota = (char **)malloc(tamaño_tablero * sizeof(char *));    // Asignar memoria para un array de punteros

    if (j2_Flota == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Asignar memoria para cada fila
        j2_Flota[i] = (char *)malloc(tamaño_tablero * sizeof(char));
        if (j2_Flota[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Inicializar la matriz con guiones (-)
        for (int j = 0; j < tamaño_tablero; j++) {
            j2_Flota[i][j] = '-';
        }
    }

    //Creación del tablero oponente 2 con matriz dinámica
    char **j2_Oponente = (char **)malloc(tamaño_tablero * sizeof(char *));    // Asignar memoria para un array de punteros

    if (j2_Oponente == NULL) {
        printf("Error al reservar memoria\n");
        exit(1);
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Asignar memoria para cada fila
        j2_Oponente[i] = (char *)malloc(tamaño_tablero * sizeof(char));
        if (j2_Oponente[i] == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
    }

    for (int i = 0; i < tamaño_tablero; i++) {                         // Inicializar la matriz con guiones (-)
        for (int j = 0; j < tamaño_tablero; j++) {
            j2_Oponente[i][j] = '-';
        }
    }

    configuracion();

}

//cabecera: void mostrar()
//precondición: el usuario ha seleccionado 2 en configuración
//postcondición: se han mostrado los datos de los barcos, jugadores y tablero
void mostrar(Jugador jugador1, Jugador jugador2, int tamaño_tablero) {
    // Mostrar información de los jugadores
    printf("Nombre del jugador 1: %s\n", jugador1.Nomb_jugador);
    printf("Nombre del jugador 2: %s\n", jugador2.Nomb_jugador);
    printf("Tipo de disparo del jugador 1 (A -> automático, M -> manual): %c\n", jugador1.disparo);
    printf("Tipo de disparo del jugador 2 (A -> automático, M -> manual): %c\n", jugador2.disparo);
    
    // Mostrar información del tablero
    printf("Tamaño del tablero: %d\n", tamaño_tablero);
    
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
    
    // Volver al menú de configuración
    configuracion();
}

//cabecera: void borrar()
//precondición: el usuario ha seleccionado 3 en configuración
//postcondición: se han borrado los datos de los barcos, jugadores y tablero
void borrar(char **j1_Flota, char **j1_Oponente, char **j2_Flota, char **j2_Oponente, int tamaño_tablero, Barco *flota, int num_barcos) {
    // Liberar matrices dinámicas de jugador 1
    for (int i = 0; i < tamaño_tablero; i++) {
        free(j1_Flota[i]);
        free(j1_Oponente[i]);
    }
    free(j1_Flota);
    free(j1_Oponente);

    // Liberar matrices dinámicas de jugador 2
    for (int i = 0; i < tamaño_tablero; i++) {
        free(j2_Flota[i]);
        free(j2_Oponente[i]);
    }
    free(j2_Flota);
    free(j2_Oponente);

    // Liberar vector dinámico de barcos
    if (flota != NULL) {
        free(flota);
    }

    // Reiniciar estructuras (si son globales)
    jugador1.Nomb_jugador[0] = '\0';
    jugador2.Nomb_jugador[0] = '\0';
    jugador1.disparo = ' ';
    jugador2.disparo = ' ';
    jugador1.empieza = 0;
    jugador2.empieza = 0;

    // Reiniciar configuraciones globales
    tamaño_tablero = 0;
    
    // Eliminar los archivos .txt
    if (remove("Barcos.txt") != 0) {
        printf("No se pudo eliminar el archivo Barcos.txt o no existe.\n");
    }

    if (remove("Juego.txt") != 0) {
        printf("No se pudo eliminar el archivo Juego.txt o no existe.\n");
    }

    printf("Todos los datos han sido eliminados correctamente.\n");
    
    // Volver al menú de configuración
    configuracion();
}

void guardar(Barco *flota, int num_barcos, int flota_total,
    Jugador jugador1, Jugador jugador2,
    int tamaño_tablero,
    char **j1_Flota, char **j1_Oponente,
    char **j2_Flota, char **j2_Oponente) {

    //Crear fichero Juego.txt
    FILE *juego = fopen("Juego.txt", "w");
    if (juego == NULL) {
        printf("No se ha podido abrir el archivo Juego.txt\n");
        return;
    }

    //Datos generales
    fprintf("%d-%d-%d\n",tamaño_tablero, flota_total,num_barcos);
    // 2. Lista de tipos de barcos
    for (int i = 0; i < num_barcos; i++) {
        fprintf(archivo, "%c-%d\n", flota[i].Id_barco, flota[i].cantidad);
    }
    // Función auxiliar para imprimir matrices
    void imprimir_tablero(FILE *f, char **tablero, int tamaño) {
        for (int i = 0; i < tamaño; i++) {
            for (int j = 0; j < tamaño; j++) {
                fprintf(f, "%c ", tablero[i][j]);
            }
            fprintf(f, "\n");
        }
    }
    // 3. Jugador 1
    fprintf(archivo, "1-%s-0-%c-0\n", jugador1.Nomb_jugador, jugador1.disparo);
    imprimir_tablero(archivo, j1_Flota, tamaño_tablero);
    imprimir_tablero(archivo, j1_Oponente, tamaño_tablero);

    // 4. Jugador 2
    fprintf(archivo, "2-%s-0-%c-0\n", jugador2.Nomb_jugador, jugador2.disparo);
    imprimir_tablero(archivo, j2_Flota, tamaño_tablero);
    imprimir_tablero(archivo, j2_Oponente, tamaño_tablero);

    fclose(archivo);
    printf("Archivo 'Juego.txt' guardado correctamente.\n");


}

//cabecera: void cargar()
//precondición: el usuario ha seleccionado 5 en configuración
//postcondición: se han cargado los datos de los barcos, jugadores y tablero
void cargar(Barco **flota, int *num_barcos, int *flota_total,
    Jugador *jugador1, Jugador *jugador2,
    int *tamaño_tablero,
    char ***j1_Flota, char ***j1_Oponente,
    char ***j2_Flota, char ***j2_Oponente) {

FILE *archivo = fopen("Juego.txt", "r");
if (archivo == NULL) {
printf("No se pudo abrir el archivo Juego.txt\n");
return;
}

// Leer datos generales
fscanf(archivo, "%d-%d-%d\n", tamaño_tablero, flota_total, num_barcos);

// Leer flota
*flota = (Barco *)malloc((*num_barcos) * sizeof(Barco));
for (int i = 0; i < *num_barcos; i++) {
fscanf(archivo, "%c-%d\n", &((*flota)[i].Id_barco), &((*flota)[i].cantidad));
(*flota)[i].impactos = 0;
(*flota)[i].x = 0;
(*flota)[i].y = 0;
(*flota)[i].orientacion = 'h';
}

// Leer datos jugador 1
int idx, disparos, ganador;
char tipo;
fscanf(archivo, "%d-%[^-]-%d-%c-%d\n", &idx, jugador1->Nomb_jugador, &disparos, &tipo, &ganador);
jugador1->indice = idx;
jugador1->disparos = disparos;
jugador1->disparo = tipo;
jugador1->ganador = ganador;

// Matriz Flota jugador 1
*j1_Flota = (char **)malloc((*tamaño_tablero) * sizeof(char *));
for (int i = 0; i < *tamaño_tablero; i++) {
(*j1_Flota)[i] = (char *)malloc((*tamaño_tablero) * sizeof(char));
for (int j = 0; j < *tamaño_tablero; j++) {
    fscanf(archivo, " %c", &((*j1_Flota)[i][j]));
}
fscanf(archivo, "\n");
}

// Matriz Oponente jugador 1
*j1_Oponente = (char **)malloc((*tamaño_tablero) * sizeof(char *));
for (int i = 0; i < *tamaño_tablero; i++) {
(*j1_Oponente)[i] = (char *)malloc((*tamaño_tablero) * sizeof(char));
for (int j = 0; j < *tamaño_tablero; j++) {
    fscanf(archivo, " %c", &((*j1_Oponente)[i][j]));
}
fscanf(archivo, "\n");
}

// Leer datos jugador 2
fscanf(archivo, "%d-%[^-]-%d-%c-%d\n", &idx, jugador2->Nomb_jugador, &disparos, &tipo, &ganador);
jugador2->indice = idx;
jugador2->disparos = disparos;
jugador2->disparo = tipo;
jugador2->ganador = ganador;

// Matriz Flota jugador 2
*j2_Flota = (char **)malloc((*tamaño_tablero) * sizeof(char *));
for (int i = 0; i < *tamaño_tablero; i++) {
(*j2_Flota)[i] = (char *)malloc((*tamaño_tablero) * sizeof(char));
for (int j = 0; j < *tamaño_tablero; j++) {
    fscanf(archivo, " %c", &((*j2_Flota)[i][j]));
}
fscanf(archivo, "\n");
}

// Matriz Oponente jugador 2
*j2_Oponente = (char **)malloc((*tamaño_tablero) * sizeof(char *));
for (int i = 0; i < *tamaño_tablero; i++) {
(*j2_Oponente)[i] = (char *)malloc((*tamaño_tablero) * sizeof(char));
for (int j = 0; j < *tamaño_tablero; j++) {
    fscanf(archivo, " %c", &((*j2_Oponente)[i][j]));
}
fscanf(archivo, "\n");
}

fclose(archivo);
printf("Datos cargados correctamente desde Juego.txt\n");
}



//cabecera: void volver()
//precondición: el usuario ha seleccionado 6 en configuración
//postcondición: se ha vuelto al menú principal
void volver() {
    configuracion_inicial();
}