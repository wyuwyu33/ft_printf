/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:22:57 by wyu               #+#    #+#             */
/*   Updated: 2022/02/11 16:28:54 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_precision(t_info *info)
{
	int count;
	
	if (!ft_strchr("diuxX", info->specifier))
		return (0);
	count = info->precision;
	while (info->precision > 0)
	{
		ft_putchar('0');
		info->precision--;
	}
	return (count);
}