#include <stdio.h>
#include <ctype.h>
#include <string.h>

void contador(char frase[50]){
	int i, cont;
	cont = 0;
	i = 0;
	while (frase[i] != '\0'){
		cont = cont +1;
		i = i+1;
	}
	printf("Longitud total de la cadena: %d \n", cont);
}

int mayusNum(char frase[50]){
	int i, mayus, num;
	i = 0;
	mayus = 0;
	num = 0;
	while (frase[i] != '\0'){
		if (isupper(frase[i])) {
            mayus = 1;
        }else{
			if (isdigit(frase[i])) {
            	num = 1;
		   	}
		}
		i = i+1;
	}
	if ((mayus == 1 )&& (num == 1)){
		return(1);
	}else{
		return(0);
	}
}

void tokenizar(char copia[50], char palabras[20][50]) {
    int i;
    char *palabra;
	i =0;
    palabra = strtok(frase, " ");

    while (palabra != NULL) {
        strcpy(palabras[i], palabra);
        i = i + 1;
        palabra = strtok(NULL, " ");
    }
    return;
}

int esPalindromo(char palabras[50]) {
    int i, j;
	i= 0;
	j = 0;
    while (palabras[j] != '\0') {
        j = j + 1;
    }
    j = j - 1;
    while (i < j) {
        if (palabras[i] != palabras[j]) {
            return 0;
        }
        i = i + 1;
        j = j - 1;
    }
    return 1;
}

void enmascarar(char frase[50], char buscada[50]){
	char *posicion;
	posicion = strstr(frase, buscada);
	if (posicion != NULL){
		strcpy(posicion, "*****");
	}
	puts(frase);
}

int main(){
	char frase[50],copia[50] palabras [20][50];
	int xpalabra, mayusDig, palin;
	fgets(frase, 50, stdin);
	strcpy(copia, frase);
	contador(frase);
	mayusDig = mayusNum(frase);
	if (mayusDig == 1){
		printf("La frase contiene al menos un digito y una mayuscula \n");
	}else{
		printf("La frase NO contiene al menos un digito y una mayuscula \n");
	}
	tokenizar(copia, palabras);
	printf("Ingrese el numero de palabra a analizar: \n");
	scanf("%d", &xpalabra);
	while(getchar() != '\n');
	palin = esPalindromo(palabras[xpalabra-1]);
	if (palin == 1) {
    	printf("La palabra es palindromo\n");
	}else {
    	printf("La palabra no es palindromo\n");
	}
	enmascarar(frase, "clave");
	return 0;
}
