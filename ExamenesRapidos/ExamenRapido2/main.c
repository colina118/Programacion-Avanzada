#include <stdio.h>
#include <stdlib.h>

typedef void (*t_iterate)(void * size);
typedef int (*t_position)(void * );
typedef void (*t_siguiente)();
//typedef void (*t_rIterator)(void * size);

void iterate(t_iterate, void *);
void forward(void * vector, t_position begin, t_position end, t_position next, void * final);
void reverse(void* vector, t_position begin, t_position end, t_position prev);
void bidirectional(void* vector, t_position begin, t_position end, t_position next, t_position prev);

void intBegin(void*, void* );
void intEnd(void* );
void intNext(void* );

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

void forward(void * vector, t_position begin, t_position end, t_position next, void * final)
{
	void * principio = (*begin)(vector);
	void * fin = (*end)(final);
	void * sig = next;
	while(principio != fin)
	{
		printf(principio);
		principio += sig;
	}
	
}

void reverse(void* vector, t_position begin, t_position end, t_position prev)
{
	void * principio = (*begin)(vector);
	void * fin = (*end)(final);
	void * ant = prev;
	while(fin != principio)
	{
		printf(fin);
		principio -= ant;
	}
}

int intBegin(void * pa)
{
	int * a = (int *)pa;
	return a;
}

int intEnd(void * pa)
{
	int * a = (int *)pa;
	return a;
}

int intNext(void * pa)
{
	return sizeof(int);
}