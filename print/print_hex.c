/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:40 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 16:05:46 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hexlen(unsigned int unum)
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

int	print_hex_notationlen(t_info info, unsigned int unum)
{
	if (info.hash == VALID && unum)
		return (2);
	return (0);
}

int	print_hex(t_info info, unsigned int hex_num)
{
	int	count;
	int	len;
	int	notation_len;
	
	count = 0;
	len = print_hexlen(hex_num);
	notation_len = print_hex_notationlen(info, hex_num);
	precision_redefine(&info, len);
	width_redefine(&info, len + notation_len);
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
