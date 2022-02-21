/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:23:19 by wyu               #+#    #+#             */
/*   Updated: 2022/02/21 20:38:02 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	filter_specifier(t_info *info)
{
	if (!ft_strchr("di", info->specifier) && (info->space || info->plus))
		info->error = VALID;
	if (!ft_strchr("xX", info->specifier) && info->hash)
		info->error = VALID;
	if (!ft_strchr("sdiuxX%", info->specifier) && info->precision != 0)
		info->error = VALID;
	if (!ft_strchr("diuxX%", info->specifier) && info->zero)
		info->error = VALID;
}

void	filter_flag(t_info *info)
{
	if (info->dash && info->zero)
		info->error = VALID;
	if (info->space && info->plus)
		info->error = VALID;
}

void	filter_info(t_info *info)
{
	filter_specifier(info);
	filter_flag(info);
}
