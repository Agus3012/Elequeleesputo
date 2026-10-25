#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

struct nodo{
	int dni;
	struct nodo *sig;
};
typedef struct nodo *puntero;

typedef struct{
	char nomb[50];
	puntero cab;
}info;

void crearCab(info arreglo[N]);
void procesa(info arreglo[N]);
void suprimir(info arreglo[N], int xdni);
void mostrarRec(info arreglo[N], int i, int xdni, puntero aux);
void intercambio(puntero &cab);


int main(){
	info arreglo[N];
	int xdni, dni2;
	procesa(arreglo);
	printf("Ingrese dni para suprimir: \n");
	scanf("%d", &xdni);
	suprimir(arreglo, xdni);
	printf("Ingrese dni para buscar entre los cursos: \n");
	scanf("%d", &dni2);
	mostrarRec(arreglo, 0, dni2, arreglo[0].cab);
	intercambio(arreglo[6].cab);
}

void crearCab(info arreglo[N]){
	int i;
	for (i=0;i<N;i++){
		printf("Ingrese nombre del curso: \n");
		fgets(arreglo[i].nomb, 50, stdin);
		arreglo[i].cab = NULL;
	}
}

void procesa(info arreglo[N]){
	int dni, curso;
	puntero nuevo;
	printf("Ingrese dni (0 para terminar): \n");
	scanf("%d", &dni);
	while (dni !=0){
		printf("Ingrese curso: \n");
		scanf("%%d", &curso);
		nuevo = (puntero) malloc (sizeof (struct nodo));
		if (nuevo != NULL){
			nuevo->dni = dni;
			nuevo->sig = arreglo[curso-1].cab; 
			arreglo[curso-1].cab = nuevo;
		}
		printf("Ingrese dni (0 para terminar): \n");
		scanf("%d", &dni);
	}
	return;
}

void suprimir(info arreglo[N], int xdni){
	puntero anterior, p;
	int i, ban; 
	i = 0;
	ban = 0;
	while(i<N && ban == 0){
		if ((arreglo[i].cab != NULL) && (arreglo[i].cab->dni == xdni)){
			p = arreglo[i].cab;
			arreglo[i].cab = arreglo[i].cab -> sig;
			free (p);
			ban = 1;
		}else{
			p = arreglo[i].cab;
			anterior = arreglo[i].cab;
			while (p != NULL && p->dni != xdni){
				anterior = p;
				p = p->sig;
			}
			if (p != NULL){
				anterior -> sig = p ->sig;
				free(p);
				ban = 1;
			}
		}
	}
	//validacion de la bandera
	if (ban == 0){
		printf("DNI invalido (no encontrado) \n");
	}
}

void mostrarRec(info arreglo[N], int i, int xdni, puntero aux){
	if (i<N){
		if(aux != NULL){
			if(aux -> dni == xdni){
				printf("El dni se encuentra en el curso %d\n", i+1);
				
			}
			mostrarRec(arreglo, i, xdni, aux ->sig);
		}
		mostrarRec(arreglo, i+1, xdni, arreglo[i+1].cab);
	}
}

void suprimir(info arreglo[N], int i, int xdni, puntero &xp){
	if (i<N){
		if(xp != NULL){
			if(xp->dni == xdni){
				puntero aux = xp;
				xp  = xp ->sig ;
				free(aux);
			}else{
				suprimir(arreglo, i, xdni, xp->sig);
			}
		}else{
			if (i+1 <N){
				suprimir(arreglo, i+1, xdni, arreglo[i+1].cab);
			}
		}
	}
}

void intercambio(puntero &cab){
	if(cab != NULL && cab->sig != NULL && cab->sig->sig != NULL){
		puntero segundo = cab->sig;
		puntero tercero = segundo->sig;
		segundo->sig = tercero->sig;
		tercero->sig = segundo;
		cab->sig = tercero;
	}
}




