#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define M 5

typedef struct{
	int cod;
	char nomb[50];
	int cant;
	int arre[N];
}info;

void grabar(FILE *archi);
void buscarMayor(FILE *archi, int);
void modificar(FILE *archi, int, int);
float promedio(FILE *archi);
void listado(FILE *archi, float);
void actualizar(FILE *archi);

int main(){
	FILE *archi;
	int xcod, xano;
	archi = fopen("Categorias.dat", "wb");
	if(archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("el archivo no se creo correctamente");
	}
	archi = fopen("Categorias.dat", "rb");
	if (archi != NULL){
		printf("Ingrese codigo de categoría: \n");
		scanf("%d", &xcod);
		buscarMayor(archi, xcod);
		fclose(archi);
	}else{
		printf("el archivo no se creo correctamente");
	}
	archi = fopen("Categorias.dat", "rb+");
	if (archi != NULL){
		printf("Ingrese codigo de categoría: \n");
		scanf("%d", &xcod);
		printf("Ingrese año \n");
		scanf("%d", &xano);
		modificar(archi, xcod, xano-2007);
		fclose(archi);
	}else{
		printf("el archivo no se creo correctamente");
	}
	archi = fopen("Categorias.dat", "rb");
	if (archi != NULL){
		float prom = promedio(archi);
		rewind(archi);
		listado(archi, prom);
		fclose(archi);
	}else{
		printf("el archivo no se creo correctamente");
	}
	archi = fopen("Categorias.dat", "rb+");
	if(archi != NULL){
		actualizar(archi);
		fclose(archi);
	}else{
		printf("el archivo no se creo correctamente");
	}
}

void grabar(FILE *archi){
	info aux;
	int i, j;
	for(i=0;i<M;i++){
		printf("Ingrese codigo de la categoria: \n");
		scanf("%d", &aux.cod);
		while (getchar()!='\n');
		printf("Ingrese nombre de la categoría: \n");
		fgets(aux.nomb, 50, stdin);
		printf("Ingrese cantidad de clubes disponibles: \n");
		scanf("%d", &aux.cant);
		for(j=0;j<N;j++){
			printf("Ingrese la cantidad de inscriptos del año %d\n", 2007+j);
			scanf("%d", &aux.arre[j]);
		}
		fwrite(&aux, sizeof(info), 1, archi);
		while(getchar()!='\n');
	}	
}

void buscarMayor(FILE *archi, int cod){
	info aux;
	int i, ano, ban,mayor;
	mayor = 0;
	ban = 0;
	while(fread(&aux, sizeof(info), 1, archi) == 1 && ban == 0){
		if(aux.cod == cod){
			for(i=0;i<N;i++){
				if(aux.arre[i] > mayor){
					mayor = aux.arre[i];
					ano = i;
				}
			}
			ban = 1;
		}
	}
	if (ban ==1){
		printf("Año con mayor cantidad de inscriptos de la categoría %d: %d\n", cod, ano+2007);
	}else{
		printf("Codigo no encontrado\n");
	}
}

void modificar(FILE *archi, int cod, int i){
	info aux;
	int ban, cant;
	ban = 0;
	while(fread(&aux, sizeof(info), 1, archi) == 1 && ban == 0){
		if(aux.cod == cod){
			printf("Ingrese nueva cantidad de inscriptos: \n");
			scanf("%d", &cant);
			aux.arre[i] = cant;
			fseek(archi, -(long)sizeof(info), SEEK_CUR);
			fwrite(&aux, sizeof(info), 1, archi);
			ban = 1;
		}
	}
	if (ban == 0){
		printf("codigo no encontrado\n");
	}else{
		printf("Modificacion exitosa\n");
	}
}

float promedio(FILE *archi){
	info aux;
	int i;
	float prom, acum;
	acum = 0;
	while(fread(&aux, sizeof(info), 1, archi)==1){
		for(i=0;i<N;i++){
			acum = acum +aux.arre[i];
		}
	}
	return prom = acum /(N*M);
}

void listado(FILE *archi, float prom){
	info aux;
	int i;
	float xprom, acum;
	while(fread(&aux, sizeof(info), 1, archi)==1){
		acum = 0;
		for(i=0;i<N;i++){
			acum = acum +aux.arre[i];
		}
		xprom = acum /N;
		if (xprom > prom){
			printf("La categoria %s supera la cantidad promedio de inscriptos\n", aux.nomb);
		}
	}
}

void actualizar(FILE *archi){
	info aux;
	int ban;
	ban = 0;
	while(fread(&aux, sizeof(info), 1, archi) == 1 && ban == 0){
		if(strcmp(aux.nomb, "NACIONAL B\n") == 0){
			ban = 1;
			printf("Ingrese nueva cantidad de clubes disponibles: \n");
			scanf("%d", &aux.cant);
			fseek(archi, -(long)sizeof(info), SEEK_CUR);
			fwrite(&aux, sizeof(info), 1, archi);
		}
	}
}




