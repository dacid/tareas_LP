#include <stdio.h>
#include <string.h>

//#include "evento.h"

void error(char * op, int param)
{
	printf("error: operation \"%s\" needs %d parameter%c\n", op, param, param != 1 ? 's' : ' ');
}

int main(int argc, char * argv[])
{
	// lack of parameters
	if(argc == 1)
	{
		printf("error: no parameter specified\n");
		return 1;
	}

	if(!strcmp(argv[1], "new"))
	{
		if(argc != 4)
		{
			error("new", 2);
			return 1;
		}
	}
	else if(!strcmp(argv[1], "get"))
	{
		if(argc!= 3)
		{
			error("get", 1);
			return 1;
		}
	}
	else if(!strcmp(argv[1], "delete"))
	{
		if(argc!= 3)
		{
			error("delete", 1);
			return 1;
		}
	}
	else if(!strcmp(argv[1], "update"))
	{

	}
	else if(!strcmp(argv[1], "list"))
	{
		if(argc!= 2)
		{
			error("list", 0);
			return 1;
		}

	}
	else if(!strcmp(argv[1], "clear"))
	{
		if(argc!= 2)
		{
			error("clear", 0);
			return 1;
		}

	}
	else if(!strcmp(argv[1], "do"))
	{
		if(argc!= 3)
		{
			error("do", 1);
			return 1;
		}
	}
	else
	{
		printf("error: invalid parameter");
		return 1;
	}
	
	return 0;
}
