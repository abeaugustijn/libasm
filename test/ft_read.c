/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:03:11 by aaugusti          #+#    #+#             */
/*   Updated: 2020/07/07 21:07:30 by aaugusti      ########   odam.nl         */
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
	int		read1_ret;
	int 	read2_ret;

	bzero(buf1, BUFSIZE);
	bzero(buf2, BUFSIZE);
	fd1 = open(FILENAME, O_RDONLY);
	fd2 = open(FILENAME, O_RDONLY);
	printf("\nTEST: ft_read \n");
	read1_ret = read(fd1, buf1, BUFSIZE);
	read2_ret = ft_read(fd2, buf2, BUFSIZE);
	assert(read1_ret == read2_ret);
	if (strncmp(buf1, buf2, read1_ret))
		printf("ft_read_test failed\n");
}
