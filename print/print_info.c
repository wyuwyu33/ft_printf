/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:24:17 by wyu               #+#    #+#             */
/*   Updated: 2022/02/18 23:19:48 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_info(t_info info, va_list *ap)
{
	char	specifier;
	int		count;

	if (info.error || info.specifier == '\0' || info.width < 0)
		return (-1);
	specifier = info.specifier;
	if (specifier == 'c')
		count = print_char(info, (char)va_arg(*ap, int));
	else if (specifier == '%')
		count = print_char(info, '%');
	else if (specifier == 's')
		count = print_string(info, va_arg(*ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = print_int(info, va_arg(*ap, int));
	else if (specifier == 'u')
		count = print_unsigned(info, va_arg(*ap, unsigned int));
	else if (specifier == 'p') // to do
		count = print_address(info, va_arg(*ap, size_t));
	else if (specifier == 'x' || specifier == 'X')
		count = print_hex(info, va_arg(*ap, unsigned int));
	else
		return (-1);
	return (count);
}
