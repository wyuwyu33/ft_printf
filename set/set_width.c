/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:22:59 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:42:32 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_asterisk(t_info *info, int asterisk)
{
	if (asterisk <= -INT32_MAX || INT32_MAX <= asterisk)
	{
		info->width = -1;
		return ;
	}
	if (asterisk < 0)
	{
		info->dash = VALID;
		asterisk *= -1;
	}
	info->width = asterisk;
}

void	set_width(char **format, t_info *info, va_list *ap)
{
	int	tmp;

	if (**format && ft_strchr("123456789", **format))
	{
		info->width = ft_atoi(*format);
		while (**format && ft_strchr("0123456789", **format))
			(*format)++;
	}
	else if (**format && **format == '*')
	{
		tmp = va_arg(*ap, int);
		width_asterisk(info, tmp);
		(*format)++;
	}
}
