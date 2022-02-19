/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:11 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:41:03 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_addresslen(size_t address)
{
	size_t	base;
	int		count;

	base = 16;
	count = 1;
	while (address >= base)
	{
		address /= base;
		count++;
	}
	return (count + 2);
}

int	print_putaddress(size_t address)
{
	size_t	base;
	size_t	idx;
	int		count;

	base = 16;
	if (base > address)
		return (write(1, &"0123456789abcdef"[address], 1));
	idx = address % base;
	count = print_putaddress(address / base);
	write(1, &"0123456789abcdef"[idx], 1);
	return (count + 1);
}

int	print_address(t_info info, size_t address)
{
	int	count;
	int	len;

	count = 0;
	len = print_addresslen(address);
	precision_redefine(&info, len);
	width_redefine(&info, len);
	count += print_space_prefix(&info);
	count += print_sign(info, '\0');
	count += print_notation(info);
	count += print_zero(&info);
	count += print_precision(&info);
	count += print_putaddress(address);
	count += print_space_postfix(&info);
	return (count);
}
