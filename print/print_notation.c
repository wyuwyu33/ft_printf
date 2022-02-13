/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_notation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:59:27 by wyu               #+#    #+#             */
/*   Updated: 2022/02/11 16:10:48 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_notation(t_info info)
{
	if (!ft_strchr("xXp", info.specifier))
		return (0);
	if (!(info.specifier == 'p') && !info.hash)
		return (0);
	if (ft_strchr("xp", info.specifier))
		return (ft_putstr("0x"));
	else if (info.specifier ==  'X')
		return (ft_putstr("0X"));
	return (0);
}