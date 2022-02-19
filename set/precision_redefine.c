/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_redefine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:27:32 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:44:20 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	precision_redefine(t_info *info, int size)
{
	if (info->precision > size)
		info->precision -= size;
	else
		info->precision = 0;
}
