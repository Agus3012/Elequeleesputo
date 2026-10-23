#include <stdio.h>
#define N 4
#define Z 8

void carga(int arreglo[Z][N]){
	int i, j, nota;
	for (i=0;i<Z;i++){
		for(j=0;j<N;j++){
			printf("Ingrese %d nota del %d estudiante \n", j+1, i+1);
			scanf("%d", &nota);
			while ((nota >= 0) && (nota <= 10)){
				arreglo[i][j]= nota;
			}
		}
	}
	return;
}

int promedio(int arreglo[Z][N]){
	int i, j, contador;
	float sum, promedio;
	contador = 0;
	for (i=0;i<Z;i++){
		sum = 0;
		for (j=0;j<N;j++){
			sum = sum + arreglo[i][j];
		}
		promedio = sum / N;
		printf("Estudiante %d, Estado: ", i+1);
		if (promedio >= 7){
			printf("Promocionado\n");
		}else{
			if ((promedio >= 4) && (promedio < 7)){
				printf("Regular\n");
			}else{
				contador = contador +1;
				printf("Libre\n");
			}
		}
	}
	return contador;
}

void promedioParciales(int arreglo[Z][N]){
	int i, j, aux1, aux2;
	float sum, promedio, mayor, menor;
	mayor = 0;
	menor = 11;
	for (j = 0;j<N;j++){
		sum =0;
		for (i=0;i<N;i++){
			sum = sum + arreglo[i][j];
		}
		promedio = sum / Z;
		printf("Promedio general Parcial %d: %.2f \n", j+1, promedio);
		if (promedio > mayor){
			mayor = promedio;
			aux1 = j+1;
		}else{ 
			if (promedio<menor){
				menor = promedio;
				aux2 = j+1;
			}
		}
	}
	printf("Examen con peor rendimiento: %d\n", aux2);
	printf("Examen con mejor rendimiento: %d \n", aux1);
	return;
}

void notaBajaAlta(int arreglo[Z][N]){
	int i, j, mayor, menor, aux1, aux2, aux3, aux4;
	mayor = 0;
	menor = 11;
	for (i=0;i<Z;i++){
		for (j=0;j<N;j++){
			if (arreglo[i][j] > mayor){
				mayor = arreglo[i][j];
				aux1 = i+1;
				aux2 = j+1;
			}else{
				if (arreglo[i][j] < menor){
					menor = arreglo[i][j];
					aux3 = i+1;
					aux4 = j+1;	
				}
			}
		}
	}
	printf("Nota mas alta de la matriz: %d, Corresponde al estudiante %d, en el parcial %d \n", mayor, aux1, aux2);
	printf("Nota mas baja de la matriz: %d, Corresponde al estudiante %d, en el parcial %d \n", menor, aux3, aux4);	
	return;
}	

int main(){
	int arreglo[Z][N], cont;
	carga(arreglo);
	cont = promedio(arreglo);
	promedioParciales(arreglo);
	notaBajaAlta(arreglo);
	printf("Cantidad de alumnos en condición Libre: %d \n", cont);
}


