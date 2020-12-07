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

void reg_mascota();
void reg_turnos();
void listVetFecha();

main(){
	int Opc;
	
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
		   
   	case 2: reg_mascota(); 
   			
   	break;
   	
        case 3: reg_turnos();
   		 
   	break;
   		
   	case 4:
        
	break;
   }
	}while (Opc != 5);
}


void reg_mascota(){
	Mascota masc;
	
	m=fopen("Mascotas.dat", "a+b");
	
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
		
	fwrite(&masc, sizeof(Mascota),1,m);
	fclose(m);
}

void reg_turnos(){
	Turnos turn;
	Mascota masc;
	Veterinario vet;
	int mat;
	bool b=false;
	
	printf("Ingresar las Matricula del Veterinario: ");
	scanf("%d", &mat);
	t=fopen("Turnos.dat","a+b");
	
	v=fopen("Veterinarios.dat", "rb");
	fread(&vet, sizeof(Veterinario),1,v);
	
	while(!feof(v)){
		if(mat==vet.Matricula){
			turn.Matricula_de_Veterinario=vet.Matricula;
			printf("\nDni del duenio de la mascota: ");
			scanf("%d", &turn.DNI_Duenio);
			
			printf("/n Fecha del Turno (dia/mes/anio): ");
			scanf("%d/%d%d", &turn.Fecha.dia,turn.Fecha.mes,turn.Fecha.anio);
			
			_flushall();
			printf("\nDetalle de Atencion: ");
			gets(turn.Detalle_de_Atencion);
			
			fwrite(&turn, sizeof(Turnos),1,t);
			b=true;
		}
		fread(&vet, sizeof(Veterinario),1,v);
	}
	if(b==false){
		printf("Matricula Ingresada NO valida");
	}
	
	fclose(t);
	
}

void listVetFecha(){
	int d,m,a
	Turnos tur;
	Veterinario vet;
	Mascota masc;
	fecha fec;
	cadena apeynom;
	
	printf("Ingresar fecha de atencion que desea buscar (dia/mes/año): ");
	scanf("%d/%d/%d", &d,&m,&a);
	_flushall();
	printf("\nIngresar apellido y nombre del veterinario que desea buscar: ");
	gets(apeynom);
	
	t=fopen("Turnos.dat", "r+b");
	v=fopen("Veterinarios.dat", "r+b");
	m=fopen("Mascotas.dat", "r+b");
	
	fread(&vet,sizeof(Veterinario),1,v);
	fread(&masc,sizeof(Mascota),1,m);
	fread(&tur,sizeof(Turnos),1,t);
}
