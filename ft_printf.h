/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:55:56 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:31:59 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h> 

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_charprint(int c);
int		ft_strprint(char *str);
int		ft_nbrprint(int n);
int		ft_percprint(void);
int		ft_ptrlen(uintptr_t ptr);
int		ft_ptrprint(unsigned long long ptr);
int		ft_nbrlen(unsigned int num);
int		ft_unsdprint(unsigned int num);
int		ft_hexlen(unsigned	int n);
int		ft_hexprint(unsigned int n, const char format);
char	*ft_unsd_itoa(unsigned int num);

void	ft_putptr(uintptr_t p);
void	ft_puthex(unsigned int n, const char format);
void	putstr(char *str);

int		ft_len(int n);
int		ft_pos_neg(int n);
char	*ft_null(int n, char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);

#endif
