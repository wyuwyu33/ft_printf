/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:03:28 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:40:18 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_strlen(t_info info, char *str)
{
	int	limit;
	int	len;

	if (info.precision_activate == VALID)
		limit = info.precision;
	else
		limit = INT_MAX;
	if (!str)
		len = 6;
	else
		len = (int)ft_strlen(str);
	if (limit > len)
		return (len);
	else
		return (limit);
}

int	print_putstr(char *str, int len)
{
	if (!str)
		return (write(1, "(null)", len));
	return (write(1, str, len));
}

int	print_string(t_info info, char *str)
{
	int	count;
	int	len;

	count = 0;
	len = print_strlen(info, str);
	precision_redefine(&info, len);
	width_redefine(&info, len);
	count += print_space_prefix(&info);
	count += print_sign(info, '\0');
	count += print_notation(info);
	count += print_zero(&info);
	count += print_precision(&info);
	count += print_putstr(str, len);
	count += print_space_postfix(&info);
	return (count);
}
