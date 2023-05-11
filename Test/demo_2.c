#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *demo = NULL;
	/*char c;

	demo = fopen("file.txt", "r");

	while((c = fgetc(demo)) != EOF)
	{
		printf("%c", c);
	}
	*/
	int display;

	demo = fopen("f.txt", "r");

	if (demo == NULL)
		printf("Error.\n");
	else
	{
		printf("Archivo encontrado!\n");
		exit(EXIT_FAILURE);
	}

	fclose(demo);
	return(0);
}
