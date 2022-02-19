/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:11:12 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:39:00 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_zero(t_info *info)
{
	int	count;

	if (info->zero != VALID)
		return (0);
	count = info->width;
	while (info->width > 0)
	{
		ft_putchar('0');
		info->width--;
	}
	return (count);
}
