#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int cod;
	char titulo[50];
	float precio;
	char autor[50];
	int cant;
}info;

struct nodo{
	info datos;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &xp);
void insertar(puntero &xp);
int buscar(puntero xp, int cod, char xautor[50], char xtitulo[50], float xprecio);
void impresionInversa(puntero xp);
void eliminacion(puntero &xp, int cod);
float total(puntero xp);

int main(){
	puntero cab;
	int cod, p, cod2;
	char xautor[50], xtitulo[50];
	float xprecio, xtotal;
	crear(cab);
	insertar(cab);
	printf("Ingrese codigo a buscar:\n");
	scanf("%d", &cod);
	p = buscar(cab, cod, xautor, xtitulo, xprecio);
	if (p!=0){
		printf("Autor del libro del codigo buscado: %s\n", xautor);
		printf("Titulo del libro del codigo buscado: %s\n", xtitulo);
		printf("Precio del libro del codigo buscado: %f\n", xprecio);
	}else{
		printf("codigo no encontrado\n");
	}
	impresionInversa(cab);
	printf("Ingrese codigo de un libro a eliminar: \n");
	scanf("%d", &cod2);
	eliminacion(cab, cod2);
	xtotal = total(cab);
	printf("El total recaudado fue de: %f \n", xtotal);
}

void crear(puntero &xp){
	xp = NULL;
}

void insertar(puntero &xp){
	puntero n;
	int cod;
	printf("Ingrese codigo del libro: \n");
	scanf("%d", &cod);
	while(getchar()!= '\n');
	while(cod != 0){
		n = (puntero)malloc(sizeof(nodo));
			if(n !=NULL){
			n->datos.cod = cod;
			printf("Ingrese titulo del libro: \n");
			fgets(n->datos.titulo, 50, stdin);
			printf("Ingrese precio del libro:\n");
			scanf("%f", &n->datos.precio);
			while(getchar()!= '\n');
			printf("Ingrese autor del libro: \n");
			fgets(n->datos.autor, 50, stdin);
			printf("Ingrese cantida de libro: \n");
			scanf("%d", &n->datos.cant);
			n ->sig = xp;
			xp = n;
		}
		printf("Ingrese codigo del libro: \n");
		scanf("%d", &cod);
		while(getchar() != '\n');
	}
}

int buscar(puntero xp, int cod, char xautor[50], char xtitulo[50], float xprecio){
	if (xp != NULL){
		if(xp->datos.cod == cod){
			strcpy(xautor, xp->datos.autor);
			strcpy(xtitulo, xp->datos.titulo);
			xprecio = xp->datos.precio;
			return 1;
		}else{
			return buscar(xp->sig, cod, xautor, xtitulo, xprecio);
		}
	}else{
		return 0;
	}
}

void impresionInversa(puntero xp){
	if (xp != NULL){
		impresionInversa(xp->sig);
		printf("Codigo del libro: %d \n", xp->datos.cod);
		printf("Autor del libro: %s\n", xp->datos.autor);
		printf("Titulo del libro: %s\n", xp->datos.titulo);
		printf("Precio del libro: %f\n", xp->datos.precio);
		printf("Cantidad de unidades del libro: %d\n", xp->datos.cant);
	}
}

void eliminacion(puntero &xp, int cod){
	puntero anterior, p;
	if((xp !=NULL) && xp->datos.cod == cod){
		p = xp;
		xp = xp->sig;
		free(p);
	}else{
		p = xp;
		anterior = xp;
		while (p != NULL && p->datos.cod != cod){
			anterior = p;
			p = p->sig;
		}
		if(p!=NULL){
			anterior->sig = p->sig;
			free(p);
		}
	}
}

float total(puntero xp){
	float xtotal;
	xtotal = 0;
	while(xp != NULL){
		xtotal = xtotal + xp->datos.precio;
		xp = xp->sig;
	}
	return xtotal;
}



