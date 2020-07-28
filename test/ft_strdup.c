/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:14:41 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/07/28 15:09:28 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTESTS 1000

void	ft_strdup_test_one(char *test_string)
{
	char	*return_values[2];

	return_values[0] = strdup(test_string);
	return_values[1] = ft_strdup(test_string);
	assert(strcmp(return_values[0], return_values[1]) == 0);
	free(return_values[0]);
	free(return_values[1]);
}

void	ft_strdup_test(void)
{
	char	test[NTESTS + 1];
	int		i;

	printf("\nTEST: ft_strdup \n");
	bzero(test, NTESTS + 1);
	i = 0;
	while (i < NTESTS)
	{
		test[i] = i % 26 + 'a';
		ft_strdup_test_one(test);
		i++;
	}
	printf(SUCCESS_STR);
}
