/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:55:11 by wyu               #+#    #+#             */
/*   Updated: 2022/02/13 08:58:38 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define TYPE "csdiupxX%"
# define FLAGS "-0# +"
# define VALID 1
# define INVALID 0

typedef struct	s_info
{
	int			dash;
	int			zero;
	int			hash;
	int			space;
	int			plus;
	int			width;
	int			precision;
	int			error;
	char		specifier;
}				t_info;

// info
t_info	init_info(void);
void	filter_info(t_info *info);

// print
int		print_address(t_info info, size_t address);
int		print_char(t_info info, char ch);
int		print_hex(t_info info, unsigned int hex_num);
int		print_info(t_info info, va_list ap);
int		print_int(t_info info, int i_num);
int		print_notation(t_info info);
int		print_precision(t_info *info);
int		print_sign(t_info info, char sign);
int		print_space_postfix(t_info *info);
int		print_space_prefix(t_info *info);
int		print_string(t_info info, char *str);
int		print_unsigned(t_info info, unsigned int u_num);
int		print_zero(t_info *info);

// set
void	precision_redefine(t_info *info, int size);
void	set_flag(char **format,t_info *info);
t_info	set_info(char **format, va_list ap);
void	set_precision(char **format,t_info *info, va_list ap);
void	set_specifier(char **format, t_info *info);
void	set_width(char **format,t_info *info, va_list ap);
void	width_redefine(t_info *info, int size);

// utill
void	ft_putchar(char c);
int		ft_putstr(char *str);

// ft_printf
int		ft_printf(const char *format, ...);

#endif