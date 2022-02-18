/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:40:41 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 01:22:58 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_specifier(char **format, t_info *info)
{
	if (!**format || !ft_strchr(TYPE, **format))
		return ;
	info->specifier = **format;
	(*format)++;
}
