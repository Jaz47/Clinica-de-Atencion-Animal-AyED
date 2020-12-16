#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"
//cambios
//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;
bool Iniciar_Ses(FILE *Arch_Usua);
void reg_mascota(FILE *Arch_Masc);
void Reg_Turns(FILE *Arch_Veter);
void listVetFecha(FILE *Arch_Veter);

main(){
	int Opc;
	bool Inicio=false;
	
	do{
  printf("\t-----------------------------------------------\n");
  printf("\t|      *Modulo de Asistente*                  |\n");
  printf("\t| 1-> Iniciar Sesion                          |\n");
  printf("\t| 2-> Registrar Mascota                       |\n");
  printf("\t| 3-> Registrar Turnos                        |\n");
  printf("\t| 4-> Listar Atencion por Veterinario y Fecha |\n");
  printf("\t| 5-> Cerrar Aplicacion                       |\n");
  printf("\t-----------------------------------------------\n");

   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   
   switch (Opc){
   	case 1: Inicio=Iniciar_Ses(Arch_Usua); 
	    	if (Inicio) printf("\nBIENVENIDO!!!\n\n");
	    	else printf("\nERROR en inicio de sesion. VUELVA A INTENTARLO!!!\n\n");
   		break;
   		
   	case 2: if (!Inicio) printf("Inicie sesion para continuar\n");
			else reg_mascota(Arch_Masc);
			
   		break;
   	
   	case 3: if (!Inicio) printf("Inicie sesion para continuar\n");
			else Reg_Turns(Arch_Turns);
			
   		 	break;
   		
   	case 4:if (!Inicio) printf("Inicie sesion para continuar\n");
			else listVetFecha(Arch_Veter);
			
			break;
   }
	}while (Opc != 5);
}

 bool Iniciar_Ses(FILE *Arch_Usua){
	Arch_Usua=fopen("Usuarios.dat","rb");
	if(Arch_Usua==NULL){
		printf("\nEl archivo no existe!\n");
		exit(1);
	}
	
	Usuarios Lectr;
	cadena userAux, passAux;
	
	printf("\nIngrese el Usuario: ");
	_flushall();
	gets(userAux);
	printf("\nIngrese la Clave: ");
	_flushall();
	gets(passAux);
	
	fread(&Lectr, sizeof(Lectr), 1,Arch_Usua);
	while(!feof(Arch_Usua)){
		if(strcmp(Lectr.usuario,userAux)==0 && strcmp(Lectr.contras,passAux)==0){
			fclose(Arch_Usua);
			return true;
		}
		fread(&Lectr, sizeof(Lectr), 1,Arch_Usua);
	}
	return false;

}


void reg_mascota(FILE *Arch_Masc){
	Mascota masc;
	
	Arch_Masc=fopen("Mascotas.dat", "a+b");
	
	
	printf("\nNombre de la mascota: ");
	_flushall();
	gets(masc.Apellido_y_Nombre);
		
	
	printf("\nDNI del duenio: ");
	scanf("%d",&masc.DNI_Duenio);
	
	_flushall();
	printf("\nDomicilio: ");
	gets(masc.Domicilio);
	_flushall();
	printf("\nLocalidad: ");
	gets(masc.Localidad);
		
	
	printf("\nFecha de nacimiento de la mascota(dia,mes,anio): ");
    scanf("%d/%d/%d", &masc.Fecha_de_Nac.dia,&masc.Fecha_de_Nac.mes,&masc.Fecha_de_Nac.anio);
    
    printf("\nPeso de la Mascota: ");
    scanf("%.2f", &masc.Peso);
    
    _flushall();
    printf("\nTelefono del DueÃƒÆ’Ã‚Â±o: ");
    gets(masc.Telefono);
		
	fwrite(&masc, sizeof(Mascota),1,Arch_Masc);
	fclose(Arch_Masc);
}

void Reg_Turns(FILE *Arch_Veter){
	Turnos turn;
	Mascota masc;
	Veterinario vet;
	int mat;
	bool b=false;
	
	printf("Ingresar las Matricula del Veterinario: ");
	scanf("%d", &mat);
	Arch_Turns=fopen("Turnos.dat","a+b");
	if(Arch_Turns==NULL){
		printf("\nEl archivo no existe!\n");
		exit(1);
	}
	
	Arch_Veter=fopen("Veterinarios.dat", "rb");
	if(Arch_Veter==NULL){
		printf("\nEl archivo no existe!\n");
		exit(1);
	}
	fread(&vet, sizeof(Veterinario),1,Arch_Veter);
	
	while(!feof(Arch_Veter) && !b){
		if(mat==vet.Matric){
			//turn.Matricula_de_Veterinario=vet.Matricula;
			printf("\nDni del duenio de la mascota: ");
			scanf("%d", &turn.DNI_Duenio);
			
			printf("/n Fecha del Turno (dia/mes/anio): ");
			scanf("%d/%d/%d", &turn.Fecha.dia, &turn.Fecha.mes, &turn.Fecha.anio);
			turn.Matricula_de_Veterinario=mat;
			turn.borrado=false;
			strcpy(turn.Detalle_de_Atencion, "");
			
			fwrite(&turn, sizeof(Turnos),1,Arch_Turns);
			b=true;
			printf("\nTurno Guardado\n");
			system("pause");
		}
		fread(&vet, sizeof(Veterinario),1,Arch_Veter);
	}
	if(b==false){
		printf("Matricula Ingresada NO valida");
	}
	fclose(Arch_Veter);
	fclose(Arch_Turns);
	
}

void listVetFecha(FILE *Arch_Veter){
	int d,m,a,mat;
	Turnos tur;
	Veterinario vet;
	fecha fec;
	
	
	printf("Ingresar dia de atencion que desea buscar: ");
	scanf("%d", &d);
	printf("Ingresar  mes de atencion que desea buscar: ");
	scanf("%d", &m);
	printf("Ingresar Anio de atencion que desea buscar: ");
	scanf("%d", &a);
	
	printf("\nIngresar Matricula del Veterinario que desea buscar: ");
	scanf("%d", &mat);
	
	Arch_Turns=fopen("Turnos.dat", "r+b");
	Arch_Veter=fopen("Veterinarios.dat", "r+b");
	
	
	
	while(!feof(Arch_Veter)){
		if(mat==vet.Matric){
			while(!feof(Arch_Turns)){
				if (d==tur.Fecha.dia){
					while(!feof(Arch_Turns)){
						if (m==tur.Fecha.mes){
							while(!feof(Arch_Turns)){
								if (a==tur.Fecha.anio){
									printf("\nMatricula del Veterinario a cargo: ");
									scanf("%d",&vet.Matric);
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
