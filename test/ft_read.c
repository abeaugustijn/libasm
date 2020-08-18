/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:03:11 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/18 14:13:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILENAME "ft_read.s"
#define BUFSIZE 500

#define ERRNO_TEST_FD 123123
#define ERRNO_TEST_BUF_SIZE 42

typedef ssize_t	(*t_read_function)(int, void *, size_t);

static void		ft_read_test_errno(void)
{
	char	*dummy_buffer;
	int		expected_errno;
	int		return_values[2];

	dummy_buffer = NULL;
	errno = 0;
	return_values[0] = read(ERRNO_TEST_FD, dummy_buffer, ERRNO_TEST_BUF_SIZE);
	expected_errno = errno;
	errno = 0;
	return_values[1] = ft_read(ERRNO_TEST_FD, dummy_buffer, ERRNO_TEST_BUF_SIZE);
	assert(errno == expected_errno);
	assert(return_values[0] == return_values[1]);
}

static ssize_t	ft_read_test_one(t_read_function read_function, char *buffer,
			char *filename, size_t buffer_size)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (read_function(fd, buffer, buffer_size));
}

void			ft_read_test(void)
{
	char	buffers[2][BUFSIZE];
	int		return_values[2];

	printf("\nTEST: ft_read \n");
	ft_read_test_errno();
	bzero(buffers, BUFSIZE * 2);
	return_values[0] = ft_read_test_one(read, buffers[0], FILENAME, BUFSIZE);
	return_values[1] = ft_read_test_one(ft_read, buffers[1], FILENAME, BUFSIZE);
	assert(return_values[0] == return_values[1]);
	assert(strncmp(buffers[0], buffers[1], return_values[0]) == 0);
	printf(SUCCESS_STR);
}
