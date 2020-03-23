/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 18:51:32 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 10:10:23 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <stdio.h>

void	ft_write_test(void)
{
	char	*str;
	size_t	len;

	str = "If you see this, it worked!\n";
	len = ft_strlen(str);
	printf("\nTEST: ft_write \n");
	ft_write(1, str, len);
}
