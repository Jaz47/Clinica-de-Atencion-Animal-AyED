#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void menuPrincipal();


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
*/
struct fecha{
	int dia, mes, anio;	
};


typedef char cadena [60];

struct Usuarios{
	cadena usuario;
	cadena contras;   
	cadena ape_y_nomb;
};

struct Veterinario{
    cadena ApellidoyNombre;
    int Matric; 
    int DNI;
    cadena Telefono;
    cadena Usuario;
    cadena contr;
};

struct Mascota{
	cadena Apellido_y_Nombre;
    cadena Domicilio ;
    int DNI_Duenio ;
    cadena Localidad;
    fecha Fecha_de_Nac;
    float Peso; 
    cadena Telefono;
};



struct Turnos{
	int Matricula_de_Veterinario;
    fecha Fecha ;
    int DNI_Duenio; 
    cadena Detalle_de_Atencion;
    bool borrado;
};


void user(FILE *Arch_Usua, cadena &aux){
	
	
	bool bandera = false;
	
	do{
		int longitud, contadorMayus=0, contadorNum=0;
		printf("\nIngrese su nombre de usuario: ");
		_flushall();
		gets(aux);
		longitud = strlen(aux);
		
		if (longitud > 5 && longitud < 11)
		{
			if (aux[0] >= 'a' && aux[0] <= 'z')
			{
				for (int i=0; i<longitud; i++)
				{
					if (aux[i] >= 'A' && aux[i] <= 'Z')
					{
						contadorMayus++;
					}
					else
					{
						if (aux[i] >= '0' && aux[i] <= '9')
						{
							contadorNum++;
						}
					}
				}
				if (contadorMayus > 1 && contadorNum < 4)
				{
					bandera = true;
				}
			}
		}
		if(bandera == false){
			printf("\nEl nombre de usuario ingresado no cumple con alguna de las condiciones dadas.");
			printf("\nVuelva a intentar.\n\n");
		}
	}while(bandera == false);
}

void password(FILE *Arch_Usua, cadena &password){
	int Mayus,Minus,Num,Signos,NumConsecutivos,letrasCons;
	bool Band = false;
	cadena passAux;
	
	do{
		Mayus = 0, Minus = 0, Num = 0, Signos = 0, NumConsecutivos = 0, letrasCons = 1;
		
		printf("\nIngrese su contrasenia: ");
		_flushall();
		gets(passAux);
		strcpy(password, passAux);

		for(int i=0; i<strlen(passAux); i++)
		{
			if (passAux[i] >='A' && passAux[i] <='Z')
			{
			Mayus++;		
			} 
			else 
			{
				if (passAux[i] >='a' && passAux[i] <='z')
				{
				 Minus++;	
				}
				else
				{
					if (passAux[i] >= '0' && passAux[i] <= '9')
					{
						Num++;
						NumConsecutivos++;
					}
					else
					{
						Signos++;
					}
				}
	 		}
		}
		strlwr(passAux);
		
		for(int i=0; i<strlen(passAux); i++)
		{
			if (passAux[i] >= 'a' && passAux[i] <= 'z')
			{
			   if(i>0 && passAux[i-1]>'9' && passAux[i]==passAux[i-1] + 1)
			   {
			   		letrasCons++;
			   } 			
			}
		}	
		if (Mayus >= 1 && Minus >= 1 && Num >= 1 && Signos == 0 && letrasCons != 2 && NumConsecutivos <= 3)
		{
			Band = true;
		}	
	}while(Band == false);
	 
}

