#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"

void reg_mascota();
void reg_turnos();
void listVetFecha();

main(){
	int Opc;
	FILE *Arch_Turns, *Arch_Veter, *Arch_Masc;
	
	do{
  printf("\t-----------------------------------------------\n");
  printf("\t|      **Modulo de Asistente**                |\n");
  printf("\t| 1-> Iniciar Sesion                          |\n");
  printf("\t| 2-> Registrar Mascota                       |\n");
  printf("\t| 3-> Registrar Turnos                        |\n");
  printf("\t| 4-> Listar Atencion por Veterinario y Fecha |\n");
  printf("\t| 5-> Cerrar Aplicacion                       |\n");
  printf("\t-----------------------------------------------\n");

   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   
   switch (Opc){
   	case 1:
   	case 2:
   		Arch_Masc=fopen("Mascotas.dat","a+b");
   		reg_mascota; 
   		fclose(Arch_Masc);
   	break;
   	
   	case 3:
   		 Arch_Turns=fopen("Turnos.dat","rb");
   		 reg_turnos(Arch_Turns);
   		 fclose(Arch_Turns);
   		break;
   		
   	case 4:;
   }
	}while (Opc != 5);
}


void reg_mascota(){
	Mascota masc;
	
	Arch_Masc=fopen("Mascotas.dat", "a+b");
	
	_flushall();
	
		printf("Nombre de la mascota: ");
		gets(masc.Apellido_y_Nombre);
		
	
	printf("DNI del duenio: ");
	scanf("%d",&masc.DNI_Duenio);
	
	_flushall();

		printf("Domicilio: ");
		gets(masc.Domicilio);
		
	
	_flushall();
	
		printf("Localidad: ");
		gets(masc.Localidad);
		
	
	printf("Fecha de nacimiento de la mascota(dia,mes,anio): ");
    scanf("%d/%d/%d", &masc.Fecha_de_Nac.dia,&masc.Fecha_de_Nac.mes,&masc.Fecha_de_Nac.anio);
    
    printf("\nPeso de la Mascota: ");
    scanf("%f", &masc.Peso);
    
    _flushall();
    printf("Telefono del Dueño: ");
    gets(masc.Telefono);
		
	fwrite(&masc, sizeof(Mascota),1,Arch_Masc);
	fclose(Arch_Masc);
}

void reg_turnos(){
	Turnos turn;
	Mascota masc;
	Veterinario vet;
	int mat;
	bool b==false;
	
	printf("Ingresar las Matricula del Veterinario: ");
	scanf("%d", &mat);
	Arch_Turns=fopen("Turnos.dat","a+b");
	
	Arch_Veter=fopen("Veterinarios.dat", "rb");
	fread(&vet, sizeof(Veterinario),1,Arch_Veter);
	
	while(!feof(Arch_Veter)){
		if(mat==vet.Matricula){
			turn.Matricula_de_Veterinario=vet.Matricula;
			printf("\nDni del duenio de la mascota: ");
			scanf("%d", &turn.DNI_Duenio);
			
			printf("/n Fecha del Turno (dia/mes/anio): ");
			scanf("%d/%d%d", &turn.Fecha.dia,turn.Fecha.mes,turn.Fecha.anio);
			
			
			fwrite(&turn, sizeof(Turnos),1,Arch_Turns);
			b=true;
		}
		fread(&vet, sizeof(Veterinario),1,Arch_Veter);
	}
	if(b==false){
		printf("Matricula Ingresada NO valida");
	}
	fclose(Arch_Veter);
	fclose(Arch_Turns);
	
}

void listVetFecha(){
	int d,m,a,mat;
	Turnos tur;
	Veterinario vet;
	fecha fec;
	
	
	printf("Ingresar dia de atencion que desea buscar: ");
	scanf("%d", &d);
	printf("Ingresar  mes de atencion que desea buscar: ");
	scanf("%d", &m);
	printf("Ingresar año de atencion que desea buscar: ");
	scanf("%d", &a);
	
	printf("\nIngresar Matricula del Veterinario que desea buscar: ");
	scanf("%d", &mat)
	
	Arch_Turns=fopen("Turnos.dat", "r+b");
	Arch_Veter=fopen("Veterinarios.dat", "r+b");
	
	
	
	while(!feof(Arch_Veter)){
		if(mat==vet.Matricula){
			while(!feof(Arch_Turns)){
				if (d==tur.Fecha.dia){
					while(!feof(Arch_Turns)){
						if (m==tur.Fecha.mes){
							while(!feof(Arch_Turns)){
								if (a==tur.Fecha.anio){
									printf("\nMatricula del Veterinario a cargo: ");
									puts(vet.Matricula);
									printf("\nFecha de la consulta:");
									printf("\nDIA: %d",tur.Fecha.dia);
									printf("\nMES: %d",tur.Fecha.mes);
									printf("\nANIO: %d",tur.Fecha.anio);
								}
								fread(&tur,sizeof(Turnos),1,Arch_Turns);
							}
						}
						fread(&tur,sizeof(Turnos),1,Arch_Turns);
					}
				}
				fread(&tur,sizeof(Turnos),1,Arch_Turns);
			}
		}
		fread(&vet,sizeof(Veterinario),1,Arch_Veter);
	}
	
	fclose(Arch_Veter);
	fclose(Arch_Turns);
	
}
