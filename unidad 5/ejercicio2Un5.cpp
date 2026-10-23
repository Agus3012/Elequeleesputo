#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int dni;
	int edad;
	char tipo;
	char estado[10];
}t_socio;

void crearArre(t_socio *&arre, int N);
void cargaArre(t_socio *arre, int N, int i);
void contar(t_socio *arre, int *&subArre, int N);
void generarSubArre(t_socio *arre, int *subArre, int N, int i, int j);


int main(){
	t_socio *arreglo = NULL;
	int cant, *subArre = NULL, j;
	printf("Ingrese la cantida de socios \n");
	scanf("%d", &cant);
	crearArre(arreglo, cant);
	cargaArre(arreglo, cant, 0);
	contar(arreglo, subArre, cant);
	generarSubArre(arreglo, subArre, cant, 0, 0);
	free(arreglo);
	free(subArre);
	arreglo = NULL;
	subArre = NULL;
	return 0;
}



void crearArre(t_socio *&arre, int N){ 
	arre = (t_socio *) malloc(N* sizeof(t_socio));
}

void cargaArre(t_socio *arre, int N, int i){
	if (i < N){
		printf("Ingrese DNI: \n");
		scanf("%d", &arre[i].dni);
		printf("Ingrese edad: \n");
		scanf("%d", &arre[i].edad);
		while (getchar() != '\n');
		printf("Ingrese tipo: \n");
		scanf("%c", &arre[i].tipo);
		while (getchar() != '\n');
		printf("Ingrese estado: \n");
		fgets(arre[i].estado, 10, stdin);
		cargaArre(arre, N, i+1);
	}
}

void contar(t_socio *arre, int *&subArre, int N){
	int i, cont;
	cont = 0;
	for (i=0;i<N;i++){
		if((arre[i].edad) > 40 && (arre[i].tipo == 'A')){
			cont = cont +1;
		}
	}
	subArre = (int*) malloc(cont* sizeof(int));
}

void generarSubArre(t_socio *arre, int *subArre, int N, int i, int j){
	if (i<N){
		if ((arre[i].edad) > 40 && (arre[i].tipo == 'A')){
			subArre[j] = arre[i].dni;
			generarSubArre(arre, subArre, N, i+1, j+1);
		}else{
			generarSubArre(arre, subArre, N, i+1, j);
		}	
	}
}





