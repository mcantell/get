#include "get_next_line.h"

int main()
{


	int o = open("gnlTester/files/empty", O_RDWR);
	char *linea = get_next_line(o);
	while (linea != NULL)
	{
		printf("%s", linea);
		free(linea);
		linea = get_next_line(o);
	}
	free(linea);
    return (0);
}