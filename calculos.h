#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPrincipal();

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



void menuPrincipal() {
system("cls");
  printf("\t----------------------------------------\n");
  printf("\t|      **MENU PRINCIPAL**              |\n");
  printf("\t| 1-> Modulo Consultorio Veterinario   |\n");
  printf("\t| 2-> Modulo de Asistente              |\n");
  printf("\t| 3-> Modulo de Administracion         |\n");
  printf("\t| 4-> Salir                            |\n");
  printf("\t----------------------------------------\n");
 }

