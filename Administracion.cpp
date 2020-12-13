#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"

//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;

//Funciones Utilizadas
void reg_veter(FILE *Arch_Veter);
void Usuario_Valid(FILE *Arch_Usua);  //Contine la Carga y las coniciones
void Usuario_Unic(FILE *Arch_Usua);  // Compara el usuario que esta en la cargado en el archivo con un nuevo Usuario a Ingresar
void Cont_Valid(FILE *Arch_Usua);
bool Cont_Valid(cadena Contra);
bool validarConsecutivasPass(cadena Contra);
void aten_vet();

main(){
	
	int Opc;
	do{
		 printf("\t-----------------------------------------------\n");
         printf("\t|      **Modulo de Administracion**           |\n");
         printf("\t| 1-> Registrar Veterinario                   |\n");
         printf("\t| 2-> Registrar Usuario Asistente             |\n");
         printf("\t| 3-> Atencion por Veterinaria                |\n");
         printf("\t| 4-> Ranking de Veterinario por Atencion     |\n");
         printf("\t| 5-> Cerrar Aplicacion                       |\n");
         printf("\t-----------------------------------------------\n");
   
   
   printf("\nIngresar Opcion: ");
   scanf("%d", &Opc);
   
   switch (Opc){
   	case 1: reg_veter(Arch_Veter);  //Crear Usuarios para el Modul. de Consultorio
		   break;
   	case 2: Usuario_Valid(Arch_Usua);  //Crear Usuarios para Modul. Asistente
		   break;
   	case 3:
		   break;
   	case 4:
		   break;
   	
   }
   
	}while(Opc!=5);
	
}

void reg_veter(FILE *Arch_Veter){
	Veterinario vet;
	
	
	Arch_Veter=fopen("Veterinarios.dat", "a+b");   //Apertura del Arch_Veter
	
	_flushall();
	printf("Apellido y nombre del veterinario: ");
	gets(vet.ApellidoyNombre);
	printf("DNI del Veterinario: ");
	scanf("%d",&vet.DNI);
        printf("\nMatricula del Veterinario: ");
        scanf("%f", &vet.Matricula);
        _flushall();
        printf("Telefono: ");
        gets(vet.Telefono);
		
	fwrite(&vet, sizeof(Veterinario),1,Arch_Veter);
	fclose(Arch_Veter);
}

void Usuario_Valid(FILE *Arch_Usua){   //Validacion el Usuario
	Usuarios Usuari;
	int Long, Mays = 0, Cant_Nro = 0; //importante inicializar los contadores
	bool bandera;
	
	Arch_Usua=fopen("Usuario.dat","a+b");
	do{
	printf("\nRegistrar usuario: ");
	_flushall();
	gets(Usuari.usuario);
	
	Long= strlen(Usuari.usuario);
	
	if(Long>5 && Long<11 && Usuari.usuario[0]>='a' && Usuari.usuario[0]<='z'){
		for(int i=0; i<strlen(Usuari.usuario); i++){
			if(Usuari.usuario[i]>='A' && Usuari.usuario[i]<='Z') Mays++;
			else if(Usuari.usuario[i]>='0' && Usuari.usuario[i]<='9') Cant_Nro++;						
		}		
		if(Mays >= 2 && Cant_Nro<=3){
			bandera= true;
			printf("\nUsuario Valido\n");	
			fwrite(&Usuari, sizeof(Usuarios), 1,Arch_Usua);  //Guardado de Usuarios Valido, para el modulo del Asistente
		}
		//Arch_Usua()
		
	
	}

	if(bandera==false){
		printf("\nEl usuario no cumple algunas de las condiciones\n");
		printf("\nPOR FAVOR VUELVA A INTENTARLO..\n\n");
	}
}while(bandera==false); 
fclose(Arch_Usua);  //Cierre del del Arcj_Usua
	
	//FALTA HACER LA COMPARACION QUE SEA UNICO
}

