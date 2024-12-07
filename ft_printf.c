/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosokyrk <bosokyrk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:21:08 by bosokyrk          #+#    #+#             */
/*   Updated: 2024/12/07 16:28:15 by bosokyrk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	vartype(va_list list, char type)
{
	if (type == 'c')
		return (writechar(va_arg(list, int)));
	else if (type == 's')
		return (writestr(va_arg(list, char *)));
	else if (type == 'p')
		return (writeptr(va_arg(list, void *)));
	else if (type == 'd' || type == 'i')
		return (writenbr(va_arg(list, int)));
	else if (type == 'u')
		return (writeunsignednbr(va_arg(list, unsigned int)));
	else if (type == 'x')
		return (writehexlower(va_arg(list, int)));
	else if (type == 'X')
		return (writehexupper(va_arg(list, int)));
	else if (type == '%')
		return (writechar('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
			cnt += vartype(list, s[++i]);
		else
			cnt += writechar(s[i]);
		i++;
	}
	va_end(list);
	return (cnt);
}
