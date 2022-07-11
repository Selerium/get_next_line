#include"get_next_line.h"
#include<fcntl.h>
#include<string.h>
#include<stdio.h>

int	main()
{
	int	fd;
	int	i;

	i = 0;
	fd = open("urmom.txt", O_RDONLY);
	while (i++ < 15)
		printf("we found: %s", get_next_line(fd));
}
