/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:03:39 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:42:07 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	print_int_setinfo(t_info *info, int num)
{
	if (num >= 0)
		return ('+');
	info->plus = VALID;
	return ('-');
}

int	print_intlen(int num)
{
	int	base;
	int	count;

	if (!num)
		return (1);
	base = 10;
	count = 0;
	while (num)
	{
		num /= base;
		count++;
	}
	return (count);
}

int	print_putint_rec(int num)
{
	int	base;
	int	count;
	int	idx;

	base = 10;
	if (num < 0)
	{
		idx = -(num % base);
		count = print_putint_rec(-(num / base));
	}
	else if (!num)
		return (0);
	else
	{
		idx = num % base;
		count = print_putint_rec(num / base);
	}
	write(1, &"0123456789"[idx], 1);
	return (count + 1);
}

int	print_putint(int num)
{
	if (!num)
		return (write(1, "0", 1));
	return (print_putint_rec(num));
}

int	print_int(t_info info, int i_num)
{
	int		count;
	int		len;
	char	sign;

	count = 0;
	sign = print_int_setinfo(&info, i_num);
	len = print_intlen(i_num);
	precision_redefine(&info, len);
	width_redefine(&info, len);
	count += print_space_prefix(&info);
	count += print_sign(info, sign);
	count += print_notation(info);
	count += print_zero(&info);
	count += print_precision(&info);
	count += print_putint(i_num);
	count += print_space_postfix(&info);
	return (count);
}
