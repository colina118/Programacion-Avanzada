#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int *edad;
	char *nombre;
	char *apellido;
	char *telefono;
	int camita;
}persona;

typedef struct
{
	int numero;
	int ocupada;
	persona ocupante;
}cama;

void agregarPaciente(persona **p, int *num);

int main(int argc, char **argv)
{
	int opcion = -1;
	int numCamas = 2;
	int numAsignada = 0;
	int numPacientes = 0;
	int pacPorCama;
	cama * camas =(cama *)malloc(numCamas*sizeof(cama));
	persona * paciente;
	
	while(opcion != 0)
	{
		printf("1.Incorporar Paciente\n2.Paciente por Cama\n3.Dar de alta Paciente\n4.Listar Paciente\n5.Camas Disponibles\n0.Salir\n");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
			{
				if(numPacientes == 0)
				{
					numPacientes++;
					paciente = (persona *)malloc(numPacientes * sizeof(persona));
					agregarPaciente(&paciente, &numPacientes);
					printf("Introduzca el telefono del paciente\n");
					scanf("\n%[^\n]", ((paciente) + numPacientes)->telefono);
					printf("Introduzca la edad del paciente\n");
					scanf("\n%[^\n]", ((paciente) + numPacientes)->edad);
					printf("Introduzca el nombre del paciente\n");
					scanf("\n%[^\n]", ((paciente) + numPacientes)->nombre);
					printf("Introduzca el apellido del paciente\n");
					scanf("\n%[^\n]", ((paciente) + numPacientes)->apellido);
					((paciente) + numPacientes)->camita = numAsignada + 1;
					((camas)+numAsignada)->ocupante = *(paciente + numPacientes);
					((camas)+numAsignada)->ocupada = 1;
					numAsignada++;
					
				}
				else
				{
					numPacientes++;
					if(numPacientes+1 > numCamas)
					{
						numCamas += 5;
						realloc(camas, numCamas * sizeof(cama));
						realloc(paciente, numPacientes * sizeof(persona));
						agregarPaciente(&paciente, &numPacientes);
						printf("Introduzca el telefono del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->telefono);
						printf("Introduzca la edad del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->edad);
						printf("Introduzca el nombre del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->nombre);
						printf("Introduzca el apellido del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->apellido);
						((paciente) + numPacientes)->camita = numAsignada + 1;
						((camas)+numAsignada)->ocupante = *(paciente + numPacientes);
						((camas)+numAsignada)->ocupada = 1;
						numAsignada++;
					}
					else
					{
						realloc(paciente, numPacientes * sizeof(persona));
						agregarPaciente(&paciente, &numPacientes);
						printf("Introduzca el telefono del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->telefono);
						printf("Introduzca la edad del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->edad);
						printf("Introduzca el nombre del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->nombre);
						printf("Introduzca el apellido del paciente\n");
						scanf("\n%[^\n]", ((paciente) + numPacientes)->apellido);
						((paciente) + numPacientes)->camita = numAsignada + 1;
						((camas)+numAsignada)->ocupante = *(paciente + numPacientes);
						((camas)+numAsignada)->ocupada = 1;
						numAsignada++;
					}
				}
				
				break;
			}
			case 2:
			{
				printf("Escriba el numero de la cama de la cual quiere ver al paciente\n");
				scanf("%d", &pacPorCama);
				printf("Aqui no hay pedo\n");
				if(((camas)+pacPorCama)->ocupada != 0)
				{
					
					printf(((camas)+pacPorCama)->ocupante.nombre);
					printf("\n");
					printf(((camas)+pacPorCama)->ocupante.apellido);
					printf("\n");
					printf(((camas)+numAsignada)->ocupante.telefono);
					printf("\n");
					printf(((camas)+pacPorCama)->ocupante.edad);
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
				break;
			}
			case 5:
			{
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
	printf(((paciente) + numPacientes)->camita);
	printf(((camas)+numAsignada)->ocupante.nombre);
	return 0;
}


void agregarPaciente(persona **p, int *num)
{
	(*p+(*num))->telefono =(char *)malloc(15*sizeof(char));
	(*p+(*num))->nombre =(char *)malloc(30*sizeof(char));
	(*p+(*num))->apellido =(char *)malloc(30*sizeof(char));
	(*p+(*num))->edad =(int *)malloc(sizeof(int));
	//(*p+(*num))->camita =(int *)malloc(sizeof(int));
	
}