/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:55:59 by wyu               #+#    #+#             */
/*   Updated: 2022/02/19 02:13:45 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
	printf("----printf--\n");
	printf("\n%d\n", printf("% s", ""));
	printf("----ft_printf--\n");
	printf("\n%d", ft_printf("% s", ""));
	return (0);
}
