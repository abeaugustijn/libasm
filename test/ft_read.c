/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:03:11 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/07/28 14:54:06 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILENAME "ft_read.s"
#define BUFSIZE 500

typedef ssize_t	(*t_read_function)(int, void *, size_t);

ssize_t		ft_read_test_one(t_read_function read_function, char *buffer,
			char *filename, size_t buffer_size)
{
	int	fd;

	fd = open(filename, buffer_size);
	return (read_function(fd, buffer, buffer_size));
}

void		ft_read_test(void)
{
	char	buffers[2][BUFSIZE];
	int		return_values[2];

	printf("\nTEST: ft_read \n");
	bzero(buffers, BUFSIZE * 2);
	return_values[0] = ft_read_test_one(read, buffers[0], FILENAME, BUFSIZE);
	return_values[1] = ft_read_test_one(ft_read, buffers[1], FILENAME, BUFSIZE);
	assert(return_values[0] == return_values[1]);
	assert(strncmp(buffers[0], buffers[1], return_values[0]) == 0);
	printf(SUCCESS_STR);
}
