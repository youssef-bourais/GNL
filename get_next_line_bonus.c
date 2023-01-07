/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:52:48 by ybourais          #+#    #+#             */
/*   Updated: 2022/12/25 14:51:27 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_index(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == n)
			return (i);
		i++;
	}
	return (-42);
}

char	*ft_read(int fd, char *temp)
{
	char	buff[BUFFER_SIZE + 1];
	int		res;
	int		k;
	int		n;

	res = 0;
	k = 0;
	n = 0;
	while (1)
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		buff[res] = '\0';
		temp = ft_str_join(temp, buff);
		if (ft_index_chrch(temp + n, '\n') == 1 || res < BUFFER_SIZE)
			break ;
		n = k * BUFFER_SIZE;
		k++;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*str;
	char		*tofree;
	int			j;

	if (fd < 0)
		return (NULL);
	j = 0;
	temp[fd] = ft_read(fd, temp[fd]);
	if (temp[fd] == NULL)
		return (NULL);
	j = ft_index(temp[fd], '\n');
	if (j == -42)
		j = ft_len(temp[fd]) - 1;
	if (temp[fd][0] == '\0')
	{
		free(temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	str = ft_sub_str(temp[fd], 0, j + 1);
	tofree = temp[fd];
	temp[fd] = ft_sub_str(temp[fd], j + 1, ft_len(temp[fd]) - j);
	free(tofree);
	return (str);
}
