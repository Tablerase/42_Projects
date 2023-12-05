/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:22:51 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/01 16:08:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);

int		ft_print_str(char *str);
int		ft_print_char(char c);
int		ft_reverse_print_str(char *str);
char	*ft_putnbr_base(long long nbr, char *base, char *str);
char	*ft_uputnbr_base(unsigned long long nbr, char *base, char *str);

#endif