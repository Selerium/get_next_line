/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:58:42 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/16 19:01:40 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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
			return (1);
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
	newstr[i + 1] = '\0';
	i = ft_strlen(newstr);
	while (hold[i] != '\0')
	{
		hold[i - ft_strlen(newstr)] = hold[i];
		i++;
	}
	hold[i - ft_strlen(newstr)] = '\0';
	return (newstr);
}
