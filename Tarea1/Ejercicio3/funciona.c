#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int edad;
	char* nombre;
	char* apellido;
	char* telefono;
	int camita;
}persona;

typedef struct
{
	int numero;
	int ocupada;
	persona* ocupante;
}cama;

void agregarPaciente(cama *pers, int num);
char* consigueString(char* car, int tam);

int main(int argc, char **argv)
{
	int opcion = -1;
	int numCamas = 1;
	int numDisponible = numCamas;
	int i;
	int pacPorCama;
	cama * camas =(cama *)malloc(numCamas*sizeof(cama));
	
	for(i =0; i < numCamas; i++)
	{
		((camas)+i)->numero = i;
		((camas)+i)->ocupada = 1;
		((camas)+i)->ocupante = NULL;
	}
	
	while(opcion != 0)
	{
		printf("1.Incorporar Paciente\n2.Paciente por Cama\n3.Dar de alta Paciente\n4.Listar Paciente\n5.Camas Disponibles\n0.Salir\n");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
			{
				if(numDisponible == 0)
				{
					numCamas += 5;
					numDisponible +=5;
					realloc(camas, numCamas * sizeof(cama));
					for(i = numCamas-5; i < numCamas; i++)
					{
						((camas)+i)->numero = i;
						((camas)+i)->ocupada = 1;
						((camas)+i)->ocupante = NULL;
					}
				}
				for(i = 0; i < numCamas;i++)
				{
					if(((camas)+i)->ocupada == 1)
					{
						agregarPaciente(camas, i);
						
						((camas)+i)->ocupada = 0;
						numDisponible--;
						
						break;
					}
				}
				
			
			break;
			}
			case 2:
			{
				printf("Escriba el numero de la cama de la cual quiere ver al paciente\n");
				scanf("%d", &pacPorCama);
				printf("Aqui no hay pedo\n");
				if(((camas)+pacPorCama)->ocupada != 1)
				{
					
					printf(((camas)+pacPorCama)->ocupante->nombre);
					printf("\n");
					printf(((camas)+pacPorCama)->ocupante->apellido);
					printf("\n");
					printf(((camas)+pacPorCama)->ocupante->telefono);
					printf("\n");
					printf("%d",((camas)+pacPorCama)->ocupante->edad);
					printf("\n");
					
				}
				else
				{
					printf("Esa cama no tiene ningun paciente\n");
				}
				break;
			}
			case 3:
			{
				
				break;
			}
			case 4:
			{
				for(i = 0; i < numCamas; i++)
				{
					if(((camas)+i)->ocupada != 0)
					{
						printf("Paciente numero: ");
						printf("%d", i+1);
						printf("\n");
						printf(((camas)+i)->ocupante->nombre);
						printf("\n");
						printf(((camas)+i)->ocupante->apellido);
						printf("\n");
						printf(((camas)+i)->ocupante->telefono);
						printf("\n");
						printf("%d",((camas)+i)->ocupante->edad);
						printf("\n");
					}
				}
				break;
			}
			case 5:
			{
				for(i = 0; i < numCamas; i ++)
				{
					if(((camas)+i)->ocupada == 0)
					{
						printf("%d", ((camas)+i)->numero);
						printf("\n");
					}
				}
				break;
			}
			case 0:
			{
				printf("Adios gracias por utilizar el sistema\n");
				break;
			}
			default:
			{
				printf("esa opcion no es valida");
				break;
			}
		}
		
	}
	return 0;
}


void agregarPaciente(cama* pers, int num)
{
	cama* p = pers + num;
	printf ("\n");
	p->ocupante = (persona*) malloc(sizeof(persona));

	p->ocupante->nombre =(char *)malloc(30*sizeof(char));
	p->ocupante->apellido =(char *)malloc(30*sizeof(char));
	p->ocupante->telefono =(char *)malloc(30*sizeof(char));
	//(*p+(*num))->camita =(int *)malloc(sizeof(int));
	getchar();
	printf("Introduzca el telefono del paciente: ");
	consigueString(p->ocupante->telefono, 30);
	printf("Introduzca la edad del paciente\n");
	scanf("%d", &p->ocupante->edad);
	getchar();
	printf("Introduzca el nombre del paciente\n");
	consigueString(p->ocupante->nombre, 30);
	printf("Introduzca el apellido del paciente\n");
	consigueString(p->ocupante->apellido, 30);
	return;
}

char* consigueString(char* car, int tam) 
{
	fgets(car, tam, stdin);
	*(car + strcspn(car, "\n")) = 0;
}