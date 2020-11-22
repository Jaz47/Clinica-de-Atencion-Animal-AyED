#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPrincipal();
int Menu_Consultorio();
int Modul_Asist();
int Modul_Admin();

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
 
int Menu_Consultorio(){
  printf("\t------------------------------------------------------\n");
  printf("\t|      **Modulo Consultorio Veterinario**            |\n");
  printf("\t| 1-> Iniciar Sesion                                 |\n");
  printf("\t| 2-> Visualizar Lista de Espera de Turnos (Informes)|\n");
  printf("\t| 3-> Registrar Evolucion de la Mascota              |\n")
  printf("\t| 4-> Cerrar Aplicacion                              |\n");
  printf("\t------------------------------------------------------\n");
   
   int Opc;
   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   return Opc;
 }

int Modul_Asist(){
  printf("\t-----------------------------------------------\n");
  printf("\t|      **Modulo de Asistente**                |\n");
  printf("\t| 1-> Iniciar Sesion                          |\n");
  printf("\t| 2-> Registrar Mascota                       |\n");
  printf("\t| 3-> Registrar Turnos                        |\n")
  printf("\t| 4-> Listar Atencion pot Veterinario y Fecha |\n");
  printf("\t| 5-> Cerrar Aplicacion                       |\n");
  printf("\t-----------------------------------------------\n");
   
   int Opc;
   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   return Opc;
 }

int Modul_Admin(){
  printf("\t-----------------------------------------------\n");
  printf("\t|      **Modulo de Administracion**           |\n");
  printf("\t| 1-> Registrar Veterinario                   |\n");
  printf("\t| 2-> Registrar Usuario Asistente             |\n");
  printf("\t| 3-> Atencion por Veterinaria                |\n")
  printf("\t| 4-> Ranking de Veterinario por Atencion     |\n");
  printf("\t| 5-> Cerrar Aplicacion                       |\n");
  printf("\t-----------------------------------------------\n");
   
   int Opc;
   printf("\nIngresar Opcion: ");
   scanf("%d", & Opc);
   return Opc;
 }
