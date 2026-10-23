#include <stdio.h>
#define N 4

void carga(int arreglo[N][N]){
	int i, j;
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Ingrese unidades vendidas en el trimestre %d de la sucursal %d \n", i+1, j+1);
			scanf("%d", &arreglo[i][j]);
		}
	}
	return;
}


void trimestre(int arreglo[N][N], int xtri){
	int j;
	for (j=0;j<N;j++){
		printf("Unidades vendidas de la sucursal %d en el trimestre %d: %d \n", j+1, xtri, arreglo[xtri-1][j]);
	}
	return;
}

void sumaFila(int arreglo[N][N], int subArre[N] ){
	int i, j, sum;
	for (i=0;i<N;i++){
		sum = 0;
		for (j=0;j<N;j++){
			sum = sum + arreglo[i][j];
		}
		subArre[i] = sum;
	}
	return;	
}

void sumaColumna(int arreglo[N][N]){
	int i, j, sum;
	for (j =0;j<N;j++){
		sum =0;
		for(i=0;i<N;i++){
			sum = sum + arreglo[i][j];
		}
		printf("total acumulado anual sucursal %d: %d \n", j+1, sum);
	}
}

float promedio(int arreglo[N][N]){
	int i;
	float sum;
	sum =0;
	for (i=0;i<N;i++){
		sum = sum + arreglo[i][i];
	}
	return(sum/N);
}

void umbral(int arreglo[N][N], int xumbral){
	int i, j, cont;
	cont = 0;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			if (arreglo[i][j] > xumbral){
				cont = cont +1;
			}
		}
	}
	printf("celdas de la matriz superan el umbral: %d \n", cont);
}


int main(){
	int arreglo[N][N], xtri, subArre[N], xumbral;
	carga(arreglo);
	printf("Ingrese un trimestre: \n");
	scanf("%d", &xtri);
	trimestre(arreglo, xtri);
	sumaFila(arreglo, subArre);
	sumaColumna(arreglo);
	printf("Ingrese umbral: ");
	scanf("%d", &xumbral);
	umbral(arreglo, xumbral);
	return 0;
}
