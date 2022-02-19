/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:40 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:26:10 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hexlen(t_info info, unsigned int unum)
{
	unsigned int	base;
	int				count;

	base = 16;
	count = 1;
	while (unum >= base)
	{
		unum /= base;
		count++;
	}
	if (info.hash == VALID && unum)
		return (count + 2);
	return (count);
}

int	print_puthex(char specifier, unsigned int unum)
{
	char			*digit;
	unsigned int	base;
	unsigned int	idx;
	int				count;

	if (specifier == 'X')
		digit = "0123456789ABCDEF";
	else
		digit = "0123456789abcdef";
	base = 16;
	if (base > unum)
		return (write(1, &digit[unum], 1));
	idx = unum % base;
	count = print_puthex(specifier, unum / base);
	write(1, &digit[idx], 1);
	return (count + 1);
}

int	print_hex(t_info info, unsigned int hex_num)
{
	int	count;
	int	len;

	count = 0;
	len = print_hexlen(info, hex_num);
	precision_redefine(&info, len);
	width_redefine(&info, len);
	count += print_space_prefix(&info);
	count += print_sign(info, '\0');
	if (hex_num)
		count += print_notation(info);
	count += print_zero(&info);
	count += print_precision(&info);
	count += print_puthex(info.specifier, hex_num);
	count += print_space_postfix(&info);
	return (count);
}