void Usuario_Unic(FILE *Arch_Usua){
	Usuarios u;
	Usuarios Usuario2;  //Nuevo usuario Ingresado
	
	Arch_Usua=fopen("Usuarios.dat","rb");  //Archivo abierto para lectura
/*	printf("\nIngresar usuario: ");
	_flushall();
	gets(Usuario2.usuario);   //Usuario Nuevo, cargado ya
	*/
	rewind(Arch_Usua);
	fread(&u, sizeof(Usuarios), 1,Arch_Usua);
	while(!feof(Arch_Usua)){
		if(strcmp(Usuario2.usuario,u.usuario)==0){
			printf("\nUsuario ya existente");
		}
		else{
			printf("\nUsuario Valido");
			fwrite(&Usuario2, sizeof(Usuarios), 1,Arch_Usua);
		}
	}
	
	fclose(Arch_Usua);
	
}

bool Contr_Valid(cadena Contra){  //Validacion de la Contraseña
	
	int may = 0, min = 0, num = 0, otros = 0, numcons = 0;
	
	for(int i=0; i<strlen(Contra); i++){
		if (Contra[i] >='A' && Contra[i] <='Z'){
			may++;
			numcons = 0;		
		} 
		else if (Contra[i] >='a' && Contra[i] <='z'){
				 min++;
				 numcons = 0;
			 }
			 else if (Contra[i] >= '0' && Contra[i] <='9'){
			 	num++;
				numcons++;	
			    }
			 	else otros++;
		if (numcons == 4) break;
	}
	
	return may>=1 && 
		   min>=1 && 
		   num>=1 && 
		   otros==0 && 
	       strlen(Contra)>=6 && 
		   strlen(Contra)<=32 && 
		   numcons<=3 && 
		   validarConsecutivasPass(Contra); //Guardamos la contraseña en esta funcion, para luego comparar las consecutivas
}
bool validarConsecutivasPass(cadena Contra){  //Tiene todas las Validaciones para la o las contraseñas
	int letrasCons = 1;
	cadena Contr2;   //Creamos una nueva cadena para la contraseña
	strcpy(Contr2, Contra);
	strlwr(Contr2);  //Convierte la cadena de Mayusc a Minusc.
	//aBuel123
	for(int i=0; i<strlen(Contr2); i++){
		if (Contr2[i] >='a' && Contr2[i] <='z'){
			if(i>0 && Contr2[i-1]>'9' && Contra[i]==Contr2[i-1]+1) letrasCons++;
			//else letrasCons = 0;			
		}
		
		if (letrasCons == 2) break;
	}	
	return letrasCons < 2;
}
	
void aten_vet(*FILE Veterinarios){
	char a;
	int b=0;
	Turnos tur;
	int mat;
	
	printf("\n                         °°ATENCION POR VETERINARIA°°");
	printf("****************************************************************************************")
	
	do{
		printf("\nIngrese Matricula del Veterinario:");
	    scanf("%d",&mat)
		fread(&a, sizeof(Turnos),1,Veterinarios);
		while(!feof(Veterinarios)){
			if(mat==tur.Matricula_de_Veterinario){
				printf("\n\nMatricula del Veterinario: %d", tur.Matricula_de_Veterinario);
				printf("\nDNI del duenio: %d", tur.DNI_Duenio);
				printf("\nDetalles de la Atencion: %s ",tur.Detalle_de_Atencion);
				b=1;
			}
			fread(&a, sizeof(Turnos),1,Veterinarios);
		}
	}while(b==0);
}
bool crearRank(){
	FILE *veterinarios = fopen("veterinarios.dat");
	Veterinario lectura;
	int matriculas[100];
	int cantidades [100];
	c=0
	
	fread(&lectura,sizeof(veterinario),1,veterinarios);
	while(!feof(veterinarios)){
		matriculas[c] =lectura.Matricula;
		cantidades[c] =aten_vet(turnos,lectura,matricula);
		fread (&lectura, sizeof (veterinario), 1,veterinarios);
	}
	
	
	burbuja()
	
	
	
	
}


