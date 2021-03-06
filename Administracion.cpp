#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculos.h"

//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;

//Prototipos Utilizadas
void reg_veter(FILE *Arch_Veter);
void reg_asis(FILE *Arch_Usua);
void Ranking(int mes, int anio);
int aten_vet(int mat, int mes, int anio);

main(){
	int Mes, Anio, matrc;
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
   	case 1: reg_veter(Arch_Veter);
   		break;
   	case 2:reg_asis(Arch_Usua);
   		break;
   	case 3: printf("\nIngrese Matricula del Veterinario: ");
   	        scanf("%d",&matrc);
   	        printf("\nIngrese Mes y Anio: ");
   	        scanf("%d/%d",&Mes, &Anio);
   	        aten_vet(matrc, Mes, Anio);
   		break;
   	case 4: printf("\nIngresar Mes y Anio: ");
   	        scanf("%d/%d",&Mes, &Anio);
   	        Ranking(Mes, Anio);
   	    break;
   }
   
	}while(Opc!=5);
 
}

void reg_asis(FILE *Arch_Usua){
	Usuarios u;
	cadena passAux, userAux;
	Arch_Usua=fopen("Usuarios.dat", "a+b");
	
	
	printf("Apellido y nombre del Asistente: ");
	scanf("%s", &u.ape_y_nomb);
	printf("\n// AVISOO!! PARA CREAR SU USUARIO DEBE CUMPLIR LOS SIG REQUISITOS:\n");
	printf("-Cantidad minima de 6 caracteres y maxima de 10 \n-Pueden ser letras, numeros y/o simbolos del conjunto {+,-,/,*,?,Ã‚Â¿,!,Ã‚Â¡}.");
	printf("\n-Comenzar con una letra minuscula.\n-Tener al menos 2 letras mayusculas.\nTener como maximo 3 digitos\n \n--EJEMPLO: mARtin12\n\n");
	_flushall();
    user(Arch_Usua,userAux);
    strcpy(u.usuario, userAux);
   	printf("\n// AVISOO!! PARA CREAR SU CLAVE DEBE CUMPLIR LOS SIG REQUISITOS:\n");
    printf("-Debera contener al menos una letra mayuscula, una letra minscula y un nmero.\n-No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumÃƒÂ©ricos.\n -DeberÃƒÂ¡ tener entre 6 y 32 caracteres.\n-No debe tener mas de 3 caracteres numericos consecutivos.\n-No debe tener 2 caracteres consecutivos que refieran a letras alfabÃƒÂ©ticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas\n \n--EJEMPLO: Achus32\n");
    password(Arch_Usua,passAux);
	strcpy(u.contras, passAux);	
	fwrite(&u, sizeof(Usuarios),1,Arch_Usua);
	fclose(Arch_Usua);
}

void reg_veter(FILE *Arch_Veter){
	Veterinario vet;
	cadena passAux, userAux;
	Arch_Veter=fopen("Veterinarios.dat", "ab");
	
	
	printf("Apellido y nombre del veterinario: ");
	_flushall();
	gets (vet.ApellidoyNombre);	
	 printf("DNI del Veterinario: ");
	 scanf("%d",&vet.DNI);
	 printf("Telefono: ");
	 _flushall();
	 gets(vet.Telefono);
	
     printf("\nMatricula del Veterinario: ");
     scanf("%d",&vet.Matric);
    
    password(Arch_Veter,passAux);
    printf("%d",vet.Matric);
	strcpy(vet.contr, passAux);	
	fwrite(&vet, sizeof(Veterinario),1,Arch_Veter);
	fclose(Arch_Veter);
	system("pause");
}





void Ranking(int mes, int anio){
	 FILE *Arch_Veter=fopen("Veterinarios.dat","rb");
	 Veterinario Lect;
	 int Matricula[100];
	 int Cantidades[100];
	 int c=0;
	 
	 fread(&Lect, sizeof(Veterinario), 1, Arch_Veter);
	 while(!feof(Arch_Veter)){
	 	Matricula[c]=Lect.Matric;
	 	Cantidades[c]=aten_vet(Lect.Matric, mes, anio);
	 	c++;
	 	fread(&Lect, sizeof(Veterinario), 1, Arch_Veter);
	 }
	 system("cls");
	
	 
	 for(int i=0; i<c; i++){
	 	printf(" -> %d : %d\n", Matricula[i], Cantidades[i]);
	 }
	 system("pause");
	 fclose(Arch_Veter);
}
	
int aten_vet(int mat, int mes, int anio){
	int Cont=0;
	Turnos tur; 
	FILE *Arch_Turns = fopen("Turnos.dat","rb");;
	
	printf("\n                   Â°ATENCION POR VETERINARIAÂ°");
	printf("****************************************************************************************");
	
	    
		fread(&tur, sizeof(Turnos),1,Arch_Turns);
		while(!feof(Arch_Turns)){
			if(mat==tur.Matricula_de_Veterinario && mes==tur.Fecha.mes && anio==tur.Fecha.anio ){
				printf("\n\nMatricula del Veterinario: %d", tur.Matricula_de_Veterinario);
				printf("\nDNI del duenio: %d", tur.DNI_Duenio);
				printf("\nDetalles de la Atencion: %s \n\n",tur.Detalle_de_Atencion);
				Cont++;
		
			}
			fread(&tur, sizeof(Turnos), 1, Arch_Turns);
		}
	fclose(Arch_Turns);
 	return Cont;
}
