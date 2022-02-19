/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:32:32 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:39:45 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_space_prefix(t_info *info)
{
	int	count;

	if (info->zero == VALID || info->dash == VALID)
		return (0);
	count = info->width;
	while (info->width > 0)
	{
		ft_putchar(' ');
		info->width--;
	}
	return (count);
}
