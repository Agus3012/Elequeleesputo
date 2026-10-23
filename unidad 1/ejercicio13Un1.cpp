#include <stdio.h>
#define CARAS 2
#define COLUMNAS 3
#define FILAS 3

void carga(int cubo[CARAS][FILAS][COLUMNAS]){
	int i, j, k;
	for (i=0; i<CARAS;i++){
		for (j=0;j<FILAS;j++){
			for(k=0;k<COLUMNAS;k++){
				printf("Ingrese cantidad de paquetes del nivel %d del cubo, fila %d, columna %d", i, j+1, k+1);
				scanf("%d", &cubo[i][j][k]);
			}
		}
	}
	return;
}

void recorridoPorCara(int cubo[FILAS][COLUMNAS]){
	int j, k, total;
	total = 0;
	printf("Matriz de la cara seleccionada: ");
	for (j=0;j<FILAS;j++){
		for (k=0;k<COLUMNAS;k++){
			printf("%d ", cubo[j][k]);
			total = total + cubo[j][k];
		}
		printf("\n");
	}
	printf("Total de paquetes del nivel seleccionado: %d\n", total);
	return;
}

void recorridoCompleto(int cubo[CARAS][FILAS][COLUMNAS]){
	int i, j, k, total, vacios;
	vacios = 0;
	total = 0;
	for(i=0;i<CARAS;i++){
		for(j=0;j<FILAS;j++){
			for(k=0;k<COLUMNAS;k++){
				total = total + cubo[i][j][k];
				if (cubo[i][j][k] == 0){
					vacios = vacios + 1;
				}
			}
		}
	}
	printf("total acumulado en todo el depósito: %d", total);
	printf("Total de compartimientos vacios: %d", vacios);
	return;
}

int main(){
	int cubo[CARAS][FILAS][COLUMNAS], xcara;
	carga(cubo);
	printf("Ingrese un nivel del cubo (0 o 1)");
	scanf("%d", &xcara);
	recorridoPorCara(cubo[xcara]);
	recorridoCompleto(cubo);
	return 0;
}
