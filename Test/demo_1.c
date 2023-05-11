#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *archivo;

	char nombreArchivo[] = "file.txt";

	archivo = fopen(nombreArchivo, "w");

	if(archivo != NULL)
	{
		printf("Archivo creado y abierto con exito.\n");
		fclose(archivo);
	}
	else
	{
		printf("Error al abrir el archivo.\n");
	}
	return(0);
}
