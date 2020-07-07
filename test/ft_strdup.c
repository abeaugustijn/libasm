/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:14:41 by aaugusti          #+#    #+#             */
/*   Updated: 2020/07/07 21:41:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTESTS (50)

#if 1

void	ft_strdup_test(void)
{
	char	*str1;
	char	*str2;
	char	test[NTESTS + 1];
	int		i;

	bzero(test, NTESTS + 1);
	printf("\nTEST: ft_strdup \n");
	i = 0;
	while (i < NTESTS)
	{
		test[i] = i % 26 + 'a';
		str1 = strdup(test);
		str2 = ft_strdup(test);
		assert(!ft_strcmp(str1, str2));
		free(str1);
		free(str2);
		i++;
	}
	printf(SUCCESS_STR);
}

#else

void	ft_strdup_test(void)
{
	char	*res;
	char	*str = "test\n";
	res = ft_strdup(str);
	printf("%s\n", res);
	free(res);
}

#endif
