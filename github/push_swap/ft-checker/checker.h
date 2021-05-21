/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:26:10 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/06 19:14:22 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

long int	ft_atoiswap(const char *n);
long* 		check_values (int argc, char **argv, long *cad);
long*		ft_checkordered (long *i, int argc);
long* 		ft_convert_int (int argc, char **argv, long *cad);
long*		ft_compare (long *i, int argc);
long*		ft_stacks (int argc,long *stk);
int			ft_orders(long *stk, long *stk2, int dig);
void		ft_printstacks (long *i, long *j, int dig);
void		ft_move(long *stk, long *stk2, int dig, char *cad);
void		ft_swap(long *stk, int dig);
void		ft_push(long *stk, long *stk2, int dig);
void		ft_rotate(long *stk, int dig);
int 		ft_findtop(long *stk, int dig);
int 		ft_find_args(int argc, char *argv);
void		ft_help(void);
long* 		check_args(int size, char *arg, long *cad);
long* 		ft_convert_arg(int size, char *arg, long *cad);
int			checkchar(char c, int pos);
int			checkorder(char *cad);
#endif