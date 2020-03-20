/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 20:20:03 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/20 22:04:29 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <string.h>
#include <assert.h>

#include <stdio.h>

static void	ft_strlen_test_one(char *str)
{
	size_t a = ft_strlen(str);
	size_t b = strlen(str);
	printf("\texpected: %lu\tgot: %lu\n", b, a);
}

void	ft_strlen_test(void)
{
	printf("TEST: ft_strlen \n");
	ft_strlen_test_one("123123123");
	ft_strlen_test_one("abc");
	ft_strlen_test_one("aaa\0aaa");
	ft_strlen_test_one("a");
	ft_strlen_test_one("");
	ft_strlen_test_one("lkjlkjlkjlkjskgjakdfgadjfbgjadbfgadbfgbadfg");
}
