/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:46:09 by iassil            #+#    #+#             */
/*   Updated: 2024/01/29 19:40:04 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static int	ft_count_digit(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	long	nb;
	size_t	len;

	nb = (long)nbr;
	len = ft_count_digit(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	return (len);
}
