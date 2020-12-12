#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"

FILE *Arch_Veter;
FILE *Arch_Usuar;

void reg_veter(FILE *Arch_Veter);
void Usuario_Valid(FILE *Arch_Usua);
void aten_vet();

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
   scanf("%d", &Opc);
   
   switch (Opc){
   	case 1: reg_veter(Arch_Veter);  //Crear Usuarios para el Modul. de Consultorio
		   break;
   	case 2: Usuario_Valid(Arch_Usua);  //Crear Usuarios para Modul. Asistente
		   break;
   	case 3:
		   break;
   	case 4:
		   break;
   	
   }
   
	}while(Opc!=5);
	
}

void reg_veter(FILE *Arch_Veter){
	Veterinario vet;
	
	
	Arch_Veter=fopen("Veterinarios.dat", "a+b");   //Apertura del Arch_Veter
	
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
		
	fwrite(&vet, sizeof(Veterinario),1,Arch_Veter);
	fclose(Arch_Veter);
}

void Usuario_Valid(FILE *Arch_Usua){
	Usuarios Usuari;
	int Long, Mays = 0, Cant_Nro = 0; //importante inicializar los contadores
	bool bandera;
	
	Arch_Usua=fopen("Usuario.dat","a+b");
	do{
	printf("\nRegistrar usuario: ");
	_flushall();
	gets(Usuari.usuario);
	
	Long= strlen(Usuari.usuario);
	
	if(Long>5 && Long<11 && Usuari.usuario[0]>='a' && Usuari.usuario[0]<='z'){
		for(int i=0; i<strlen(Usuari.usuario); i++){
			if(Usuari.usuario[i]>='A' && Usuari.usuario[i]<='Z') Mays++;
			else if(Usuari.usuario[i]>='0' && Usuari.usuario[i]<='9') Cant_Nro++;						
		}		
		if(Mays >= 2 && Cant_Nro<=3){
			bandera= true;
			printf("\nUsuario Valido\n");	
			fwrite(&Usuari, sizeof(Usuarios), 1,Arch_Usua);  //Guardado de Usuarios Valido, para el modulo del Asistente
		}	
	
	}

	if(bandera==false){
		printf("\nEl usuario no cumple algunas de las condiciones\n");
		printf("\nPOR FAVOR VUELVA A INTENTARLO..\n\n");
	}
}while(bandera==false);
fclose(Arch_Usua);  //Cierre del del Arcj_Usua
	
	//FALTA HACER LA COMPARACION QUE SEA UNICO
}
	


