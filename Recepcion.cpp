#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"

//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;


void reg_mascota(FILE *Arch_Masc);
void reg_turnos(FILE *Arch_Turns);
void listVetFecha(FILE *Arch_Veter);

main(){
	int Opc;
	bool Inicio=false;
	
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
   		break;
   		
   	case 2:
   		
   	break;
   	
   	case 3: 
   		 
   		break;
   		
   	case 4:;
   }
	}while (Opc != 5);
}


void reg_mascota(){
	Mascota masc;
	
	Arch_Masc=fopen("Mascotas.dat", "a+b");
	
	
	printf("\nNombre de la Mascota: ");
	_flushall();
	gets(masc.Apellido_y_Nombre);
		
	
	printf("\nDNI del Duenio: ");
	scanf("%d",&masc.DNI_Duenio);
	
	_flushall();
	printf("\nDomicilio: ");
	gets(masc.Domicilio);
	_flushall();
	printf("\nLocalidad: ");
	gets(masc.Localidad);
		
	
	printf("\nFecha de nacimiento de la Mascota(dia,mes,anio): ");
    scanf("%d/%d/%d", &masc.Fecha_de_Nac.dia,&masc.Fecha_de_Nac.mes,&masc.Fecha_de_Nac.anio);
    
    printf("\nPeso de la Mascota: ");
    scanf("%.2f", &masc.Peso);
    
    _flushall();
    printf("\nTelefono del DueÃ±o: ");
    gets(masc.Telefono);
		
	fwrite(&masc, sizeof(Mascota),1,Arch_Masc);
	fclose(Arch_Masc);
}

void reg_turnos(){
	Turnos turn;
	Mascota masc;
	Veterinario vet;
	int mat;
	bool b=false;
	
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
		printf(" Disculpe su Matricula Ingresada NO es valida");
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
	printf("Ingresar aÃ±o de atencion que desea buscar: ");
	scanf("%d", &a);
	
	printf("\nIngresar Matricula del Veterinario que desea buscar: ");
	scanf("%d", &mat);
	
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
									scanf("%d",&vet.Matricula);
									printf("\nFecha de la consulta:");
									printf("\nDia/ Mes/ Anio: %d/ %d/ %d",tur.Fecha.dia,tur.Fecha.mes,tur.Fecha.anio );
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
