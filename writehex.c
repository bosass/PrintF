/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writehex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosokyrk <bosokyrk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:23:19 by bosokyrk          #+#    #+#             */
/*   Updated: 2024/12/07 16:26:59 by bosokyrk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	hexconvert(size_t nbr)
{
	char	*hex;
	int		cnt;

	cnt = 0;
	hex = "0123456789abcdef";
	if (nbr >= 0 && nbr < 16)
		cnt += writechar(hex[nbr]);
	else
	{
		cnt += hexconvert(nbr / 16);
		cnt += hexconvert(nbr % 16);
	}
	return (cnt);
}

int	writeptr(size_t *ptr)
{
	int		cnt;

	cnt = 0;
	if (ptr == NULL)
	{
		cnt += writestr("(nil)");
		return (cnt);
	}
	else
	{
		cnt += writestr("0x");
		cnt += hexconvert((size_t)ptr);
		return (cnt);
	}
}

int	writehexlower(unsigned int nbr)
{
	int	cnt;

	cnt = hexconvert((size_t)nbr);
	return (cnt);
}

int	writehexupper(unsigned int nbr)
{
	char	*hex;
	int		cnt;

	cnt = 0;
	hex = "0123456789ABCDEF";
	if (nbr >= 0 && nbr < 16)
		cnt += writechar(hex[nbr]);
	else
	{
		cnt += writehexupper(nbr / 16);
		cnt += writehexupper(nbr % 16);
	}
	return (cnt);
}
