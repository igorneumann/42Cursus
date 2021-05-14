/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:26:10 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/13 20:45:33 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

long int	ft_atoiswap(const char *n);
void		ft_orderit(long *stk, long *stk2, int dig);
long* 		check_values (int argc, char **argv, long *cad);
long*		ft_checkordered (long *i, int argc);
long* 		ft_convert_int (int argc, char **argv, long *cad);
long*		ft_compare (long *i, int argc);
long*		ft_stacks (int argc,long *stk);
void		ft_printstacks (long *i, long *j, int dig);
void		ft_move(long *stk, long *stk2, int dig, char *cad);
void		ft_swap(long *stk, int dig);
void		ft_push(long *stk, long *stk2, int dig);
void		ft_rotate(long *stk, int dig);
int			ft_findbigger(long *stk, int dig);
int			ft_findsmaller(long *stk, int dig, int func, int buff);
int			ft_findbig(long *stk, int dig, int func, int buff);
char*		ft_ordertree(long *stk, int dig);
void		ft_orderbig(long *stk, long *stk2, int dig, int ord);
void		ft_orderhundred(long *stk, long *stk2, int dig);
void		ft_orderhuge(long *stk, long *stk2, int dig);
void		ft_ra(long *stk, long *stk2, int small, int dig);
void		ft_rra(long *stk, long *stk2, int small, int dig);
void		ft_rb(long *stk, long *stk2, int small, int dig);
void		ft_rrb(long *stk, long *stk2, int small, int dig);
int 		ft_findtop(long *stk, int dig);
int 		ft_find_args(int argc, char *argv);
void		ft_help(void);
int			ft_isdigit(int c);
void		ft_orderstack(long *stk, long *ord, int dig);
long		ft_biggerthan(long *stk, long bigger, int dig);
void		*ft_orderfi (long *stk, long *stk2, int cut, int dig);
void 		ft_rrr (long *stk, long *ord, int top);
void 		ft_rrrl (long *stk, long *ord, int top);
void		*ft_orderrev (long *stk, long *stk2, int cut, int dig);
void		ft_orderleft(long *stk, long *stk2, int dig);
int 		lessmov(int *small,int dig, int cut);
void		ft_orderwait (long *stk, long *stk2, int dig, int cut);
void		ft_orderwaitl (long *stk, long *stk2, int dig, int cut);
int			ft_findbiggerthan(long *stk, int dig, long smaller);
int			ft_findsmallerthan(long *stk, int dig, long bigger);
#endif