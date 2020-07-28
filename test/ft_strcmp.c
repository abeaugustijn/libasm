/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/20 22:14:15 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/07/28 15:11:40 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef char *t_test_case[2];

static t_test_case	g_test_cases[] = {
	{"test", "test"},
	{"", "test"},
	{"test", "a"},
	{"test123", "test"},
	{"test0", "test1"},
	{"", ""},
	{NULL, NULL},
};

static void	ft_strcmp_test_one(char *str1, char *str2)
{
	int	return_values[2];

	return_values[0] = ft_strcmp(str1, str2);
	return_values[1] = strcmp(str1, str2);
	assert(return_values[0] == return_values[1]);
}

void		ft_strcmp_test(void)
{
	int	i;

	printf("\nTEST: ft_strcmp \n");
	i = 0;
	while (g_test_cases[i][0] != NULL)
	{
		ft_strcmp_test_one(g_test_cases[i][0], g_test_cases[i][1]);
		i++;
	}
	printf(SUCCESS_STR);
}
