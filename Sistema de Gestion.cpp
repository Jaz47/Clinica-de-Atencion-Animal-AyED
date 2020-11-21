#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"

typedef char cadena[100];

struct fecha{
	int dia, mes, anio;	
};



struct Usuarios{
	cadena usuario[10];
	cadena contras[10];   
	cadena ape_y_nomb[60];
};

struct Veterinario{
    cadena ApellidoyNombre[60];
    int Matricula; 
    int DNI;
    cadena Telefono[25];
};

struct Mascota{
	cadena Apellido_y_Nombre[60];
    cadena Domicilio [60];
    int DNI_Duenio ;
    cadena Localidad[60];
    fecha Fecha_de_Nac;
    float Peso; 
    cadena Telefono[25];
};

struct Turnos{
	int Matricula_de_Veterinario;
    fecha Fecha ;
    int DNI_Duenio; 
    cadena Detalle_de_Atencion[380];
};

int Opc;

main(){
	

	do{
		menuPrincipal();
		printf("\nIngresar Opcion: ");
        scanf("%d", &Opc);
        system("cls");
		switch(Opc){
			case 1: Menu_Consultorio();
			       do{
			       	
				   }while(Opc!=4);
				   	  
				break;
			
			case 2: Modul_Asist();
			      do{
			       	
				   }while(Opc!=5);
			    break;
			
			case 3: Modul_Admin();
			      do{
			       	
				   }while(Opc!=5);
			    break;
		}
		
		system("PAUSE");
	
	}while (Opc != 4);
}
