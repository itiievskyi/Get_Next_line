/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:02:41 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/16 10:02:44 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd == -1)
		return (-1);
	temp[BUFF_SIZE] = '\0';
	while ((i = read (fd, temp, BUFF_SIZE)))
	{
//		if (*line == NULL)
			*line = temp;
//		else
//			*line = ft_strjoin(*line, temp);
	}
	return (i);
}
