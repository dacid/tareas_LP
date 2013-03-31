#include <stdlib.h>
#include <stdio.h>
#include "include/evento.h"

ptr_funcion funciones_base[7];

FILE * file;

void nuevo_evento(evento * ptr_evento)
{
	file = fopen("eventos.dat", "ab");
	if(file == NULL) printf("error: no se pudo abrir el archivo\n");
	else
	{
		fwrite(ptr_evento, sizeof(evento), 1, file);
		fclose(file);
		printf("Evento #%d creado exitosamente!\n", ptr_evento->id);
	}
}

void mostrar_evento(evento * ptr_evento)
{

}

void eliminar_evento(evento * ptr_evento)
{

}

void modificar_evento(evento * ptr_evento)
{

}

void concretar_evento(evento * ptr_evento)
{

}

void listar_eventos()
{

}

void vaciar_eventos()
{

}

