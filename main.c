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

int main()
{
	char *line_0;
	printf("int = %d, line = %s\n", get_next_line(1, &line_0), line_0);
	ft_putstr("-= libft check: OK=-\n");
	system("test_gnl");
	return 0;
<<<<<<< HEAD

=======
	
>>>>>>> 15dca8053380383b8c65db787bed8b5826368a9b
}
