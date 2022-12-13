/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:29:56 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/26 16:54:28 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (len = ft_charprint(va_arg(args, int)));
	else if (format == 's')
		return (len = ft_strprint(va_arg(args, char *)));
	else if (format == 'p')
		return (len = ft_ptrprint(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (len = ft_nbrprint(va_arg(args, int)));
	else if (format == 'u')
		return (len = ft_unsdprint(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (len = ft_hexprint(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (len = ft_percprint());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_charprint(str[i]);
		i ++;
	}
	va_end (args);
	return (len);
}
