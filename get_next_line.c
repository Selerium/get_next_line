/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:47:37 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/14 23:38:19 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
//#include "main.c"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1)
		return (s2);
	j = (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (j == 0)
		return (NULL);
	newstr = (char *) malloc (j * sizeof(char));
	if (!newstr)
		return (NULL);
	i = -1;
	while (++i >= 0 && s1[i])
		newstr[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

int	ft_hasnextline(char *check)
{
	int	i;

	i = 0;
	while (check[i] != '\0')
	{
		if (check[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_splithold(char *hold)
{
	int		i;
	char	*newstr;

	newstr = (char *) ft_calloc (ft_strlen(hold), sizeof(char));
	i = 0;
	while (hold[i] != '\n' && hold[i] != 0)
	{
		newstr[i] = hold[i];
		i++;
	}
	newstr[i] = '\n';
	i = ft_strlen(newstr);
	while (hold[i] != '\0')
	{
		hold[i - ft_strlen(newstr)] = hold[i];
		i++;
	}
	hold[i - ft_strlen(newstr)] = '\0';
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buf;
	int			i;

	i = 0;
	if (!hold)
		hold = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	printf("initial hold value: |-%s-|\n", hold);
	buf = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	while (ft_hasnextline(hold) == 0 && i != -1)
	{
		if (read(fd, buf, BUFFER_SIZE) > 0)
			hold = ft_join (hold, buf);
		else
			i = -1;
		printf("\nBuffer: %d\n >%s<\n", i, buf);
		printf("Hold: %d\n >%s<\n", i, hold);
	}
	free (buf);
	if (i == -1)
		return (NULL);
	buf = ft_splithold(hold);
	printf("\nfinal hold value: |-%s-|\n", hold);
	return (buf);
}
