/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:26:10 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/20 20:37:54 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

long int	ft_atoiswap(const char *n);
void		ft_orderit(long *stk, long *stk2, int dig);
long* 		check_values (int argc, char **argv, long *cad);
long*		ft_checkordered (long *i, int argc);
long* 		ft_convert_int (int argc, char **argv, long *cad);
long*		ft_compare (long *i, int argc);
long*		ft_stacks (int argc,long *stk);
void		ft_orders(long *stk, long *stk2, int dig);
void		ft_printstacks (long *i, long *j, int dig);
void		ft_move(long *stk, long *stk2, int dig, char *cad);
void		ft_swap(long *stk, int dig);
void		ft_push(long *stk, long *stk2, int dig);
void		ft_rotate(long *stk, int dig);
int			ft_findbigger(long *stk, int dig);
int			ft_findsmaller(long *stk, int dig);
char*		ft_ordertree(long *stk, int dig);
void		ft_orderfour(long *stk, long *stk2, int dig);
void		ft_orderfive(long *stk, long *stk2, int dig);
long		*ft_stkdup(long int *s, int size);
void		ft_help(void);
#endif