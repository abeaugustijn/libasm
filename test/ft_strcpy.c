/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/20 22:36:01 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/07/28 15:11:55 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *t_test_case;

static t_test_case	g_test_cases[] = {
	"jalallaa",
	"jalalallalalala",
	"a",
	"",
	NULL
};

static void	ft_strcpy_test_one(char *str)
{
	char	*dest;

	dest = malloc(ft_strlen(str));
	if (!dest)
		assert(0);
	assert(ft_strcpy(dest, str) == dest);
	assert(strcmp(dest, str) == 0);
}

void		ft_strcpy_test(void)
{
	int	i;

	printf("\nTEST: ft_strcpy \n");
	i = 0;
	while (g_test_cases[i] != NULL)
	{
		ft_strcpy_test_one(g_test_cases[i]);
		i++;
	}
	printf(SUCCESS_STR);
}
