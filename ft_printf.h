/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosokyrk <bosokyrk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:23:15 by bosokyrk          #+#    #+#             */
/*   Updated: 2024/12/07 16:23:16 by bosokyrk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	writechar(char chr);
int	writestr(char *str);
int	writenbr(int nbr);
int	writeunsignednbr(unsigned int nbr);
int	hexconvert(size_t nbr);
int	writeptr(size_t *ptr);
int	writehexlower(unsigned int nbr);
int	writehexupper(unsigned int nbr);
int	vartype(va_list list, char type);
int	ft_printf(const char *s, ...);

#endif