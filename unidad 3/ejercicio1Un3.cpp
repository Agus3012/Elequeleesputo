#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 35

int carga(int nums[N]){
	int i,band,cont1,cont2;
    band = 0;
	cont1,cont2 = 0;
	srand(time(NULL));
	for (i=0;i<N;i++){
		nums[i] = rand()%500;
		if(nums[i] % 2 == 0){
			cont1=cont1+1;
		}else{
			cont2=cont2+1;
		}
	}
	if(cont1==cont2){
		band = 1;
	}
	return(band);
}

float promedio(int nums[N]){
	int i, acum;
	float prom;
	acum=0;
	for(i=0;i<N;i++){
		acum = acum + nums[i];		
	}
	return(acum/N);
}

 void supPro(int nums[N], float promedio){
	int cont=0;
	int i;
	for(i=0;i<N;i++){
		if(nums[i] > promedio){
			cont = cont + 1;
		}
	}
	printf("%d numeros superaron al promedio\n",cont);
	return;
}

void mostrarDir(int nums[N], int numero){
	int i;
	for(i=0;i<N;i++){
		if(nums[i]<numero){
			printf("%p\n",(void*)&nums[i]);
		}
	}
	return;
}



int main(){
	int nums[N], numero; 
	float prom;
	int bandera = carga(nums);
	if(bandera == 0){
		printf("la cantidad de numeros pares e impares no es la misma\n");
	}else{
		printf("la cantidad de numeros pares es igual a la cantidad de numeros impares\n");
	}
	prom = promedio(nums);
	printf("el promedio es de %.1f\n",prom);
	supPro(nums,prom);
	printf("ingrese un numero\n");
	scanf("%d",&numero);	
	mostrarDir(nums,numero);
	return 0;
}
