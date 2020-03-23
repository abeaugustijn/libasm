/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:14:41 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 13:03:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
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
	char	test[NTESTS];
	int		i;

	assert(ft_strdup(NULL) == 0);

	bzero(test, NTESTS);
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
