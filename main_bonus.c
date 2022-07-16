#include"get_next_line.h"
#include<fcntl.h>

int	main()
{
	int	fd, fd1, fd2;
	int	i;
	char	*word;

	i = 0;
	fd = open("txt/urmom.txt", O_RDONLY);
	fd1 = open("txt/baka.txt", O_RDONLY);
	fd2 = open("txt/testing.txt", O_CREAT | O_WRONLY, 0666);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd1);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd1);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd1);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd1);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd1);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd1);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);
	word = get_next_line(fd);
	printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
	write(fd2, word, ft_strlen(word));
	free (word);

	close(fd);
	close(fd2);
}
