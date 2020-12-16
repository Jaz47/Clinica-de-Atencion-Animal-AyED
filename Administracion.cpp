#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"

//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;

//Funciones Utilizadas
void reg_veter(FILE *Arch_Veter);
void reg_asis(FILE *Arch_Usua);
void Ranking(FILE *Arch_Veter);
void aten_vet(FILE *Arch_Veter);

main(){
	
	int Opc;
	cadena Clv;
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
   scanf("%d", &Opc);
		
   switch (Opc){
   	case 1: reg_veter(Arch_Veter);
   		break;
   	case 2:reg_asis(Arch_Usua);
   		break;
   	case 3:
   		break;
   	case 4:
   	    break;
   }
   
	}while(Opc!=5);
 
}

void reg_asis(FILE *Arch_Usua){
	Usuarios u;
	cadena passAux, userAux;
	Arch_Usua=fopen("Usuarios.dat", "a+b");
	
	
	printf("Apellido y nombre del Asistente: ");
	scanf("%s", &u.usuario);
    user(Arch_Usua,userAux);
    strcpy(u.usuario, userAux);
    
    password(Arch_Usua,passAux);
	strcpy(u.contras, passAux);	
	fwrite(&u, sizeof(Usuarios),1,Arch_Usua);
	fclose(Arch_Usua);
}

void reg_veter(FILE *Arch_Veter){
	Veterinario vet;
	cadena passAux, userAux;
	Arch_Veter=fopen("Veterinarios.dat", "a+b");
	
	
	printf("Apellido y nombre del veterinario: ");
	scanf("%s", &vet.ApellidoyNombre);
	_flushall();	
	 printf("DNI del Veterinario: ");
	 scanf("%d",&vet.DNI);
	
       printf("\nMatricula del Veterinario: ");
       _flushall();
       gets(vet.Matricula);
    
   
    printf("Telefono: ");
    scanf("%s", &vet.Telefono);
    user(Arch_Veter,userAux);
    strcpy(vet.Usuario,userAux);
    
    password(Arch_Veter,passAux);
	strcpy(vet.contr, passAux);	
	fwrite(&vet, sizeof(Veterinario),1,Arch_Veter);
	fclose(Arch_Veter);
}




/*void Ranking(FILE *Arch_Veter){
	 Arch_Veter=fopen("Veterinarios.dat","rb");
	 Veterinario Lect;
	 int Matricula[100];
	 int Cantidades[100];
	 int c=0;
	 
	 fread(&Lect, sizeof(Veterinario), 1,Arch_Veter);
	 while(!feof(Arch_Veter)){
	 	Matricula[c]=Lect.Matricula;
	 	//Cantidades[c]=aten_vet(Arch_Veter,Lect.Matricula);
	 }
}*/
	
void aten_vet(FILE *Arch_Veter){
	char a;
	int b=0;
	Turnos tur;
	int mat;
	int mes, anio;
	
	printf("\n                         Â°Â°ATENCION POR VETERINARIAÂ°Â°");
	printf("****************************************************************************************");
	
	do{
		printf("\nIngrese Matricula del Veterinario:");
	    scanf("%d",&mat);
	    printf("\nIngrese mes y anio:");
	    scanf("%d",&mes,&anio);
	    
		fread(&a, sizeof(Turnos),1,Arch_Veter);
		while(!feof(Arch_Veter)){
			if(mat==tur.Matricula_de_Veterinario && mes==tur.Fecha.mes && anio==tur.Fecha.anio ){
				printf("\n\nMatricula del Veterinario: %d", tur.Matricula_de_Veterinario);
				printf("\nDNI del duenio: %d", tur.DNI_Duenio);
				printf("\nDetalles de la Atencion: %s ",tur.Detalle_de_Atencion);
				b=1;
			}
			fread(&a, sizeof(Turnos), 1,Arch_Veter);
		}
	}while(b==0);
}
