/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:03:11 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 10:10:00 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILENAME ("ft_read.asm")
#define BUFSIZE (500)

void	ft_read_test(void)
{
	char	buf1[BUFSIZE];
	char	buf2[BUFSIZE];
	int		fd1;
	int		fd2;

	bzero(buf1, BUFSIZE);
	bzero(buf2, BUFSIZE);
	fd1 = open(FILENAME, O_RDONLY);
	fd2 = open(FILENAME, O_RDONLY);
	printf("\nTEST: ft_read \n");
	assert(read(fd1, buf1, BUFSIZE) == ft_read(fd2, buf2, BUFSIZE));
	printf("buf1: %s\n", buf1);
	printf("buf2: %s\n", buf2);
	if (ft_strcmp(buf1, buf2))
		printf("ft_read_test failed\n");
}
