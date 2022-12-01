/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:50:57 by plopes-c          #+#    #+#             */
/*   Updated: 2022/12/01 18:53:03 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long		number;
	int			i;
	char		*str;

	i = 0;
	number = n;
	str = "0123456789";
	if (number < 0)
	{
		i = write(fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
		i += ft_putnbr_fd((number / 10), fd);
	return (i + ft_putchar_fd(str[number % 10], fd));
}
