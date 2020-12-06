#include<stdio.h>
#include <stdlib.h>
#include <string.h>

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


void list_turnos(FILE *t);
void Evoluc_masc(FILE *m);

main(){
	FILE *p,*m,*t;
	p=fopen("Veterinarios.dat", "a+b");
	int Opc;
	
	do{
		printf("\t------------------------------------------------------\n");
         printf("\t|      **Modulo Consultorio Veterinario**            |\n");
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
   	    	printf("NO SE REGISTRAN TURNOS\n");
   	    	system("pause");
   	    	break;
		   }
		   list_turnos(t);
		   fclose(t);
		   break;
   	case 3:
   	    e=fopen("Mascotas.dat","a+b");
   	    Evoluc_masc(m);
   	    fclose(m);
   	    break;
   }
   	}while(Opc!=4);
}


void list_turnos(FILE *t){
	
}

void Evoluc_masc(FILE *m){
	
}
