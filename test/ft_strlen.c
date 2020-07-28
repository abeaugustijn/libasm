/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/20 20:20:03 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/07/28 15:09:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 500

void	ft_strlen_test(void)
{
	char	buff[BUFFER_SIZE];
	size_t	i;
	size_t	j;

	i = 0;
	printf("TEST: ft_strlen\n");
	bzero(buff, BUFFER_SIZE);
	while (i < BUFFER_SIZE - 1)
	{
		j = 0;
		buff[i] = (char)('a' + i % 26);
		while (j < i)
		{
			assert(ft_strlen(buff + j) == strlen(buff + j));
			j++;
		}
		i++;
	}
	printf(SUCCESS_STR);
}
