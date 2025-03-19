#include<stdio.h>
#include<stdlib.h>
#include<Disparo.h>
int main(){
    int FILAS,COLS;
    int *historial;
    int **mat;
    FILAS=2;
    COLS=2;
    mat=matriz_dinamica(FILAS,COLS); "placeholder para la funcion 'colocacion barcos'"
    historial=(int*)malloc(mat*sizeof(int));
    disparoJ1(mat,*historial);
    disparoIA(mat,*historial);
return 0;
}

double matriz_dinamica(int filas,int columnas){

int i,j,filas,columnas,**matriz;
    matriz = (int **)malloc (filas*sizeof(int *));
    for (i=0;i<filas;i++){
        matriz[i] = (int *)malloc (columnas*sizeof(int));
    }
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            matriz[i][j]=0;
            printf("%i \n",matriz[i][j]);
            printf(" ");
        }
    }


return matriz[i][j];
}



}
void disparoJ1(int **mat,int *historial){
    int i,j,n = 0;
    printf("introduce la posicion del disparo \n");
    printf("fila");
    scanf("%i \n",&i);
    printf("columna");
    scanf("%i \n",&j);
    if(matriz[i][j]==0){
        printf("fallo");
    }else{
        printf("tocado");
        historial[n] = matriz[i][j];
        n++;
    }

}
void disparoIA(int **mat,int *historial){
int i,j,ci,cj,n;
i=0;
j=0;
n=0;
while(i==0||i>=10){
    i=rand()%11;
}
while(j==0||j>=10){
    j=rand()%11;
}
 if(matriz[i][j]==0){
        printf("fallo");
    }else{
        printf("tocado");
        historial[n] = matriz[i][j];
        n++;
        if(matriz[i][j]=='s')
            printf("hundido");
        if(matriz[i][j]=='a'||matriz[i][j]=='d'||matriz[i][j]=='f'){
            do{
                    ci=i;
                    cj=j;
                    for(n=0;n<=100;n++){
                    while(ci<=i-1|ci==i|ci>=i+1){
                        i=rand()%11;
                        }
                        while(cj<=j-1|cj==j|cj>=j+1){
                        j=rand()%11;
                        }

                if(matriz[i][j]=='a'||matriz[i][j]=='d'||matriz[i][j]=='f'||matriz[i][j]=!historial[n])
                    printf("tocado");
                if(matriz[i][j]=='s'||matriz[i][j]=!historial[n]){
                    printf("hundido");
                }else{
                printf("fallo");
                }
            }while(matriz[i][j]=='a'||matriz[i][j]=='d'||matriz[i][j]=='f'||matriz[i][j]=!historial[n])

            }
        }

    }









}
