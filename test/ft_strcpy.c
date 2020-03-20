/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:36:01 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/20 23:04:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void ft_strcpy_test_one(char *str)
{
	char	*dest;

	dest = malloc(ft_strlen(str));
	if (!dest)
		assert(0);
	assert(ft_strcpy(dest, str) == dest);
	printf("\ttesting: %s\n\tgot: %s\n\tdiff: %d\n\n",
			str,
			dest,
			ft_strcmp(dest, str));
}

void	ft_strcpy_test(void)
{
	printf("\nTEST: ft_strcpy \n");
	ft_strcpy_test_one("jalalalal");
	ft_strcpy_test_one("jalalalalaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_strcpy_test_one("a");
	ft_strcpy_test_one("");
}
