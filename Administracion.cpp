#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"



void reg_veter();

main(){
	int Opc;
	do{
		 printf("\t-----------------------------------------------\n");
     printf("\t|      **Modulo de Administracion**           |\n");
     printf("\t| 1-> Registrar Veterinario                   |\n");
     printf("\t| 2-> Registrar Usuario Asistente             |\n");
     printf("\t| 3-> Atencion por Veterinaria                |\n");
     printf("\t| 4-> Ranking de Veterinario por Atencion     |\n");
     printf("\t| 5-> Cerrar Aplicacion                       |\n");
     printf("\t-----------------------------------------------\n");
   
   
   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   
   switch (Opc){
   	
   }
   
	}while(Opc!=5);
	
}

void reg_veter(){
	Veterinario vet;
	FILE *Arch_Veter;
	
	Arch_Veter=fopen("Veterinarios.dat", "a+b");
	
	_flushall();
	
		printf("Apellido y nombre del veterinario: ");
		gets(vet.ApellidoyNombre);
		
	
	printf("DNI del Veterinario: ");
	scanf("%d",&vet.DNI);
	
    printf("\nMatricula del Veterinario: ");
    scanf("%f", &vet.Matricula);
    
    _flushall();
    printf("Telefono: ");
    gets(vet.Telefono);
		
	fwrite(&vet, sizeof(Veterinario),1,v);
	fclose(Arch_Veter);
}
