/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:03:56 by wyu               #+#    #+#             */
/*   Updated: 2022/02/18 22:56:55 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_uintlen(unsigned int unum)
{
	unsigned int base;
	int count;

	base = 10;
	count = 1;
	while (unum >= base)
	{
		unum /= base;
		count++;
	}
	return (count);
}

int print_putunsinged(unsigned int unum)
{
	unsigned int	base;
	unsigned int	idx;
	int				count;

	base = 10;
	if (unum < base)
		return (write(1, &"0123456789"[unum], 1));
	idx = unum % base;
	count = print_putunsinged(unum / base);
	write(1, &"0123456789"[idx], 1);
	return (count + 1);
}

int	print_unsigned(t_info info, unsigned int u_num)
{
	int count;
	int len;

	count = 0;
	len = print_uintlen(u_num);
	precision_redefine(&info, len);
	width_redefine(&info, len);
	count += print_space_prefix(&info);
	count += print_sign(info, '\0');
	count += print_notation(info);
	count += print_zero(&info);
	count += print_precision(&info);
	count += print_putunsinged(u_num);
	count += print_space_postfix(&info);
	return (count);
}