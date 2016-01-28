#include <stdio.h>
#include <stdlib.h>

typedef void (*t_iterate)(void * size);
typedef void (*t_position)(void *);
//typedef void (*t_rIterator)(void * size);

void iterate(t_iterate, void *);
void forward(void * vector, t_position begin, t_position end, t_position next);
void reverse(void* vector, t_position begin, t_position end, t_position prev);
void bidirectional(void* vector, t_position begin, t_position end, t_position next, t_position prev);

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

void forward(void * vector, t_position begin, t_position end, t_position next);
{
	void * principio = begin;
	void * fin = end;
	
}