#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dni;
	int cod;
	float monto;
}adjudicatarios;

void carga(adjudicatarios *arreglo, int N);
void busqueda(adjudicatarios *arreglo, int N, int xdni, int *xplan, float *xmonto, int i);
void generarsubArre(adjudicatarios *arreglo, adjudicatarios *&subArre, int N);

int main (){
	adjudicatarios *arreglo = NULL, *subArre = NULL;
	int cant, xdni, xplan, j;
	float xmonto;
	printf("Ingrese la cantidad de adjudicatarios\n");
	scanf("%d", &cant);
	arreglo = (adjudicatarios*) malloc(cant * sizeof(adjudicatarios));
	carga(arreglo, cant);
	printf("Ingrese dni a buscar: \n");
	scanf("%d", &xdni);
	busqueda(arreglo, cant, xdni, &xplan, &xmonto, 0);
	printf("Plan del dni buscado: %d\n", xplan);
	printf("Monto del dni buscado: %.2f\n", xmonto);
	generarsubArre(arreglo, subArre, cant);
	free(arreglo);
	arreglo = NULL;
	free(subArre);
	subArre = NULL;
	return 0;
}

void carga(adjudicatarios *arreglo, int N){
	int i;
	for (i=0;i<N;i++){
		printf("Ingrese dni: \n");
		scanf("%d", &arreglo[i].dni);
		printf("Ingrese cod: \n");
		scanf("%d", &arreglo[i].cod);
		printf("Ingrese monto: \n");
		scanf("%f", &arreglo[i].monto);
	}
	return;
}
void busqueda(adjudicatarios *arreglo, int N, int xdni, int *xplan, float *xmonto, int  i){
	if (i<N) {
		if(arreglo[i].dni == xdni){
			*xplan = arreglo[i].cod;
			*xmonto = arreglo[i].monto;
		}else{
			busqueda(arreglo, N, xdni, xplan, xmonto, i+1);
		}
	}
}

void generarsubArre(adjudicatarios *arreglo, adjudicatarios *&subArre, int N){
	int i, j;
	j = 0;
	for (i=0;i<N;i++){
		if (arreglo[i].cod == 1 || arreglo[i].cod == 3){
			j = j+1;
		}
	}
	subArre = (adjudicatarios*)malloc(j * sizeof(adjudicatarios));
	
	j =0;
	for (i=0;i<N;i++){
		if (arreglo[i].cod == 1 || arreglo[i].cod == 3){
			subArre[j] = arreglo[i];
			j = j+1;
		}
	}
}
