/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:26:10 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/13 19:54:29 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

long int	ft_atoiswap(const char *n);
long* 		check_values (int argc, char **argv);
long* 		ft_convert_int (int argc, char **argv);
long*		ft_compare (long *i, int argc);
long*		ft_checkordered (long *i, int argc);
long* 		check_values (int argc, char **argv);
long* 		ft_convert_int (int argc, char **argv);
long*		ft_compare (long *i, int argc);
long*		ft_stacks (int argc,long *stk);
int			ft_move(long *stk, long *stk2);
#endif