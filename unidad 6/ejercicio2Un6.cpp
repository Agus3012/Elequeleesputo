#include <stdio.h>
#include <string.h>

typedef struct{
	int leg;
	char nom[50];
	float notF;
}alumno;

void grabar(FILE *archi);
void prom(FILE *archi);

int main(){
	FILE *archi;
	archi = fopen("calificaciones.txt", "w");
	if (archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("calificaciones.txt", "r");
	if (archi != NULL){
		prom(archi);
		fclose(archi);
	}
}

void grabar(FILE *archi){
	alumno alu;
	int i;
	for (i=0;i<3;i++){
		printf("Ingrese legajo del alumno: \n");
		scanf("%d", &alu.leg);
		while (getchar() != '\n');
		printf("Ingrese nombre del alumno: \n");
		fgets(alu.nom, 50, stdin);
		printf("Ingrese nota final del alumno: \n");
		scanf("%f", &alu.notF);
		while (getchar() != '\n');
		fprintf(archi, "%d %s %.2f \n", alu.leg, alu.nom, alu.notF);
	}
}

void prom(FILE *archi){
	alumno alu;
	int cantidad;
	float sumNotas, promedio;
	sumNotas = 0;
	while(fscanf(archi, "%d %s %f\n", &alu.leg, alu.nom, &alu.notF) ==3){
		printf("%d %s %.2f\n", alu.leg, alu.nom, alu.notF);
		sumNotas = sumNotas + alu.notF;
	}
	promedio = sumNotas / 3;
	printf("Promedio general: %.2f\n", promedio);
}
