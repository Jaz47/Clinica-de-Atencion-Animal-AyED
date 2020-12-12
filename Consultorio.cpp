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


void list_turnos(FILE *Arch_Turns){
	Turnos Turns;
	
	Arch_Turns=fopen("Turnos.dat","rb");
	if(Arch_Turns==NULL){
		printf("\n\tÂ¡EROOR!.. El Archivo no Pudo Abrirse");
		exit(1);
	}
	
	printf("\nLA LISTA DE ESPERA ES\n");
	fread(&Turns, sizeof(Turnos), 1,Arch_Turns);
	while(!feof(Arch_Turns)){  //Mientras no sea final de archivo
	printf("\n%d/%d/%d",Turns.Fecha.dia,Turns.Fecha.mes,Turns.Fecha.anio);
		fread(&Turns, sizeof(Turnos), 1,Arch_Turns);
	}
	printf("\n\n");
	fclose(Arch_Turns);
		//FALTA CORREGIR, IMCOMPLETO
	
}
	
}

void Evoluc_masc(){
	Veterinario Veter;
	Mascota masc;
	Turnos tur;
	cadena apynom;
	
	_flushall();
	printf("Apellido y Nombre de la mascota a atender: ");
	gets(apynom);
	Arch_Turns=fopen("Turnos.dat", "r+b");
	Arch_Masc=fopen("Mascotas.dat", "r+b");
	
	while(!feof(Arch_Masc)){
		if(strcmp(apynom,masc.Apellido_y_Nombre)==0){
			while(!feof(Arch_Turns)){
				if(masc.DNI_Duenio==tur.DNI_Duenio){
					rewind(Arch_Masc);
					printf("\nDetalle de evolucion de la mascota: \n ");
					gets(tur.Detalle_de_Atencion);
					tur.borrado=true;
					fseek(Arch_Masc, -sizeof(Turnos), SEEK_CUR);
					fwrite(&masc,sizeof(Mascota),1, Arch_Masc);
					printf("El Registro se dio de baja\n\n");
					printf("\n");
				}
				fread(&tur,sizeof(Turnos),1,Arch_Turns);
			}
		}
		fread(&masc,sizeof(Mascota),1,Arch_Masc);
	}
	fclose(Arch_Masc);
	fclose(Arch_Turns);
}
