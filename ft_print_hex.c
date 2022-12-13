/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:33:47 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/25 19:08:54 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned	int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else if (n <= 9)
		ft_putchar_fd((n + '0'), 1);
	else if (format == 'x')
		ft_putchar_fd((n - 10 + 'a'), 1);
	else if (format == 'X')
		ft_putchar_fd((n - 10 + 'A'), 1);
}

int	ft_hexprint(unsigned int n, const char format)
{
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	else
		ft_puthex(n, format);
	return (ft_hexlen(n));
}
