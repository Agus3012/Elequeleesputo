#include <stdio.h>
#include <stdlib.h>
struct nodo{
	int nro;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &cab);
void insertarCola(puntero &cab, int valor);
void insertarColaRec(puntero &cab2, int valor);

int main(){
	puntero cab, cab2;
	int valor, valor2;
	crear(cab);
	crear(cab2);
	printf("Ingrese valor para agregar a la lista 1: (-1 para terminar) \n");
	scanf("%d", &valor);
	while (valor != -1){
		insertarCola(cab, valor);
		printf("Ingrese valor para agregar a la lista 1: (-1 para terminar) \n");
		scanf("%d", &valor);
	}
	printf("Ingrese valor para agregar a la lista 2: (-1 para terminar) \n");
	scanf("%d", &valor2);
	while (valor2 != -1){
		insertarColaRec(cab2, valor2);
		printf("Ingrese valor para agregar a la lista 2: (-1 para terminar) \n");
		scanf("%d", &valor2);
	}		
}

void crear(puntero &cab){
	cab = NULL;
}

void insertarCola(puntero &cab, int valor){
	puntero nuevo, p;
	nuevo = (puntero)malloc(sizeof(struct nodo));
	nuevo->nro = valor;
	nuevo->sig = NULL;
	if (cab == NULL){
		cab = nuevo;
	}else{
		p = cab;
		while (p->sig !=NULL){
			p = p->sig;
		}
		p->sig = nuevo;
	}
}
void insertarColaRec(puntero &cab2, int valor){
	if (cab2 == NULL){
		cab2 = (puntero)malloc(sizeof(struct nodo));
		cab2->nro = valor;
		cab2->sig = NULL;
	}else{
		insertarColaRec(cab2->sig, valor);
	}
		
}



