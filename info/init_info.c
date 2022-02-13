/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:01:37 by wyu               #+#    #+#             */
/*   Updated: 2022/02/10 06:57:29 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_info	init_info(void)
{
	t_info	info;

	info.dash = INVALID;
	info.zero = INVALID;
	info.hash = INVALID;
	info.space = INVALID;
	info.plus = INVALID;
	info.width = INVALID;
	info.precision = INVALID;
	info.error = INVALID;
	info.specifier = '\0';
	return (info);
}
