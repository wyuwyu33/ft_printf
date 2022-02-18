/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:02:50 by wyu               #+#    #+#             */
/*   Updated: 2022/02/17 19:17:16 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(t_info info, char ch)
{
	int count;

	count = 0;
	precision_redefine(&info, 1);
	width_redefine(&info, 1);
	count += print_space_prefix(&info);
	count += print_sign(info, '\0');
	count += print_notation(info);
	count += print_zero(&info);
	count += print_precision(&info);
	ft_putchar(ch);
	count++;
	count += print_space_postfix(&info);
	return (count);
}
