#include <stdio.h>
#include <string.h>

int contar (char palabra [], int i, int cont);
int analizar(char palabra[], int i, int j, int *bandera);

int main(){
	char palabra[50];
	int cont, bandera;
	bandera = 1;
	printf("Ingrese la palabra para analizar: \n");
	fgets(palabra, 50, stdin);
	palabra[strcspn(palabra, "\n")] = '\0'; //Busca el \n y reemplaza por \0 para terminar la cadena ahí
	cont = contar(palabra, 0, 0);
	analizar(palabra, 0,cont-1, &bandera);
	if (bandera == 1){
		printf("La palabra es palindromo \n");
	}else{
		printf("La palabra no es palindromo \n");
	}
	
}

int contar(char palabra[], int i, int cont){
	if (palabra[i] != '\0'){
		cont = cont+1;
		return contar(palabra, i+1, cont);
	}
	return cont;
}

int analizar(char palabra[], int i, int j, int *bandera){
	if (i<j){
		if(palabra[i] != palabra[j]){
			*bandera = 0;
		}else{
			analizar(palabra, i+1, j-1, bandera);
		}
	}
}
	
	
int analizar(char palabra[], int i, int j, int *bandera){
	if (palabra[i] != '\0'){
		if(palabra[i] != palabra[j]){
			*bandera = 0;
		}else{
			analizar(palabra, i+1, j-1, bandera);
		}
	}
}
	
