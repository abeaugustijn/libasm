/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 18:51:32 by aaugusti          #+#    #+#             */
/*   Updated: 2020/07/07 21:37:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include "test.h"
#include <stdio.h>

void	ft_write_test(void)
{
	char	*str;
	size_t	len;

	str = SUCCESS_STR;
	len = ft_strlen(str);
	printf("\nTEST: ft_write \n");
	ft_write(1, str, len);
}
