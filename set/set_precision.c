/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:23 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:06:10 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	precision_asterisk(t_info *info, int asterisk)
{
	if (asterisk <= -INT32_MAX || INT32_MAX <= asterisk)
	{
		info->width = -1;
		return ;
	}
	if (asterisk < 0)
		asterisk = 0;
	info->precision = asterisk;
}

void	set_precision(char **format,t_info *info, va_list *ap)
{
	int tmp;
	
	if (**format != '.')
		return ;
	info->precision_activate = VALID;
	(*format)++;
	if (info->zero == VALID)
		info->zero = -1;
	if (!**format || !ft_strchr("123456789*", **format))
		return ;
	if (**format && ft_strchr("123456789", **format))
	{
		info->precision = ft_atoi(*format);
		while (**format && ft_strchr("0123456789", **format))
			(*format)++;
	}
	else if (**format && **format == '*')
	{
		tmp = va_arg(*ap, int);
		precision_asterisk(info, tmp);
		(*format)++;
	}
}
