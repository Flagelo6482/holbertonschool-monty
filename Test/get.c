#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buff;
	size_t size = 32;
	size_t car;

	buff = malloc(sizeof(char) * size);

	if (buff == NULL)
		return(1);

	printf("Escriba algo: ");
	car = getline(&buff, &size, stdin);
	printf("%zu caracteres se leyeron\n", car);
	printf("Escribio: %s", buff);

	return(0);
}
