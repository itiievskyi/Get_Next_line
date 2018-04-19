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

int main(int argc, char **argv)
{
	int a = 0;
	if (argc > 1000 || !(argv[0]))
		return (0);
	char *line_0;
	int fd_0;
	fd_0 = open(argv[1], O_RDONLY);
	while ((a = get_next_line(fd_0, &line_0)) > -2)
	{
		if (a < 1)
		{
			printf("RETURN = %d\n", a);
			break ;
		}
		printf("RETURN = %d\n\"%s\"\n", a, line_0);
	}
//	printf("\nint = %d, line = %s\n", get_next_line(fd_0, &line_0), line_0);
//	printf("\nint = %d, line = %s\n", get_next_line(fd_0, &line_0), line_0);

/*
	char strrrr[4];
	int fd_1 = open("test_1", O_RDONLY);
	read(fd_1, strrrr, 4);
	printf("%s\n", strrrr);
	read(fd_1, strrrr, 4);
	printf("%s\n", strrrr);
	read(fd_1, strrrr, 4);
	printf("%s\n", strrrr);
	read(fd_1, strrrr, 4);
	printf("%s\n", strrrr);
*/
	return 0;
}
