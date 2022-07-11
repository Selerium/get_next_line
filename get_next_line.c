/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:44:19 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/11 22:38:36 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

void	*ft_calloc(size_t num, size_t size)
{
	char	*ns;
	size_t	i;

	if (size != 0 && num > (SIZE_T_MAX / size))
		return (NULL);
	ns = (char *) malloc (num * size);
	if (!ns)
		return (NULL);
	i = 0;
	while (i < (num * size))
	{
		ns[i] = 0;
		i++;
	}
	return (ns);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;

	buf = (char *) ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (read(fd, &buf[i], 1) < 0)
			return (NULL);
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			buf[i + 1] = '\0';
			break ;
		}
		i++;
	}
	if (buf[i - 1] != '\n')
	{
		buf[i] = '\n';
		buf[i + 1] = '\0';
	}
	return (buf);
}
