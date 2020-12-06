#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha{
	int dia, mes, anio;	
};



struct Usuarios{
	char usuario[10];
	char contras[10];   
	char ape_y_nomb[60];
};

struct Veterinario{
    char ApellidoyNombre[60];
    int Matricula; 
    int DNI;
    char Telefono[25];
};

struct Mascota{
	char Apellido_y_Nombre[60];
    char Domicilio [60];
    int DNI_Duenio ;
    char Localidad[60];
    fecha Fecha_de_Nac;
    float Peso; 
    char Telefono[25];
};

typedef char cadena[380];

struct Turnos{
	int Matricula_de_Veterinario;
    fecha Fecha ;
    int DNI_Duenio; 
    cadena Detalle_de_Atencion[380];
};

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
	
	
	v=fopen("Veterinarios.dat", "a+b");
	
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
	fclose(m);
}
