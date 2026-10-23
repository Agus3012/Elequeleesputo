#include <stdio.h>
#include <string.h>
#define N 180
typedef struct{
	int id;
	char puesto[50];
	char dedicacion[50];
	float sueldoP;
}info;

void carga(info arreglo[N]){
	int i; 
	float sueldo;
	for (i=0;i<N;i++){
		printf("Ingrese Numero de identificacion: \n");
		scanf("%d", &arreglo[i].id);
		while(getchar() != '\n'); //se limpia el buffer luego de un scanf y antes de un fgets
		printf("Ingrese nombre del puesto: \n");
		fgets(arreglo[i].puesto, 50, stdin); // el fgets guarda el enter (\n)
		printf("Ingrese dedicacion: \n");
		fgets(arreglo[i].dedicacion, 50, stdin);
		printf("Ingrese sueldo propuesto: \n");
		scanf("%f", &sueldo);
		while (sueldo <= 0){
			printf("El sueldo debe ser positivo. Ingrese nuevamente: \n");
			scanf("%f", &sueldo);
		}
		arreglo[i].sueldoP = sueldo;
	}
	return; 
}

int fullTimeSueldo(info arreglo[N]){
	int i, cont;
	cont = 0;
	for(i=0;i<N;i++){ //strcmp("Full Time", "Full Time") devuelve 0 cuando ambos textos son iguales
		if(strcmp(arreglo[i].dedicacion, "Full Time\n") == 0 && arreglo[i].sueldoP<800000){
			cont = cont+1;
		}
	}
	return(cont);
}

void busquedaPuesto(info arreglo[N],char xpuesto[50]){
	int i;
	printf("Dedicacion y sueldo de las ofertas coincidentes: ");
	for(i=0;i<N;i++){
		if (strcmp(arreglo[i].puesto, xpuesto)==0){
			printf("%s\n", arreglo[i].dedicacion);
			printf("%.1f\n", arreglo[i].sueldoP);
		}
	}
	return;
}


int main(){
	info arreglo[N];
	int cont;
	char xpuesto[50];
	carga(arreglo);
	cont= fullTimeSueldo(arreglo);
	printf("Cantidad de propuestas que posean dedicación 'Full Time' y cuyo sueldo propuesto sea, simultáneamente, menor a $800.000: %d\n", cont);
	printf("Ingrese le nombre de un puesto: \n");
	while(getchar() != '\n');
	fgets(xpuesto, 50, stdin);
	busquedaPuesto(arreglo, xpuesto);
}
