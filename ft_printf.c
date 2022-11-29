/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:25:13 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/29 04:36:42 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		i;

	i = 0;
	va_start(args, str);
	while (str[i] && str)
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		else
		{
			i++;
			if (str[i] == 'u')
				ft_putnbr_unsigned_fd(va_arg(args, unsigned), 1);
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (str[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (str[i] == '%' || str[i--] == '\n')
				ft_putchar_fd('%', 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("numero: %%\n");
	return (0);
}
