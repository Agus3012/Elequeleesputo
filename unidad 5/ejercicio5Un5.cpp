#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int hora;
	int min;
	float porc;
	int temp;
}info;

struct nodo{
	info sensor;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &xp);
void ingresoOrdenado(puntero &xp);


int main(){
	puntero cab;
	crear(cab);
	ingresoOrdenado(cab);
}

void crear(puntero &xp){
	xp = NULL;
}

void ingresoOrdenado(puntero &xp){
	puntero actual, anterior, nuevo;
	int temp;
	printf("Ingrese temperatura (-1 para terminar)\n");
	scanf("%d", &temp);
	while (temp != -1){
		nuevo = (puntero) malloc (sizeof (struct nodo) ) ;
		nuevo ->sensor.temp = temp;
		printf("Ingrese hora: \n");
		scanf("%d", &nuevo->sensor.hora);
		printf("Ingrese minutos: \n");
		scanf("%d", &nuevo->sensor.min);
		printf("Ingrese porcentaje de humedad \n");
		scanf("%f", &nuevo->sensor.porc);
		if ((xp == NULL) || (temp < xp->sensor.temp)){
			nuevo->sig = xp;
			xp = nuevo;
		}else{
			anterior = xp;
			actual = xp->sig;
			while (actual != NULL && actual->sensor.temp < temp){
				anterior = actual;
				actual = actual->sig;
			}
			anterior->sig = nuevo;
			nuevo->sig = actual;
		}
		printf("Ingrese temperatura (-1 para terminar)\n");
		scanf("%d", &temp);
	}				
}





