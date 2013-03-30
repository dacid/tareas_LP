#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/evento.h"

void check_param(char * op, int param, int argc)
{

/* check_param
 * op	 : Name of the first parameter, argc[1] = (new | delete | get | ... ) 
 * param : Number of arguments that take the current parameter 
 * argc	 : Actual number of parameters given to the excecutable 
 */

	if(param+2 != argc)
	{
		printf("error: operation \"%s\" needs %d parameter%c\n", op, param, param != 1 ? 's' : ' ');
		exit(0);
	}
}

int main(int argc, char * argv[])
{
	// if lack of parameters
	if(argc == 1)
	{
		printf("error: no parameter specified\n");
		exit(0);
	}

	// calculate the current id in the file
	int current_id;
	FILE * file = fopen("eventos.dat", "ab");
	if(file == NULL) printf("error: could not open the file\n");
	else
	{
		current_id = ftell(file) ? ftell(file)/sizeof(evento) : 0 ;
		fclose(file); 
	}


	if(!strcmp(argv[1], "new"))
	{
		check_param("new", 2, argc);

		evento new_event;
		new_event.id = ++current_id;
		strcpy(new_event.titl, argv[2]);		
		strcpy(new_event.desc, argv[3]);
		new_event.estado = 0;

		file = fopen("eventos.dat", "ab");
		if(file == NULL) printf("error: could not open the file\n");
		else
		{
			fwrite(&new_event, sizeof(evento), 1, file);
			fclose(file);
			printf("Evento #%d creado exitosamente!\n", current_id);
		}
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
		printf("error: invalid parameter");
		exit(0);
	}
	
	exit(1);
}
