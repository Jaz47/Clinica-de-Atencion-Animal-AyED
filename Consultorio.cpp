#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"

//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;

//Funciones Globales Utilizadas
bool Iniciar_Ses();
void list_turnos(FILE *Arch_Veter);  // Mostrar los turnos de la fecha, osea cuantos registros hay para esa fecha
void Evoluc_masc();   // Modulo Asistente

main(){
	int Opc;
	bool Inicio=false;

	
	do{
		printf("\t------------------------------------------------------\n");
         printf("\t|      **Modulo de Consultorio Veterinario**            |\n");
         printf("\t| 1-> Iniciar Sesion                                 |\n");
         printf("\t| 2-> Visualizar Lista de Espera de Turnos (Informes)|\n");   // Mostrar los turnos de la fecha, osea cuantos registros hay para esa fecha
         printf("\t| 3-> Registrar Evolucion de la Mascota              |\n");  //Baja Logica
         printf("\t| 4-> Cerrar Aplicacion                              |\n");
         printf("\t------------------------------------------------------\n");
   
   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   //system("cls");
   
   switch(Opc){
   	case 1: Inicio=Iniciar_Ses();
   	        break;
   	case 2: if(!Inicio) printf("\nDebe Iniciar Sesion para poder Continuar!!!!!!\n\n");
   	        else Iniciar_Ses();
   	    break;
   	case 3: if(!Inicio) printf("\nDebe Iniciar Sesion para poder Continuar!!!!!!\n\n");
   	        else Iniciar_Ses();
   	    break;
   }
   	}while(Opc!=4);
}
//Inicio de Sesion
bool Iniciar_Ses(){
	FILE *Arch_Usua=fopen("Veterinarios.dat","rb");
	
	Veterinario vet;
	cadena mat,pass;
	printf("\nIngrese la Matricula del Veterinario: \n");
	_flushall();
	gets(mat);
	printf("\nIngrese su Contrasenia: \n");
	gets(pass);
	
	fread(&vet, sizeof(vet),1,Arch_Veter);
	while(!feof(Arch_Veter)){
		if (vet.Matricula==0 && strcmp(vet.contras,pass)==0);
	}return true;
	fread(&vet, sizeof(vet),1,Arch_Veter);
}

void list_turnos(FILE *Arch_Turns){  //Falta Corregir detalles
	Turnos Turns;
	int dia,Mes,Anio, Matric;   
	
	Arch_Turns=fopen("Turnos.dat","rb");
	if(Arch_Turns==NULL){
		printf("\n\tÃ‚Â¡EROOR!.. El Archivo no Pudo Abrirse");
		exit(1);
	}
	printf("\nIngresar fecha para mostrar sus respectivos turnos: ");
	scanf("%d/%d/%d",&dia,&Mes,&Anio);
	printf("\nIngresar Matricula del veterinario: ");
	scanf("%d",&Matric);
	printf("\nLA LISTA DE ESPERA ES\n");
	fread(&Turns, sizeof(Turnos), 1,Arch_Turns);
	while(!feof(Arch_Turns)){  //Mientras no sea final de archivo
	printf("\n%d/%d/%d",Turns.Fecha.dia,Turns.Fecha.mes,Turns.Fecha.anio);
		fread(&Turns, sizeof(Turnos), 1,Arch_Turns);
	}
	printf("\n\n");
	fclose(Arch_Turns);
	
	
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
					scanf("%s",&tur.Detalle_de_Atencion);
					tur.borrado=true;
			//		fseek(Arch_Masc, -sizeof(Turnos), SEEK_CUR);  //Retrocede
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
