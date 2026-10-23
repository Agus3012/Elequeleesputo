#include <stdio.h>
#define N 3

typedef struct{
	float precio;
	int cantidad;
}info;

void carga(info arreglo[], int i);
void maximo(info arreglo[], int i, float *maxP);
float promedio(info arreglo[], int i, float suma);
int crearSubArre(info arreglo[], info subArre[], int i, int j, float prom);
float maxMin(info subArre[],int i, int j, float max, float *min);

int main(){
	info arreglo[N], subArre[N];
	int j;
	float prom, min, max, maxP;
	maxP = 0;
	min = 99999;
	carga(arreglo, 0);
	maximo(arreglo, 0,&maxP);
	prom = promedio(arreglo, 0, 0);
	j = crearSubArre(arreglo,subArre, 0, 0, prom);
	max = maxMin(subArre, 0, j, 0, &min);
	printf("Precio maximo del subarreglo: %.2f. Precio minimo del subarreglo: %.2f \n", max, min);
	return 0;
}

void carga(info arreglo[], int i){
	if (i<N){
		printf("Ingrese precio del producto: \n");
		scanf("%f", &arreglo[i].precio);
		printf("Ingrese cantidad del producto: \n");
		scanf("%d", &arreglo[i].cantidad);
		carga(arreglo, i+1);
	}
}

void maximo(info arreglo[], int i, float *maxP){ 
	if (i<N){
		if (arreglo[i].precio > *maxP){
			*maxP = arreglo[i].precio;
		}
		maximo(arreglo, i+1, maxP);
		if (arreglo[i].precio == *maxP){ //para maximos y minimos utilizar puntero o referencia si voy a hacer una operacion posterior
			printf("Cantidades del producto que coincide con el maximo: %d\n", arreglo[i].cantidad);
	    }
	}	
}

float promedio(info arreglo[], int i, float suma){
	if (i <N){
	    suma = suma + arreglo[i].precio;
		return promedio(arreglo, i+1, suma);
	}
	return suma /N;
}

int crearSubArre(info arreglo[], info subArre[], int i, int j, float prom){
	if (i<N){
		if (arreglo[i].precio < prom){
			subArre[j] = arreglo[i];
			j = j+1;
		}
		crearSubArre(arreglo, subArre, i+1, j, prom);	
	}
	return j;
}

float maxMin(info subArre[],int i, int j, float max, float *min){
	if (i<j){
		if (subArre[i].precio < *min){
			*min = subArre[i].precio;
		}
		if(subArre[i].precio > max){
				max = subArre[i].precio;
		}
		maxMin(subArre, i+1, j, max, min);
    }
	return max;
}
