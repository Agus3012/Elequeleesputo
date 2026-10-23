#include <stdio.h>
#define N 8
#define M 15

void cereo(float tabla[N][M]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			tabla[i][j] = 0;
		}
	}
	return;
}

void procesa(float tabla[N][M]){
	int mes,prog;
	printf("ingrese el mes del 1 al 8, 0 para terminar\n");
	scanf("%d",&mes);
	while((mes < 8) && (mes > 0)){
		printf("ingrese el programa\n");
		scanf("%d",&prog);
		printf("ingrese el monto recaudado\n");
		scanf("%f",&tabla[mes-1][prog-1]);
		printf("ingrese el mes del 1 al 8, 0 para terminar\n");
		scanf("%d",&mes);
	}
	return;
}

float promedio(float tabla[N][M]){
	int i,j;
	float acum, prom;
	acum=0;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			acum=acum+tabla[i][j];
		}
	}
	prom=acum/(N*M);
	return prom;
}

int mesBajo(float tabla[N][M]){
	int i,j,a;
	float min,acum;
	min=999999999;
	for(i=0;i<N;i++){
		acum=0;
		for(j=0;j<M;j++){
			acum=acum+tabla[i][j];
		}
		if(acum<min){
			min=acum;
			a=i;
		}
	}
	return a;
}

int progBajo(float tabla[N][M]){
	int i,j,a;
	float min,acum;
	min=999999999;
	for(j=0;j<M;j++){
		acum=0;
		for(i=0;i<N;i++){
			acum=acum+tabla[i][j];
		}
		if(acum<min){
			min=acum;
			a=i;
		}
	}
	return a;
}

int main(){
	float tabla[N][M], prom;
	int ssssss, ssss;
	cereo(tabla);
	procesa(tabla);
	prom=promedio(tabla);
	printf("el ingreso promedio de la recaudacion total fue: %.1f\n",prom);
	ssssss=mesBajo(tabla);
	printf("el mes que recaudo la menor cantidad fue el mes %d\n",ssssss+1);
	ssss=progBajo(tabla);
	printf("el programa social con menos recaudacion fue el programa %d\n",ssss+1);
	return 0;
}
