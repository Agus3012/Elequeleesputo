#include <stdio.h>
#define N 45
#define M 15
void carga(float matriz[][], int i,int j){
	if(i < N){
		if(j<M){
			printf("Ingrese la nota del alumno: \n");
			scanf("%f", &matriz[i][j]);
			carga(matriz, i, j+1);
		}else{
			carga(matriz, i+1, 0);
		}	
	}
	return;
}

void mostrarU(float matriz[M], )


int main(){
	float matriz[N][M];
	carga(matriz, 0, 0);
	mostrarU(matriz[N-1], )
}
