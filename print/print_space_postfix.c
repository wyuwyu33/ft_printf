/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_postfix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:00:32 by wyu               #+#    #+#             */
/*   Updated: 2022/02/13 11:26:33 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_space_postfix(t_info *info)
{
	int count;

	if (info->dash != VALID)
		return (0);
	count = info->width;
	while (info->width > 0)
	{
		ft_putchar(' ');
		info->width--;
	}
	return (count);
}
