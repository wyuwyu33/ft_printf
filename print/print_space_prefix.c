/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:32:32 by wyu               #+#    #+#             */
/*   Updated: 2022/02/13 09:10:21 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_space_prefix(t_info *info)
{
	int count;

	if (info->zero == VALID || info->dash == VALID)
		return (0);
	while (info->width > 0)
	count = info->width;
	{
		ft_putchar(' ');
		info->width--;
	}
	return (count);
}
