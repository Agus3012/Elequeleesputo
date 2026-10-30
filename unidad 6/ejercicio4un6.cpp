#include <stdio.h>
#include <string.h>
typedef struct{
	char nomb[50];
	int reg;
	char cond;
}info;

void grabar(FILE *archi);
void mostrar(FILE *archi);
void comparar(FILE *archi, FILE *archi2);
void grabar2(FILE *archi, FILE *archi2, FILE *archi3);
void aprobados(FILE *archi, FILE *archi2);

int main(){
	FILE *archi;
	FILE *archi2;
	FILE *archi3;
	archi = fopen("alumnosPP.dat", "wb");
	if (archi != NULL){
		grabar(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi2 = fopen("alumnosAL.dat", "wb");
	if(archi2 != NULL){
		grabar(archi2);
		fclose(archi2);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("alumnosPP.dat", "rb");
	if (archi != NULL){
		mostrar(archi);
		fclose(archi);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi2 = fopen("alumnosAL.dat", "rb");
	if (archi2 != NULL){
		mostrar(archi2);
		fclose(archi2);
	}else{
		printf("El archivo no se abrio correctamente\n");
	}
	archi = fopen("alumnosPP.dat", "rb");
	archi2 = fopen("alumnosAL.dat", "rb");
	if (archi != NULL && archi2 != NULL){
		comparar(archi, archi2);
		fclose(archi);
		fclose(archi2);
	}else{
		printf("Los archivo no se abrio correctamente\n");
	}
	archi = fopen("alumnosPP.dat", "rb");
	archi2 = fopen("alumnosAL.dat", "rb");
	archi3 = fopen("ambas.dat", "wb");
	if (archi3 != NULL && archi != NULL && archi2 != NULL){
		grabar2(archi, archi2, archi3);
		fclose(archi);
		fclose(archi2);
		fclose(archi3);
	}else{
		printf("Los archivos no se abrieron correctamente\n");
	}
	archi = fopen("alumnosPP.dat", "rb");
	archi2 = fopen("alumnosAL.dat", "rb");
	if(archi != NULL && archi2 != NULL){
		aprobados(archi, archi2);
		fclose(archi);
		fclose(archi2);
	}else{
		printf("Los archivos no se abrieron correctamente\n");
	}
	
}

void grabar(FILE *archi){
	info aux;
	printf("Ingrese nombre del alumno: (termina con FIN)\n");
	fgets(aux.nomb, 50, stdin);
	while(strncmp(aux.nomb, "FIN", 3) != 0){
		printf("Ingrese numero de registro: \n");
		scanf("%d", &aux.reg);
		while (getchar() != '\n');
		printf("Ingrese condicion del alumno: \n");
		scanf("%c", &aux.cond);
		while (getchar() != '\n');
		fwrite(&aux, sizeof(aux), 1, archi);
		printf("Ingrese nombre del alumno: (termina con FIN)\n");
		fgets(aux.nomb, 50, stdin);
	}
}

void mostrar(FILE *archi){
	info aux;
	printf("Listado con los datos de los alumnos: \n");
	while((fread (&aux, sizeof(info), 1, archi)) == 1){ //fread recupera los datos del archivo, mientras que fwrite los graba en él
		printf("Nombre del alumno: %s\n", aux.nomb);
		printf("Registro del alumno: %d\n", aux.reg);
		printf("Condicion del alumno: %c\n", aux.cond);
	}
}

void comparar(FILE *archi, FILE *archi2){
	info aux, aux2;
	int leyo1 = fread(&aux, sizeof(info), 1, archi);
	int leyo2 = fread(&aux2, sizeof(info), 1, archi2);
	printf("Nombre de los alumnos que estan cursando ambas materias:  \n");
	while (leyo1 == 1 && leyo2 == 1){
		if (aux.reg == aux2.reg){
			printf("%s", aux.nomb);
			leyo1 = fread(&aux, sizeof(info), 1, archi);
            leyo2 = fread(&aux2, sizeof(info), 1, archi2);
		}else{
			if(aux.reg < aux2.reg){
				leyo1 = fread(&aux, sizeof(info), 1, archi);
			}else{
				if(aux.reg >aux2.reg){
					leyo2 = fread(&aux2, sizeof(info), 1, archi2);
				}
			}
		}
	}
}

void grabar2(FILE *archi, FILE *archi2, FILE *archi3){
	info nuevo, aux, aux2;
	int leyo1 = fread(&aux, sizeof(info), 1, archi);
	int leyo2 = fread(&aux2, sizeof(info), 1, archi2);
	while ( leyo1 == 1 && leyo2 == 1){
		if(aux.reg == aux2.reg){
			if(aux.cond == 'A' && aux2.cond == 'A'){
				nuevo = aux;
				fwrite(&nuevo, sizeof(aux), 1, archi3);
			}
			leyo1 = fread(&aux, sizeof(info), 1, archi);
			leyo2 = fread(&aux2, sizeof(info), 1, archi2);
		}else{
			if(aux.reg < aux2.reg){
				leyo1 = fread(&aux, sizeof(info), 1, archi);
			}else{
				if(aux.reg >aux2.reg){
					leyo2 = fread(&aux2, sizeof(info), 1, archi2);
				}
			}	
		}
	}
}

void aprobados(FILE *archi, FILE *archi2){
	info aux, aux2;
	int cont1, cont2;
	cont1 = 0;
	cont2 = 0;
	while(fread(&aux, sizeof(info), 1, archi) == 1){
		if (aux.cond == 'A'){
			cont1 = cont1 +1;
		}
	}
	while (fread(&aux2, sizeof(info), 1, archi2) ==1){
		if(aux2.cond == 'A'){
			cont2 = cont2 +1;
		}
	}
	if (cont1 > cont2){
		printf("Los alumnos de la materia procedural tiene mas aprobados\n");
	}else{
		if(cont1<cont2){
			printf("Los alumnos de la materia algebra tiene mas aprobados\n");
		}else{
			printf("Ambas materias tienen igual cantidad de aprobados\n");
		}
	}
}

