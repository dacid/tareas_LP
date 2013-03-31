#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/evento.h"

void check_param(char * op, int param, int argc)
{
	if(param+2 != argc)
	{
		printf("error: el parametro \"%s\" necesita %d argumento%c\n", op, param, param != 1 ? 's' : ' ');
		exit(0);
	}
}

void do_the_shit(evento * ptr_evento, ptr_funcion funcion_base)
{
	funcion_base(ptr_evento);
}

int main(int argc, char * argv[])
{
	// si no hay parametros
	if(argc == 1)
	{
		printf("error: no se especificaron parametros\n");
		exit(0);
	}

	// calcula el id actual dentro del archivo
	int current_id;
	FILE * file = fopen("eventos.dat", "ab");
	if(file == NULL) printf("error: no se pufo abrir el archivo\n");
	else
	{
		current_id = ftell(file) ? ftell(file)/sizeof(evento) : 0 ;
		fclose(file); 
	}

	if(!strcmp(argv[1], "new"))
	{
		check_param("new", 2, argc);

		evento * n_evento = (evento *)malloc(sizeof(evento*));
		n_evento->id = ++current_id;
		strcpy(n_evento->titl, argv[2]);		
		strcpy(n_evento->desc, argv[3]);
		n_evento->estado = 0;

		// Encontrar la forma de reemplazar &nuevo_evento por funcion_base[0]
		do_the_shit(n_evento, &nuevo_evento);
		free(n_evento);
	}
	else if(!strcmp(argv[1], "get"))
	{
		check_param("get", 1, argc);
	}
	else if(!strcmp(argv[1], "delete"))
	{
		check_param("delete", 1, argc);
	}
	else if(!strcmp(argv[1], "update"))
	{

	}
	else if(!strcmp(argv[1], "list"))
	{
		check_param("list", 0, argc);

	}
	else if(!strcmp(argv[1], "clear"))
	{
		check_param("clear", 0, argc);

	}
	else if(!strcmp(argv[1], "do"))
	{
		check_param("do", 1, argc);
	}
	else
	{
		printf("error: el parametro no es valido\n");
		exit(0);
	}
	
	exit(1);
}
