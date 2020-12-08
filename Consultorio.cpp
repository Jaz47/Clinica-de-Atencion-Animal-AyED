#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"


void list_turnos();
void Evoluc_masc();

main(){
	FILE *Arch_Veter;
	Arch_Veter=fopen("Veterinarios.dat", "a+b");
	int Opc;
	
	do{
		printf("\t------------------------------------------------------\n");
         printf("\t|      **Modulo de Consultorio Veterinario**            |\n");
         printf("\t| 1-> Iniciar Sesion                                 |\n");
         printf("\t| 2-> Visualizar Lista de Espera de Turnos (Informes)|\n");
         printf("\t| 3-> Registrar Evolucion de la Mascota              |\n");
         printf("\t| 4-> Cerrar Aplicacion                              |\n");
         printf("\t------------------------------------------------------\n");
   
   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   system("cls");
   
   switch(Opc){
   	case 1:
   	case 2:
   	    t=fopen("Turnos.dat","rb");
   	    if(t==NULL){
   	    	printf("LO SENTIMOS NO SE REGISTRAN TURNOS\n");
   	    	system("pause");
   	    	break;
		   }
		   list_turnos(t);
		   fclose(t);
		   break;
   	case 3:
   	    Arch_Veter=fopen("Mascotas.dat","a+b");
   	    Evoluc_masc(Arch_Veter);
   	    fclose(Arch_Veter);
   	    break;
   }
   	}while(Opc!=4);
}


void list_turnos(){
	
}

void Evoluc_masc(){
	
}
