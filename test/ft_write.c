/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 18:51:32 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/17 11:49:05 by aaugusti      ########   odam.nl         */
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

#define ERRNO_TEST_FD 123123
#define ERRNO_TEST_STRING "test"
#define ERRNO_TEST_LENGTH 4

#define RETURN_TEST_FILENAME "/dev/null"
#define RETURN_TEST_STRING "test!"
#define RETURN_TEST_LENGTH 5

static void	ft_write_test_errno(void)
{
	int	expected_errno;

	errno = 0;
	write(ERRNO_TEST_FD, ERRNO_TEST_STRING, ERRNO_TEST_LENGTH);
	expected_errno = errno;
	errno = 0;
	ft_write(ERRNO_TEST_FD, ERRNO_TEST_STRING, ERRNO_TEST_LENGTH);
	assert(errno == expected_errno);
}

static void	ft_write_test_return_value(void)
{
	const int	fd = open(RETURN_TEST_FILENAME, O_WRONLY);
	int			return_values[2];
	int			errno_values[2];

	errno = 0;
	return_values[0] = write(fd, RETURN_TEST_STRING, RETURN_TEST_LENGTH);
	errno_values[0] = errno;
	errno = 0;
	return_values[1] = ft_write(fd, RETURN_TEST_STRING, RETURN_TEST_LENGTH);
	errno_values[1] = errno;
	assert(return_values[0] == return_values[1]);
	assert(errno_values[0] == errno_values[1]);
	close(fd);
}

void		ft_write_test(void)
{
	const char	*str = SUCCESS_STR;

	printf("\nTEST: ft_write \n");
	ft_write_test_errno();
	ft_write_test_return_value();
	ft_write(1, str, strlen(str));
}
