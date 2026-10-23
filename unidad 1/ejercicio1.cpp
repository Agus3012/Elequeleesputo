#include <stdio.h>
#define N 20 

void carga(float arreglo[N]){
	int i;
	for (i=0; i<N; i++){
		printf("Ingrese el peso de la pieza \n");
		scanf("%f", &arreglo[i]);
	}
	return;
}

int pesoNulo(float arreglo[N]){ //distinto de busqueda, se analiza todo el arreglo
	int i, ban;
	ban = 0;
	while (i < N){
		if (arreglo[i] == 0 ){
			ban = 1;
		}
		i = i+1;
	}
	return(ban);
}

void mostrarPares(float arreglo [N]){
	int i;
	printf("Piezas inspeccionadas por la estación de control A: \n");
	for (i=0;i<N;i+=2){
		printf("%f \n", arreglo[i]);
	}
	return;
}

int mostrarPesosPares(float arreglo[N]){
	int i, cont;
	cont =0;
	for (i=0;i<N;i++){
		if (arreglo[i] % 2 == 0){
			cont = cont +1;
		}
	}
	return cont;
}

void mostrarMenorMayor(float arreglo[N]){
	int i, aux1, aux2;
	float menor, mayor;
	menor = 99999;
	mayor = 0;
	for (i=0;i<N;i++){
		if (arreglo[N] < menor){
			menor = arreglo[i];
			aux1 = i;
		}else{
			if(arreglo[N] > mayor){
			mayor = arreglo[i];
			aux2 = i;
			}
		}
	}
	printf("El peso mínimo se encuentra en el índice %d \n", aux1);
	printf("El peso máximo se encuentra en el índice %d \n", aux2);
	return;
}

float calculoPro(float arreglo[N]){
	int i;
	float sum;
	sum = 0;
	for (i=0;i<N;i++){
		sum = sum + arreglo[i];
	}
	return (sum / N);
}

void stack(float arreglo[N]){
	printf("Tamaño del arreglo: %zu \n", sizeof(arreglo)*N);
	return;
}

int main(){
	float arreglo[N];
	int ban, pesosPares;
	float promedio;
	carga(arreglo);
	ban = pesoNulo(arreglo);
	if (ban == 1) {
		printf("Existe al menos una pieza con peso nulo \n");
	}
	pesosPares=mostrarPesosPares(arreglo);
	printf("Cantidad de pesos pares: %d \n", pesosPares);
    //- Valor-L: Representa la localización física de memoria identificable y persistente 
    //- Valor-R: Representa el valor de datos puro o patrón de bits almacenado en esa dirección
	mostrarMenorMayor(arreglo);
	promedio = calculoPro(arreglo);
	printf("Peso promedio: %f \n", promedio);
	printf("Direccion del arreglo: %p\n", *arreglo);
    printf("Direccion del primer elemento: %p\n", &arreglo[0]);
    stack(arreglo);
}


