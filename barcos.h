#ifndef ESTADO_BARCOS_H
#define ESTADO_BARCOS_H   

// #include "modulo_configuracion.h" cuando lo tengamos


int Hundido (Barco *barco); // Verifica si el barco esta hundido
int Impactado (Barco *barco, int x, int y); // Hundido, Tocado o Agua
void Estado2(Barco *barco);  // Posicion, orientacion y el numero de impactos que lleva

#endif 



