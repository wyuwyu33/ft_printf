/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:22:34 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:45:07 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_flag(char **format, t_info *info)
{
	while (**format && ft_strchr(FLAGS, **format))
	{
		if (**format == '-')
			info->dash = VALID;
		else if (**format == '0')
			info->zero = VALID;
		else if (**format == '#')
			info->hash = VALID;
		else if (**format == ' ')
			info->space = VALID;
		else if (**format == '+')
			info->plus = VALID;
		else
		{
			info->error = VALID;
			return ;
		}
		(*format)++;
	}
}
