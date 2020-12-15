# Clinica-de-Atencion-Animal-AyED
#include<string>
#include<stdio.h>
//Archivos utilizados
FILE *Arch_Veter;
FILE *Arch_Usua;
FILE *Arch_Turns;
FILE *Arch_Masc;


int main(){
	
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
