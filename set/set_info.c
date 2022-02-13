/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:25:12 by wyu               #+#    #+#             */
/*   Updated: 2022/02/11 17:14:31 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_info	set_info(char **format, va_list ap)
{
	t_info info;

	info = init_info();
	set_flag(format, &info);
	set_width(format, &info, ap);
	set_precision(format, &info, ap);
	set_specifier(format, &info);
	filter_info(&info);
	return (info);
}
