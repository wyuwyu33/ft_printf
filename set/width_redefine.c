/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_redefine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:03:31 by wyu               #+#    #+#             */
/*   Updated: 2022/02/11 19:00:30 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_redefine(t_info *info, int size)
{
	int sign;

	sign = info->plus == VALID || info->space == VALID;
	if (sign)
		info->width--;
	if (info->width > info->precision + size)
		info->width -= info->precision + size;
	else
		info->width = 0;
}