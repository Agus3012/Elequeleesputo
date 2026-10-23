#include <stdio.h>
#include <string.h>
#include <ctype.h>

void intercambio(char frase[50]){
	frase[28-1] = '6';
	puts(frase);
	return;
}

void nuevaCadena(char frase[50]){
	char palabra[11];
	strncpy(palabra, &frase[13], 10);
    palabra[10] = '\0';
    puts(palabra);
}

void contador(char frase[50]){
	int i, contador;
	contador = 0;
	i = 0;
	while(frase[i] != '\0'){
		if ((frase[i] =='a') || (frase[i] =='e') || (frase[i] =='i') || (frase[i] =='o') || (frase[i] =='u') || (frase[i] =='A') || (frase[i] =='E') || (frase[i] =='I') || (frase[i] =='O') || (frase[i] =='U')){
			contador = contador+1;
		}
		i = i+1;
	}
	printf("La frase tiene %d vocales \n", contador);
	return;
}	

void convertirMayus(char frase[50]){
	int i;
	i =0;
	while (frase[i]!='\0'){
		frase[i] = toupper(frase[i]);
		i = i+1;
	}
	printf("Frase en mayúsculas: \n");
	puts(frase);
	return;
}
void invertirCadena(char frase[], char invertida[]) {
    int i = 0;
    int j = 0;
    while (frase[i] != '\0') {
        i=i+1;
    }
    i=i-1;
    while (i >= 0) {
        invertida[j] = frase[i];
        i=i-1;
        j=j+1;
    }
    invertida[j] = '\0';
    printf("Frase invertida: \n");
    puts(invertida);
    return;
}

int main(){
	char frase[50], invertida[50];
	fgets(frase, 50, stdin);
	intercambio(frase);
	nuevaCadena(frase);
	contador(frase);
	convertirMayus(frase);
	invertirCadena(frase, invertida);
	return 0;
}


