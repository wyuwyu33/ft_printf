/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:40:41 by wyu               #+#    #+#             */
/*   Updated: 2022/02/11 17:13:38 by wyu              ###   ########.fr       */
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
