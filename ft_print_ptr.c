/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:29:29 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/26 16:57:29 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(uintptr_t p)
{
	if (p >= 16)
	{
		ft_putptr(p / 16);
		ft_putptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar_fd((p + '0'), 1);
		else
			ft_putchar_fd((p - 10 + 'a'), 1);
	}
}

int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr = ptr / 16;
	}	
	return (len);
}

int	ft_ptrprint(unsigned long long ptr)
{
	int	print;

	print = 0;
	print += write(1, "0x", 2);
	if (ptr == 0)
		print = write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		print += ft_ptrlen(ptr);
	}
	return (print);
}
