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
void Usuario_Valid(FILE *Arch_Usua, cadena &Contra);  //Contine la Carga y las coniciones
void Usuario_Unic(FILE *Arch_Usua);  // Compara el usuario que esta en la cargado en el archivo con un nuevo Usuario a Ingresar
void password(FILE *usuario, cadena &password);
void Ranking(FILE *Arch_Veter);
void aten_vet(FILE *Arch_Veter);

main(){
	
	int Opc;
	cadena Clv;
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
   	case 2: Usuario_Valid(Arch_Usua,Clv);  //Crear Usuarios para Modul. Asistente
		   break;
   	case 3: aten_vet(Arch_Veter);
		   break;
   	case 4: Ranking(Arch_Veter);
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
        scanf("%d", &vet.Matricula);
        printf("\nIngresar Contraseña: ");
        scanf("%s",&vet.contras);
        _flushall();
        printf("Telefono: ");
        gets(vet.Telefono);
		
	fwrite(&vet, sizeof(Veterinario),1,Arch_Veter);
	fclose(Arch_Veter);
}

void Usuario_Valid(FILE *Arch_Usua, cadena &Contra){   //Validacion el Usuario

	Usuarios Usuari;
	int Long, Mays = 0, Cant_Nro = 0; //importante inicializar los contadores
	bool bandera;
	
	
	//aux=Contr_Valid(clave);
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
		    //printf("\nValido");
		    if(bandera==true){
		    	password(Arch_Usua,Contra);
			}
			fwrite(&Usuari, sizeof(Usuarios), 1,Arch_Usua);  //Guardado de Usuarios Valido, para el modulo del Asistente
		}
		
	}

	if(bandera==false){
		printf("\nEl usuario no cumple algunas de las condiciones\n");
		printf("\nPOR FAVOR VUELVA A INTENTARLO..\n\n");
	}
}while(bandera==false); 
fclose(Arch_Usua);  //Cierre del del Arcj_Usua
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
//Validacion de la ContraseÃ±a
void password(FILE *usuario, cadena &password){
	int Mayus,Minus,Num,Signos,NumConsecutivos,letrasCons;
	bool Band = false;
	cadena passAux;
	
	do{
		Mayus = 0, Minus = 0, Num = 0, Signos = 0, NumConsecutivos = 0, letrasCons = 1;
		
		printf("\nIngrese su contrasenia: ");
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


void Ranking(FILE *Arch_Veter){
	 Arch_Veter=fopen("Veterinarios.dat","rb");
	 Veterinario Lect;
	 int Matricula[100];
	 int Cantidades[100];
	 int c=0;
	 
	 fread(&Lect, sizeof(Veterinario), 1,Arch_Veter);
	 while(!feof(Arch_Veter)){
	 	Matricula[c]=Lect.Matricula;
	 	//Cantidades[c]=aten_vet(Arch_Veter,Lect.Matricula);
	 }
}
	
void aten_vet(FILE *Arch_Veter){
	char a;
	int b=0;
	Turnos tur;
	int mat;
	int mes, anio;
	
	printf("\n                         Â°Â°ATENCION POR VETERINARIAÂ°Â°");
	printf("****************************************************************************************");
	
	do{
		printf("\nIngrese Matricula del Veterinario:");
	    scanf("%d",&mat);
	    printf("\nIngrese mes y anio:");
	    scanf("%d",&mes,&anio);
	    
		fread(&a, sizeof(Turnos),1,Arch_Veter);
		while(!feof(Arch_Veter)){
			if(mat==tur.Matricula_de_Veterinario && mes==tur.Fecha.mes && anio==tur.Fecha.anio ){
				printf("\n\nMatricula del Veterinario: %d", tur.Matricula_de_Veterinario);
				printf("\nDNI del duenio: %d", tur.DNI_Duenio);
				printf("\nDetalles de la Atencion: %s ",tur.Detalle_de_Atencion);
				b=1;
			}
			fread(&a, sizeof(Turnos), 1,Arch_Veter);
		}
	}while(b==0);
}
