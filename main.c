#include <stdio.h>

typedef struct 
{
	char letra;
	int cantidad;
}frecuencia;


int main(int argc, char **argv)
{
	char * cadena;
	char * arreglo;
	int * cantidad;
	int i= 0;
	int j= 0;
	int booleano, k;
	int tam = 0;
	cadena = (char *) malloc(25 * sizeof(char));
	arreglo = (char *)malloc(25 * sizeof(char)); 
	cantidad = (int *)malloc(25 * sizeof(int));
	
	printf("Escribe la cadena que gustes\n");
	
	scanf("%[^\n]", cadena);
	
	while(*(cadena+i) != '\0')
	{
		booleano = 0;
		while(*(arreglo+j) != '\0')
		{
			if(*(cadena+i) == *(arreglo+j))
			{
				booleano = 1;
				k = j;
			}
			j++;
		}
		if(booleano == 1)
		{
			*(arreglo+tam) = *(cadena+i);
			*(cantidad+tam) +=1;
			tam++;
		}
		else
		{
			*(cantidad+k) += 1;
		}
		i++;
	}
	printf("%s", cadena);
	
	free(cadena);
	free(arreglo);
	return 0;
}
