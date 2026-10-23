#include <stdio.h>
#define N 6

void cereo(int arreglo[N], int i);
void procesa(int arreglo[N]);
void maximo(int arreglo[N], int *max,int *aux1, int i);
void minimo(int arreglo[N], int *min, int *aux2, int i);
void contadores(int arreglo[N], int *cont1, int *cont2, int i);
void promedio(int arreglo[N], int i, float *suma, float *prom, int *cont);

int main(){
	int arreglo[N], max, aux1, min, aux2, cont1, cont2, cont;
	float suma, prom;
	max = 0;
	min = 9999999;
	cont1= 0;
	cont2 =0;
	cont = 0;
	suma = 0;
	cereo(arreglo, 0);
	procesa(arreglo);
	maximo(arreglo, &max, &aux1, 0);
	printf("lenguaje mas elegido: %d\n", aux1);
	minimo(arreglo, &min, &aux2, 0);
	printf("lenguaje menos elegido: %d\n", aux2);
	contadores(arreglo, &cont1, &cont2, 0);
	printf("lenguajes recibieron menos de 5.000 votos: %d lemguajes con mas de 9.000 votos: %d \n", cont1, cont2);
	promedio(arreglo, 0,&suma, &prom, &cont);
	printf("Cantidad de lenguajes que superan al promedio: %d\n", cont);
	return 0;
}

void cereo(int arreglo[N], int i){
	if (i<N){
		arreglo[i]=0;
		cereo(arreglo, i+1);
	}
}

void procesa(int arreglo[N]){
	int leng;
	printf("Ingrese el numero de lenguaje que utiliza (Ingrese 0 para terminar): 1-Javascript, 2-HTML, 3-CSS, 4-Java, 5-Python, 6-C \n");
	scanf("%d", &leng);
	if (leng != 0){
		arreglo[leng-1]=arreglo[leng-1]+1;
		procesa(arreglo);
	}
}

void maximo(int arreglo[N], int *max, int *aux1, int i){
	if (i<N){
		if (arreglo[i]>*max){
			*max = arreglo[i];
			*aux1 = i+1;
		}
		maximo(arreglo, max, aux1, i+1);
	}
}

void minimo(int arreglo[N], int *min, int *aux2, int i){
	if (i<N){
		if (arreglo[i]<*min){
			*min = arreglo[i];
			*aux2 = i+1;
		}
		minimo(arreglo, min, aux2, i+1);
	}
}

void contadores(int arreglo[N], int *cont1, int *cont2, int i){
	if (i<N){
		if (arreglo[i] < 5000){
			*cont1 = *cont1 +1;
		}else{
			if (arreglo[i]>9000){
				*cont2 = *cont2 +1;
			}
		}
		contadores(arreglo, cont1, cont2, i+1);
	}
}

void promedio(int arreglo[N], int i, float *suma, float *prom, int *cont){
	if (i<N){
		*suma = *suma + arreglo[i];
		promedio(arreglo, i+1, suma, prom, cont);
		if(arreglo[i] > *prom){
			*cont = *cont+1;
		}
		}else{
			*prom = *suma/ N;
			*cont = 0;
		}
}

















