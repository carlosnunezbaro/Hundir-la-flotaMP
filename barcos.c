#include <stdio.h>  
#include <stdlib.h>
#include "estado-barcos.h"


int Hundido(Barco *barco);
int Impactado(Barco *barco, int x, int y);
void Estado(Barco *barco);


int Hundido(Barco *barco) {
    return barco->impactos = barco->longitud; //Verifica si el barco esta hundido return 1 (verdadero), si no lo esta return 0 (falso)
}

int Impactado(Barco *barco, int x, int y) {

    if (barco->orientacion == 'H') {
        if (y == barco->y && x == barco->x) {
        barco->impactos++;
        if (Hundido(barco)) {
        printf("!Hundido!");
        return 2; } // Hundido 
        else  
            printf("!Tocado!");
            return 1; // Tocado
        }   
    }
    else 


    if (barco->orientacion == 'V') {
        if (x == barco->x && y == barco->y) {
            barco->impactos++;
            if(Hundido(barco)) {
                printf("!Hundido");
                return 2;
            } 
            else 
            printf("!Tocado!");
            return 1;
        }
    }
    
    printf("!Agua!"); 
    return 0; // Da en el agua

}

void Estado(Barco *barco) {

printf("Barco en la posicion %d,%d orientacion: %c impactos: %d",barco->x,barco->y,barco->orientacion,barco->impactos);


}

