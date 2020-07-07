/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 20:20:03 by aaugusti          #+#    #+#             */
/*   Updated: 2020/07/07 21:39:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void	ft_strlen_test(void)
{
	char	buff[500];
	size_t	i;
	size_t	j;

	i = 0;
	printf("TEST: ft_strlen\n");
	bzero(buff, 500);
	while (i < 499)
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
