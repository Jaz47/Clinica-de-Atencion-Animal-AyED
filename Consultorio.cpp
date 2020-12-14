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
bool Iniciar_Ses(FILE *Arch_Veter);
void list_turnos(FILE *Arch_Turns);  // Mostrar los turnos de la fecha, osea cuantos registros hay para esa fecha
void Evoluc_masc(FILE *Arch_Turns);   // Modulo Asistente

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
   	case 1: Inicio=Iniciar_Ses(Arch_Veter);
   	        if(Inicio) printf("Inicio a sesion\n");
   	        else printf("Error de Inicio\n");
   	        break;
   	case 2: if(!Inicio) printf("\nDebe Iniciar Sesion para poder Continuar!!!!!!\n\n");
   	        
   	        else Iniciar_Ses(Arch_Veter);
   	          list_turnos(Arch_Turns);
   	    break;
   	case 3: if(!Inicio) printf("\nDebe Iniciar Sesion para poder Continuar!!!!!!\n\n");
   	        else Iniciar_Ses(Arch_Veter);
   	        Evoluc_masc(Arch_Turns);
   	    break;
   }
   	}while(Opc!=4);
}
//Inicio de Sesion
bool Iniciar_Ses(FILE *Arch_Veter){
	int Matr;
	cadena pass;
	Veterinario Vetr;
	
	Arch_Veter=fopen("Veterinarios.dat","rb");
	printf("\nIngresar matricula: ");
    scanf("%d",&Matr);
	printf("\nIngresar clave: ");
	gets(pass);
	
	rewind(Arch_Veter);
	fread(&Vetr, sizeof(Vetr), 1,Arch_Veter);
	while(!feof(Arch_Veter)){
		if(Vetr.Matricula==Matr && strcmp(Vetr.contras,pass)==0){
			printf("\nBienvenido al Consultorio");
			return true;
		}
		else{
			printf("\nMatricula Incorrecta\n");
			printf("Intentelo de Nuevo\n");
		}
		system("pause");
	}
	return false;
	
	
}

void list_turnos(FILE *Arch_Turns){  //Falta Corregir detalles
	Turnos Turns;
	int dia,Mes,Anio, Matric;   
	
	Arch_Turns=fopen("Turnos.dat","rb");
	if(Arch_Turns==NULL){
		printf("\n\tÃƒâ€šÃ‚Â¡EROOR!.. El Archivo no Pudo Abrirse");
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
	
void Evoluc_masc(FILE *Arch_Turns){
   Arch_Turns = fopen("Turnos.dat","r+b");

	Turnos turno;
	int dni;
	bool bandera = false;
	
	printf("\nIngrese el DNI del duenio de la mascota a atender: ");
	scanf("%d", &dni);
	
	rewind(Arch_Turns);
	
	fread(&turno, sizeof(Turnos), 1, Arch_Turns);
	while(!feof(Arch_Turns) && bandera == false){
		
		if(turno.DNI_Duenio == dni && turno.borrado == false){
					
			printf("\nDescriba la evolucion de la mascota");
	
			_flushall();
			gets(turno.Detalle_de_Atencion);
			
			turno.borrado = true;
					
			fseek(Arch_Turns, -sizeof(Turnos), SEEK_CUR);
			fwrite(&turno, sizeof(Turnos), 1, Arch_Turns);
			printf("Registro dado de baja");
			printf("\n");
	        system("pause");
			bandera = true;
		}

		else{
			fread(&turno, sizeof(Turnos), 1, Arch_Turns);
		}
	}
	
	if(bandera == false){
		printf("\nEl DNI ingresado no existe en los registros.");
	}
	fclose(Arch_Turns);
}

