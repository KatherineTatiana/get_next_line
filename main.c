/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 10:20:45 by ksoto             #+#    #+#             */
/*   Updated: 2019/11/02 10:20:50 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	char *line = NULL;

	while (get_next_line(fd1, &line) == 1)
	{
		puts(line);
		free(line);
	}
	while (get_next_line(fd2, &line) == 1)
	{
		puts(line);
		free(line);
	}
	return (0);
}