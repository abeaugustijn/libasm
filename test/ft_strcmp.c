/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:14:15 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/20 22:59:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <string.h>
#include <stdio.h>

static void ft_strcmp_test_one(char *str1, char *str2)
{
	int a = ft_strcmp(str1, str2);
	int b = strcmp(str1, str2);
	printf("\texpected: %d\tgot: %d\n", b, a);
}

void	ft_strcmp_test(void)
{
	printf("\nTEST: ft_strcmp \n");
	ft_strcmp_test_one("test", "test");
	ft_strcmp_test_one("", "test");
	ft_strcmp_test_one("test", "a");
	ft_strcmp_test_one("test123", "test");
	ft_strcmp_test_one("test0", "test1");
	ft_strcmp_test_one("", "");
}
