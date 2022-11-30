/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:25:13 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/30 00:23:33 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

void	checknprint(va_list args, int i, const char *str);

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
			checknprint(args, i, str);
		}
		i++;
	}
	va_end(args);
	return (0);
}

void	checknprint(va_list args, int i, const char *str)
{
	if (str[i] == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned), 1);
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (str[i] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (str[i] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (str[i] == '%')
		ft_putchar_fd('%', 1);
	if (str[i] == 'x')
		ft_putnbr_hexa_fd(va_arg(args, unsigned int), 1, 0);
	if (str[i] == 'X')
		ft_putnbr_hexa_fd(va_arg(args, unsigned int), 1, 1);
	if (str[i] == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_hexa_fd(va_arg(args, unsigned long int), 1, 0);
	}
}

// int	main(void)
// {
// 	char	*f;

// 	f = "abc";
// 	ft_printf("numero: %p\n", f);
// 	printf("numero: %p\n", f);
// 	return (0);
// }
