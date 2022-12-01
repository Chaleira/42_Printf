/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 05:02:18 by plopes-c          #+#    #+#             */
/*   Updated: 2022/12/01 18:34:10 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789";
	if (n >= 10)
		i = ft_putnbr_fd(n / 10, fd);
	return (i + ft_putchar_fd(str[n % 10], fd));
}
