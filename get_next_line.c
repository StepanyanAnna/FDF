/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:46:08 by annstepa          #+#    #+#             */
/*   Updated: 2022/11/03 20:46:14 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin_gnl(char *rem_line, char c)
{
	int		i;
	char	*str_join;

	str_join = malloc(sizeof(char) * (ft_strlen(rem_line) + 2));
	if (!str_join)
		return (NULL);
	i = 0;
	while (rem_line && rem_line[i])
	{
		str_join[i] = rem_line[i];
		i++;
	}
	str_join[i] = c;
	str_join[i + 1] = '\0';
	free(rem_line);
	return (str_join);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		rd;

	line = NULL;
	while (1)
	{
		rd = read(fd, &c, 1);
		if (rd < 0)
		{
			free(line);
			return (NULL);
		}
		if (rd == 0)
			return (line);
		line = ft_strjoin_gnl(line, c);
		if (c == '\n')
			return (line);
	}
	printf("%s\n", line);
	return (line);
}
