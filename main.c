/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:04:59 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/16 10:05:01 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static void		check1(void)
{
	char	*line_0;
	int		fd_0;
	int		fd_1;
	int		fd_2;
	int		a;

	a = 0;
	fd_0 = open("test_0", O_RDONLY);
	fd_1 = open("test_1", O_RDONLY);
	fd_2 = open("tests/gnl7_1.txt", O_RDONLY);
	if ((a = get_next_line(fd_0, &line_0)) > -2)
	{
		printf("FD = %d\tRETURN = %d\n\"%s\"\n", fd_0, a, line_0);
		free(line_0);
	}
	if ((a = get_next_line(fd_0, &line_0)) > -2)
	{
		printf("FD = %d\tRETURN = %d\n\"%s\"\n", fd_0, a, line_0);
		free(line_0);
	}
	if ((a = get_next_line(fd_2, &line_0)) > -2)
	{
		printf("FD = %d\tRETURN = %d\n\"%s\"\n", fd_2, a, line_0);
		free(line_0);
	}
	if ((a = get_next_line(fd_1, &line_0)) > -2)
	{
		printf("FD = %d\tRETURN = %d\n\"%s\"\n", fd_0, a, line_0);
		free(line_0);
	}
}

int				main(int argc, char **argv)
{
	char	*line_0;
	int		fd_0;
	int		a;
	int		ret = 0;

	a = 0;
	if (argc > 1000 || !(argv[0]))
		return (0);
	if (argc == 2)
	{
		printf("############	ARGUMENT FILE	############\n\n");
		int fda = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fda, &line_0)) > 0)
		{
			printf("FD = %d\tRETURN = %d\n\"%s\"\n", fda, ret, line_0);
			free(line_0);
		}
		printf("FD = %d\tRETURN = %d\n", fda, ret);
		printf("\n############	ARGUMENT FILE	############\n\n");
	}
	printf("############	REDIRECTION TEST	############\n\n");
	int fda = 0;
	while ((ret = get_next_line(fda, &line_0)) > 0)
	{
		printf("FD = %d\tRETURN = %d\n\"%s\"\n", fda, ret, line_0);
		free(line_0);
	}
	printf("FD = %d\tRETURN = %d\n", fda, ret);
	printf("\n############	REDIRECTION TEST	############\n\n");
	fd_0 = open("tests/gnl10.txt", O_RDONLY);
	while ((a = get_next_line(fd_0, &line_0)) > -2)
	{
		if (a < 1)
		{
			printf("FD = %d\tRETURN = %d\n", fd_0, a);
			free(line_0);
			break ;
		}
		printf("FD = %d\tRETURN = %d\n\"%s\"\n", fd_0, a, line_0);
	}
	check1();
	line_0 = NULL;
	if ((a = get_next_line(6, &line_0)) > -2)
		printf("RETURN = %d\n\"%s\"\n", a, line_0);
	free(line_0);
	system ("leaks test_gnl");
	return (0);
}
