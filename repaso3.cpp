#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cod;
	float precio;
}info;

struct nodo{
	info datos;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &cab);
void carga(puntero &cab);
void mostrar(puntero cab);
int masCaro(puntero xp);

int main(){
	puntero cab;
	int xmax;
	crear(cab);
	carga(cab);
	mostrar(cab);
	xmax = masCaro(cab);
	printf("Codigo del producto mas caro: %d\n", xmax);
}

void crear(puntero &cab){
	cab = NULL;
}

void carga(puntero &cab){
	puntero n;
	int cod;
	printf("Ingrese codigo del producto: \n");
	scanf("%d", &cod);
	while(cod != 0){
		n = (puntero)malloc(sizeof(nodo));
		if (n !=NULL){
			n->datos.cod = cod;
			printf("Ingrese precio del producto: \n");
			scanf("%f", &n->datos.precio);
			n->sig = cab;
			cab = n;
			printf("Ingrese codigo del producto: \n");
			scanf("%d", &cod);
		}
	}
}

void mostrar(puntero cab){
	if (cab != NULL){
		printf("Codigo del producto: %d\n", cab->datos.cod);
		printf("Precio del producto: %.2f\n", cab->datos.precio);
		mostrar(cab->sig);
	}
}

int masCaro(puntero xp){
	float max = 0;
	int aux;
	while(xp != NULL){
		if(xp->datos.precio > max){
			max = xp->datos.precio;
			aux = xp->datos.cod;
		}
		xp = xp->sig;
	}
	return aux;
}


