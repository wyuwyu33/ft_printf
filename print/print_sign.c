/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:50:50 by wyu               #+#    #+#             */
/*   Updated: 2022/02/11 15:58:31 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_sign(t_info info, char sign)
{
	if (sign == '-')
	{
		ft_putchar('-');
		return (1);
	}
	else if (sign != '+')
		return (0);
	if (!info.space && !info.plus)
		return (0);
	if (info.space == VALID)
		ft_putchar(' ');
	else if (info.plus == VALID)
		ft_putchar('+');
	else
		return (0);
	return (1);
}