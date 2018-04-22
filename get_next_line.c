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

static t_list	*get_el(t_list **list, const int fd)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(list, temp);
	temp = *list;
	return (temp);
}

static int		record_lines(char **line, t_list **temp, char *s, int length)
{
	char	*str;
	int		i;

	i = 0;
	while (((char*)((*temp)->content))[i] != '\n'
		&& ((char*)((*temp)->content))[i] != '\0')
		i++;
	if (!(*line = ft_strsub((*temp)->content, 0, i)))
		return (-1);
	if (((char*)((*temp)->content))[i] == '\0')
	{
		ft_strclr((*temp)->content);
		return (1);
	}
	str = ft_strsub((*temp)->content, i + 1, length - i - 1);
	ft_strclr((*temp)->content);
	(*temp)->content = str;
	if (!(ft_strlen((*temp)->content)))
		free(s);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*temp;
	int				lstr;
	char			buf[BUFF_SIZE + 1];
	char			*str;

	str = NULL;
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || !(temp = get_el(&list, fd)))
		return (-1);
	while ((lstr = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[lstr] = '\0';
		if (!(str = ft_strjoin(temp->content, buf)))
			return (-1);
		if (temp->content)
			free(temp->content);
		temp->content = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (lstr < BUFF_SIZE && !(ft_strlen(temp->content)))
		return (0);
	lstr = record_lines(line, &temp, str, ft_strlen(temp->content));
	return (lstr);
}
