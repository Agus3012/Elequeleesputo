#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void grabar(FILE *archi);
void leer(FILE *archi);
void notas(FILE *archi);

int main(){
	FILE *archi;
	archi = fopen("bitacora.txt", "w");
	if (archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("bitacora.txt", "r");
	if(archi != NULL){
		leer(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("bitacora.txt", "a");
	if (archi != NULL){
		notas(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
}

void grabar(FILE *archi){
	char texto[200];
	printf("Ingrese el texto a almacenar en el archivo (FIN para finalizar): \n");
	gets(texto);
	while(strcmp(texto, "FIN") != 0){
		fputs(texto, archi);
		gets(texto);
	}
}

void leer(FILE *archi){
	char texto[200];
	while(fgets(texto, sizeof(texto), *&archi) != NULL){
		printf(" %s \n", texto);
	}
}

void notas(FILE *archi){
	char texto[200];
	printf("Ingrese el texto a almacenar en el archivo (FIN para finalizar): \n");
	gets(texto);
	while(strcmp(texto, "FIN") != 0){
		fputs(texto, archi);
		gets(texto);
	}
}
