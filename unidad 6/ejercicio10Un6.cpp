#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nombre[50];
	char carrera[50];
}alumno;

struct nodo2{
	alumno datos;
	struct nodo2 *sig;
};
typedef struct nodo2 *puntero2;

typedef struct{
	int id;
	puntero2 cab;
}libros;

struct nodo1{
	libros datos;
	struct nodo1 *sig;
};
typedef struct nodo1 *puntero1;

void crear(puntero1 &cab);
void insertarCola(puntero1 &cab);
void insertar1Libro(puntero1 &cab, int id);
void insertarLibros(puntero1 &cab);
void busqueda(puntero1 xp, int id);
void insertarCola(puntero2 &cab);
void insertarAl(puntero1 cab);
void suprimir(puntero1 &cab, int id);
void recorrer(puntero1 xp, int id);
void recorrer2(puntero2 xp, char nomb[50]);
void buscarAl(puntero1 xp, char nomb[50]);
void suprimir2(puntero2 &cab, char nomb[50]);


int main(){
	puntero1 cab;
	int id, op;
	char xnomb[50];
	crear(cab);
	insertarLibros(cab);

	
	do{
		printf("MENU BIBLIOTECA\n");
        printf("1. Ingresar un libro\n");
        printf("2. Insertar alumno en lista de espera\n");
        printf("3. Devolver libro\n");
        printf("4. Mostrar alumnos por carrera\n");
        printf("5. Buscar y eliminar alumno de la lista\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        
        switch(op){
        	case 1:
        		printf("Ingrese un id para agregar un nuevo libro para que este en calidad de prestamo: \n");
				scanf("%d", &id);
				insertar1Libro(cab, id);
				break;
			case 2:
				insertarAl(cab);
				break;
			case 3:
				printf("Ingrese id del libro que fue devuelto: \n");
				scanf("%d", &id);
				suprimir(cab, id);
				break;
			case 4:
				printf("Ingrese id de un libro: \n");
				scanf("%d", &id);
				recorrer(cab, id);
				break;
			case 5:
				printf("Ingresar el nombre de un alumno: \n");
				while(getchar()!= '\n');
				fgets(xnomb, 50, stdin);
				buscarAl(cab, xnomb);
				break;
			default:
				printf("Opcion no valida\n");
;		}
	}while(op!=0);
	return 0;
}

void crear(puntero1 &cab){
	cab = NULL;
}


void insertar1Libro(puntero1 &cab, int id){
	puntero1 n;
	n = (puntero1)malloc(sizeof(nodo1));
	if (n != NULL){
		n->datos.id = id;
		n->datos.cab = NULL;
		n->sig = cab;
		cab = n;
	}
}

void insertarLibros(puntero1 &cab){
	int id;
	printf("Ingrese id del libro: (0 para finalizar)\n");
	scanf("%d", &id);
	while(id != 0){
		insertar1Libro(cab, id);
		printf("Ingrese id del libro: (0 para finalizar)\n");
		scanf("%d", &id);
	}
}

void busqueda(puntero1 xp, int id){
	if (xp != NULL){
		if(xp->datos.id == id){
			insertarCola(xp->datos.cab);
		}else{
			busqueda(xp->sig, id);
		}
	}else{
		printf("Libro no encontrado\n");
	}
}

void insertarCola(puntero2 &cab){
	puntero2 nuevo, p;
	nuevo = (puntero2)malloc(sizeof(nodo2));
	printf("Ingrese nombre del alumno: \n");
	fgets(nuevo->datos.nombre, 50, stdin);
	printf("Ingrese carrera del alumno: \n");
	fgets(nuevo->datos.carrera, 50, stdin);
	nuevo->sig = NULL;
	if(cab == NULL){
		cab = nuevo;
	}else{
		p = cab;
		while(p->sig != NULL){
			p = p->sig;
		}
		p->sig = nuevo;
	}
}

void insertarAl(puntero1 cab){
	int id;
	printf("Ingrese id del libro para agregar alumnos a la cola: (0 para terminar) \n");
	scanf("%d", &id);
	while(getchar()!='\n');
	while(id != 0){
		busqueda(cab, id);
		printf("Ingrese id del libro para agregar alumnos a la cola: (0 para terminar) \n");
		scanf("%d", &id);
		while(getchar()!='\n');
	}
} 

void suprimir(puntero1 &cab, int id){
	if (cab != NULL){
		if (cab->datos.id == id){
			if (cab->datos.cab != NULL){
				puntero2 aux = cab->datos.cab;
				cab->datos.cab = cab->datos.cab->sig;
				free(aux);
			}else{
				printf("No hay alumnos en la lista de espera\n");
			}
		}else{
			suprimir(cab->sig, id);
		}
	}else{
		printf("Libro no encontrado\n");
	}
}

void recorrer2(puntero2 xp, char nomb[50]){
	if(xp != NULL){
		if(strcmp(nomb, xp->datos.carrera) == 0){
			printf("Nombre de alumno en la carrera de %s: %s" ,nomb, xp->datos.nombre);
		}else{
			recorrer2(xp->sig, nomb);
		}
	}
}

void recorrer(puntero1 xp, int id){
	if(xp != NULL){
		if(xp->datos.id == id){
			if (xp->datos.cab != NULL){
			char xnomb[50];
			printf("Ingrese nombre de una carrera: \n");
			while(getchar() != '\n');
			fgets(xnomb, 50, stdin);
			recorrer2(xp->datos.cab, xnomb);
			}else{
				printf("No hay alumnos en la lista\n");
			}
		}else{
			recorrer(xp->sig, id);
		}
	}else{
		printf("Libro no encontrado\n");
	}
}

void suprimir2(puntero2 &cab, char nomb[50]){
	if(cab != NULL){
		if(strcmp(cab->datos.nombre, nomb) == 0 ){
			puntero2 aux = cab;
			cab = cab ->sig;
			free(aux);
		}else{
			suprimir2(cab->sig, nomb);
		}
	}
}

void buscarAl(puntero1 xp, char nomb[50]){
	int contador, ban;
	puntero2 p;
	ban = 0;
	while(xp != NULL && ban == 0){
		contador = 0;
		p = xp->datos.cab;
		while(p != NULL && ban == 0){
			if(strcmp(nomb, p->datos.nombre) == 0){
				printf("Libro que esta esperando: Libro con id: %d\n", xp->datos.id);
				printf("Alumnos antes que %s en lista de espera: %d",p->datos.nombre, contador);
				suprimir2(xp->datos.cab, nomb);
				ban = 1;
			}else{
				contador = contador +1;
				p = p->sig;
			}
		}
		xp = xp->sig;
	}
}

