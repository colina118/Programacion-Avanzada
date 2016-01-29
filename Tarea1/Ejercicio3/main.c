#include <stdio.h>
#include <string.h>

typedef struct 
{
	int edad;
	char nombre[12];
	char apellido[20];
}persona;



int main(int argc, char **argv)
{
	persona prueba;
	char opcion;
	int cont = 0;
	int i;
	int suma;
	int prom;
	char name[12];
	char lastName[20];
	int age;
	printf("hello world\n");
	persona	*arreglo = (persona *)malloc(cont * sizeof(persona));
	
	strcpy(prueba.apellido, "de la Colina");
	strcpy(prueba.nombre, "Miguel");
	//prueba.edad = 21;
	//arreglo[0] = prueba;
	//printf(arreglo[0].nombre);
	
	while(opcion != '7')
	{
		printf("1. Agregar persona \n 2. Calcular edad promedio \n 3. Persona mas joven \n 4. Persona mas vieja \n 5. Rango de edades \n 6. imprimir personas \n 7. Salir");
		scanf("%c", &opcion);
		switch (opcion)
		{
			case '1':
			printf("entraste al caso 1\n");
			cont++;
			realloc(arreglo, cont * sizeof(persona));
			printf("Escriba el nombre de la persona\n");
			scanf("%s", &name);
			strcpy(prueba.nombre, name);
			printf("Escriba el apellido de la persona\n");
			scanf("%s", &lastName);
			strcpy(prueba.apellido, lastName);
			printf("Escriba la edad de la persona\n");
			scanf("%d", &age);
			prueba.edad = age;
			
			arreglo[cont] = prueba;
			printf(arreglo[cont].nombre);
			printf("\n");
			break;
			case '2':
			printf("entraste al caso 2\n");
			i = 1;
			suma = 0;
			for(i ; i < cont +1; i++)
			{
				suma += arreglo[i].edad;
				prom = suma / cont;
			}
			printf("El promedio de edad es:\n");
			printf("%d", prom);
			printf("\n");
			break;
			case '3':
			printf("entraste al caso 3\n");
			i = 1;
			int min = 10000;
			for(i; i < cont + 1; i++)
			{
				if(arreglo[i].edad < min)
				{
					min = arreglo[i].edad;
					strcpy(name, arreglo[i].nombre);
					strcpy(lastName, arreglo[i].apellido);
				}
			}
			printf("La persona mas joven es:\n");
			printf("%s", name);
			printf("\n");
			printf("%s", lastName);
			printf("\n");
			printf("%d",min);
			printf("\n");
			break;
			case '4':
			printf("entraste al caso 4\n");
			i = 1;
			int max = 0;
			for(i; i < cont + 1; i++)
			{
				if(arreglo[i].edad > max)
				{
					max = arreglo[i].edad;
					strcpy(name, arreglo[i].nombre);
					strcpy(lastName, arreglo[i].apellido);
				}
			}
			printf("La persona mas joven es:\n");
			printf("%s", name);
			printf("\n");
			printf("%s", lastName);
			printf("\n");
			printf("%d",max);
			printf("\n");
			break;
			case '5':
			printf("entraste al caso 5\n");
			break;
			case '6':
			printf("Las personas que estan registradas son\n");
			i = 1;
			for( i; i < cont +1; i++)
			{
				printf("%d", arreglo[i].edad);
				printf("\n");
				printf(arreglo[i].apellido);
				printf("\n");
				printf(arreglo[i].nombre);
				printf("\n");
			}
			break;
			case '7':
			printf("adios");
			break;
			case '\n':
			break;
			default:
			printf("no existe esa opcion");
			break;
		}
	}
	free(arreglo);
	return 0;
}
