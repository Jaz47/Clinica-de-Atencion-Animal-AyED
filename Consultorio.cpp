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

typedef char cadena [380];
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
