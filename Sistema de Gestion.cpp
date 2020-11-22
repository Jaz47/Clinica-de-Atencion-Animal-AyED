#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"

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
    fecha Fecha_de_Nacimiento;
    float Peso; 
    char Telefono[25];
};

struct Turnos{
	int Matricula_de_Veterinario;
    fecha Fecha ;
    int DNI_Duenio; 
    char Detalle_de_Atencion[380];
};

main(){
	int opcion;
	do{
		menuPrincipal();
		printf("Seleccione la Opcion: ");
		scanf("%d", &opcion);
		
	
	}while (opcion != 4);
}
