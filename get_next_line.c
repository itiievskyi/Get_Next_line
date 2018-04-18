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

static t_list	*get_list_elem(t_list **list, const int fd)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(list, temp);
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*temp;
	int				i;
	int				lstr;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 ||
		!(*line = ft_strnew(1)) || (temp = get_list_elem(&list, fd)) == NULL)
		return (-1);
	while ((lstr = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[lstr] = '\0';
		if (!(temp->content = ft_strjoin(temp->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	*line = temp->content;
	if (lstr < BUFF_SIZE)
		return (0);
	i = 0;
	return (1);
}
