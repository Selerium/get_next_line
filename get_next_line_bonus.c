/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:47:37 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/19 04:17:54 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	**hold;
	char		*buf;
	int			i;

	i = 0;
	if (!hold)
		hold = (char **) ft_calloc (OPEN_MAX, sizeof(char *));
	if (!hold[fd])
		hold[fd] = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	buf = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	while (ft_hasnextline(hold[fd]) == 0 && i != -1)
	{
		if (read(fd, buf, BUFFER_SIZE) > 0)
			hold[fd] = ft_join (hold[fd], buf);
		else
		{
			free (hold[fd]);
			i = -1;
		}
	}
	free (buf);
	if (i == -1)
		return (NULL);
	buf = ft_splithold(hold[fd]);
	return (buf);
}
