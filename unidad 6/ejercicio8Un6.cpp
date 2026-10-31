#include <stdio.h>
#include <string.h>

typedef struct{
	int cod;
	char titulo[50];
	char dir[50];
	int cant;
}info;

void grabar(FILE *archi);
void mostrar(FILE *archi);
void modificar(FILE *archi, int cant);
void buscarDir(FILE *archi, char titulo[50]);
void grabarNuevo(FILE *archi, FILE *archi2);
void mayorEsp(FILE *archi2);
void mostrarTam(FILE *acrhi, FILE *archi2);

int main(){
	FILE *archi, *archi2;
	int cant;
	char xtitulo[50];
	archi = fopen("CINE.dat", "wb");
	if (archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("CINE.dat", "rb");
	if (archi != NULL){
		mostrar(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("CINE.dat", "rb+");
	if (archi != NULL){
		printf("Ingrese la nueva cantidad de espectadores de la pelicula 5\n");
		scanf("%d", &cant);
		modificar(archi, cant);
		fclose(archi);
	}else{
		printf("El archivno no se abrio correctamente\n");
	}
	archi = fopen("CINE.dat", "rb");
	if (archi != NULL){
		while(getchar()!='\n');
		printf("Ingrese titulo de pelicula para buscar su director: \n");
		fgets(xtitulo, 50, stdin);
		buscarDir(archi, xtitulo);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("CINE.dat", "rb");
	archi2 = fopen("exitos.dat", "wb");
	if (archi != NULL && archi2 != NULL){
		grabarNuevo(archi, archi2);
		fclose(archi);
		fclose(archi2);
	}else{
		printf("Los archivos no se abrieron correctamente\n");
	}
	archi2 = fopen("exitos.dat", "rb");
	if (archi2 != NULL){
		mayorEsp(archi2);
		fclose(archi2);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("CINE.dat", "rb");
	archi2 = fopen("exitos.dat", "rb");
	if (archi != NULL && archi2 != NULL){
		mostrarTam(archi, archi2);
		fclose(archi);
		fclose(archi2);
	}
}

void grabar(FILE *archi){
	info aux;
	int cod;
	printf("Ingrese titulo de pelicula (FIN para terminar)\n");
	fgets(aux.titulo, 50, stdin);
	while(strcmp(aux.titulo, "FIN\n") !=0){
		fseek(archi, 0, SEEK_END);
		long tam = ftell(archi);
		cod =  (int) (tam / sizeof(info)) +1;
		aux.cod = cod;
		printf("Ingrese director de la pelicula: \n");
		fgets(aux.dir, 50, stdin);
		printf("Ingrese cantidad de espectadores: \n");
		scanf("%d", &aux.cant);
		fwrite(&aux, sizeof(info), 1, archi);
		while (getchar()!= '\n');
		printf("Ingrese titulo de pelicula (FIN para terminar)\n");
		fgets(aux.titulo, 50, stdin);
	}
}

void mostrar(FILE *archi){
	info aux;
	while(fread(&aux, sizeof(info), 1, archi) == 1){
		printf("Codigo de la pelicula: %d\n", aux.cod);
		printf("Titulo de la pelicula: %s", aux.titulo);
		printf("Director de la pelicula: %s", aux.dir);
		printf("Cantidad de espectadores de la pelicula: %d\n", aux.cant);
		printf("\n");
	}
}

void modificar(FILE *archi, int cant){
	info aux;
	fseek(archi, (5-1)*sizeof(info), SEEK_SET);
	fread(&aux, sizeof(info), 1, archi);
	aux.cant = cant;
	fseek(archi, -(long)sizeof(info), SEEK_CUR);
	fwrite(&aux, sizeof(info), 1, archi);
}

void buscarDir(FILE *archi, char titulo[50]){
	info aux;
	int ban;
	ban = 0;
	while(fread(&aux, sizeof(info), 1, archi) == 1 && ban == 0){
		if(strcmp(aux.titulo, titulo)==0){
			ban = 1;
			printf("Director de la pelicula buscada: %s",aux.dir);
		}
	}
}

void grabarNuevo(FILE *archi, FILE *archi2){
	info aux;
	while(fread(&aux, sizeof(info), 1, archi) == 1){
		if(aux.cant > 100000){
			fwrite(&aux, sizeof(info), 1, archi2);
		}
	}
}

void mayorEsp(FILE *archi2){
	info aux;
	int max;
	char xtitulo[50];
	max = 0;
	while(fread(&aux, sizeof(info), 1, archi2) == 1){
		if(aux.cant > max){
			max = aux.cant;
			strcpy(xtitulo, aux.titulo);
		}
	}
	printf("Titulo de la pelicula con mayor cantidad de espectadores: %s", xtitulo);
}

void mostrarTam(FILE *archi, FILE *archi2){
	fseek(archi, 0, SEEK_END);
	fseek(archi2, 0, SEEK_END);
	long tam1=ftell(archi);
	long tam2=ftell(archi2);
	printf("Tamaño del archivo CINE.dat en bytes: %ld\n", tam1);
	printf("Tamaño del archivo exitos.dat en bytes: %ld\n", tam2);
}








