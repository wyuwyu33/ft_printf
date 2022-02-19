/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:23:06 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:23:56 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_and_print(char *format, va_list ap)
{
	int		count;
	int		printed;
	t_info	info;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			info = set_info(&format, &ap);
			printed = print_info(info, &ap);
			if (printed < 0)
				return (-1);
			count += printed;
			continue ;
		}
		ft_putchar(*(format++));
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	va_list		copy_ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	va_copy(copy_ap, ap);
	ret = parse_and_print((char *)format, copy_ap);
	va_end(copy_ap);
	va_end(ap);
	return (ret);
}
