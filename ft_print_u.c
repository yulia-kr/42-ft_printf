/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:20:08 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:16:06 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_unsd_itoa(unsigned int num)
{
	char	*nbr;
	int		len;

	len = ft_nbrlen(num);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	while (num)
	{
		nbr[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (nbr);
}

int	ft_unsdprint(unsigned int num)
{
	int		print;
	char	*n;

	print = 0;
	if (num == 0)
		print = print + write(1, "0", 1);
	else
	{
		n = ft_unsd_itoa(num);
		print = print + ft_strprint(n);
		free(n);
	}
	return (print);
}
