/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:39:15 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/19 02:30:47 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	char	*word;

	i = 0;
	fd = open("txt/urmom.txt", O_RDONLY);
	fd2 = open("txt/test.txt", O_CREAT | O_WRONLY, 0666);
	word = get_next_line(-1);
	while (word != NULL)
	// {
		printf("test result: |-%s-| %d\n", word, BUFFER_SIZE);
		write(fd2, word, ft_strlen(word));
		// free (word);
		// word = get_next_line(fd);
	// }
	free (word);
	close(fd);
	close(fd2);
}
