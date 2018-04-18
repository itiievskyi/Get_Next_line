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

#include <stdio.h>
#include "get_next_line.h"

static int	read_line(t_gnl_list **list, char **line)
{
	int					i;
	char				*temp;

	i = 1;
	if ((temp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	temp[BUFF_SIZE] = '\0';
	while (i > 0 && ft_strchr(temp, '\n') == NULL)
	{
		i = read((*list)->fdn, temp, BUFF_SIZE);
		*line = temp;
		(*list)->index += i;
	}
	(*list)->time++;
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_list	*list;
//	t_gnl_list			*temp;

	if (fd >= 0)
	{
		if ((list = (t_gnl_list*)malloc(sizeof(t_gnl_list))) == NULL)
			return (-1);
		list->fdn = fd;
		list->index = 0;
		list->time = 0;
		list->next = NULL;
		return (read_line(&list, line));
	}
	return (-1);
}
