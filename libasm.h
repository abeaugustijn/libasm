/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 20:20:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 10:14:15 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stddef.h>
# include <sys/types.h>

extern size_t	ft_strlen(const char *s) asm ("ft_strlen");
extern int		ft_strcmp(const char *str1, const char *str2) asm ("ft_strcmp");
extern char     *ft_strcpy(char *dest, const char *src) asm ("ft_strcpy");
extern ssize_t	ft_write(int fd, const void *buf, size_t count) asm ("ft_write");
extern ssize_t 	ft_read(int fd, void *buf, size_t count) asm("ft_read");
extern char		*ft_strdup(const char *s) asm("ft_strdup");

#endif
