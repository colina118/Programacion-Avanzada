#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char * argv[]) {

    int pid;
    int estado;
	int numero;
    
	while (numero !=0)
	{
		printf("Entre un numero: \n");
		scanf("%d", numero);
		
		pid = fork();
    
		if (pid == -1)
		{
			printf("Error al crear el proceso hijo \n");
		}
		else if (pid == 0)
		{
			// Estamos en el hijo
			printf("%d! = %d\n", numero, factorial(numero));
			exit(0)
		}
		else {
			
			
		}
	}

    
    return 0;
}

int factiorial(int n)
{
	int f = 2;
	int i = 3;
	
	if(n == 0 || n == 1)
	{
		return 1;
	}
	for(; i <=n; f*=i, ++i);
	return f;
}