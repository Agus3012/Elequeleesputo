#include <stdio.h>
#include <string.h>

typedef struct{
	int cod;
	char titulo[50];
	char autor[50];
	int stock;
}info;

void grabar(FILE *archi);
void informar(FILE *archi, int pos);
void infoAutor(FILE *archi, char xautor[50]);
void informarAutor(FILE *archi, char xtitulo[50]);
void grabarNuevo(FILE *archi);
void modificarStock(FILE *archi, int cod);

int main(){
	FILE *archi;
	int op, xcod;
	char xtitulo[50], xautor[50];
	archi = fopen ("TITULOS.dat", "wb");
	if (archi != NULL){
		grabar(archi);
		fclose(archi);
	}
	archi = fopen("TITULOS.dat", "rb");
	if (archi != NULL){
		do{
			printf("MENU BIBLIOTECA: \n");
			printf("1. Mostrar info de un libro\n");
			printf("2. Mostrar info de un autor\n");
			printf("3. Mostrar autor del libro ingresando titulo\n");
			printf("4. Ingresar un nuevo libro \n");
			printf("5. Realizar prestamos de un libro\n");
			printf("0. Salir del menu\n");
			printf("Ingrese una opcion: \n");
			scanf("%d", &op);
			
			switch(op){
				case 1:
					printf("Ingrese un codigo\n");
					scanf("%d", &xcod);
					informar(archi, xcod);
					rewind(archi);
					break;
				case 3:
					printf("Ingrese el titulo de un libro: \n");
					while(getchar() != '\n');
					fgets(xtitulo, 50, stdin);
					informarAutor(archi, xtitulo);
					rewind(archi);
					break;
				case 2:
					printf("Ingrese el nombre de un autor: \n");
					while(getchar() != '\n');
					fgets(xautor, 50, stdin);
					infoAutor(archi, xautor);
					rewind(archi);
					break;
				case 4:
					fclose(archi);
					archi = fopen("TITULOS.dat", "ab+");
					grabarNuevo(archi);	
					fclose(archi);
					archi = fopen("TITULOS.dat", "rb");
					break;
				case 5:
					fclose(archi);
					printf("Ingrese codigo del libro: \n");
					scanf("%d", &xcod);
					archi = fopen("TITULOS.dat", "rb+");
					modificarStock(archi, xcod);
					fclose(archi);
					archi = fopen("TITULOS.dat", "rb");
					break;				
			}
		}while(op != 0);
	}
}

void grabar(FILE *archi){
	info aux;
	int cod;
	printf("Ingrese titulo del libro: (FIN PARA TERMINAR) \n");
	fgets(aux.titulo, 50, stdin);
	while (strcmp(aux.titulo, "FIN\n")){
		fseek(archi, 0, SEEK_END);
		long tam = ftell(archi);
		cod = (int)(tam / sizeof(info)) + 1;
		aux.cod = cod;
		printf("Ingrese autor del libro: \n");
		fgets(aux.autor, 50, stdin);
		printf("Ingrese stock\n");
		scanf("%d", &aux.stock);
		while (getchar()!='\n');
		fwrite(&aux, sizeof(info), 1, archi);
		printf("Ingrese titulo del libro: (FIN PARA TERMINAR) \n");
		fgets(aux.titulo, 50, stdin);
	}
}

void informar(FILE *archi, int pos){
	info aux;
	fseek(archi, (pos-1)*sizeof(info), SEEK_SET);
	fread(&aux, sizeof(info), 1, archi);
	printf("titulo del libro: %s", aux.titulo);
	printf("Ejemplares en stock: %d\n", aux.stock);
}

void infoAutor(FILE *archi, char xautor[50]){
	int total = 0;
	info aux;
	while(fread(&aux, sizeof(info), 1, archi) == 1){
		if(strcmp(aux.autor, xautor) == 0){
			printf("El libro %s es del autor ingresado\n", aux.titulo);
			total = total +1;
		}
	
	}
	printf("Total de libros del autor: %d\n", total);
}

void informarAutor(FILE *archi, char titulo[50]){
	info aux;
	while (fread(&aux, sizeof(info), 1, archi) == 1){
		    if(strcmp(aux.titulo, titulo) == 0){
            printf("El autor del libro %s es: %s", aux.titulo, aux.autor);
		}
	}
}

void grabarNuevo(FILE *archi){
	info nuevo, aux;
	printf("Ingrese el codigo del libro\n");
	scanf("%d", &nuevo.cod);
	fseek(archi, -(long)sizeof(info), SEEK_END);
	fread(&aux, sizeof(info), 1, archi);
	while(nuevo.cod != aux.cod+1){
		printf("Codigo invalido, ingrese nuevamente: \n");
		scanf("%d", &nuevo.cod);
	}
	while (getchar() != '\n');
	printf("Ingrese titulo del libro: \n");
	fgets(nuevo.titulo, 50, stdin);
	printf("Ingrese autor del libro: \n");
	fgets(nuevo.autor, 50, stdin);
	printf("Ingrese stock: \n");
	scanf("%d", &nuevo.stock);
	fseek(archi, 0, SEEK_END); // Se posiciona al final del archivo para poder escribir después de la lectura anterior.
	fwrite(&nuevo, sizeof(info), 1, archi);
}

void modificarStock(FILE *archi, int cod){
	info aux;
	fseek(archi, (cod-1)*sizeof(info), SEEK_SET);
	fread(&aux, sizeof(info), 1, archi);
	aux.stock = aux.stock-1;
	fseek(archi, -(long)sizeof(info), SEEK_CUR);
	fwrite(&aux, sizeof(info), 1, archi);
}


	


