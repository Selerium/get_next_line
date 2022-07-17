/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:47:37 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/17 22:32:16 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_validfd(int fd, int *i)
{
	if (fd > 0 && fd < OPEN_MAX)
		return (1);
	*i = -1;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buf;
	int			i;

	i = 0;
	if (!hold)
		hold = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	buf = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	//write(1, "\ntest\n", 6);
	while (ft_validfd(fd, &i) && ft_hasnextline(hold) == 0 && i == 0)
	{
		if (read(fd, buf, BUFFER_SIZE) > 0)
			hold = ft_join (hold, buf);
		else
			i = 1;
	}
	free (buf);
	if (i == -1)
		return (NULL);
	buf = ft_splithold(hold);
	if (i == 1)
		free (hold);
	return (buf);
}
