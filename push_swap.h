/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:37 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/26 16:44:53 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_card
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_card	*target_card;
	struct s_card	*next;
	struct s_card	*prev;
}	t_card;

typedef	struct	s_decks
{
	t_card	*deck_a;
	t_card	*deck_b;
}	t_decks;

t_decks	*create_decks(int argc, char **argv);

void	show_decks(t_decks	*decks);

void	free_decks(t_decks	*decks);
void	free_deck(t_card *actual_card);

t_card	*swap(t_card *deck);
t_card	*rotate(t_card *deck);
t_card	*reverse_rotate(t_card *deck);

void	sa(t_decks *decks);
void	sb(t_decks *decks);
void	ra(t_decks *decks);
void	rb(t_decks *decks);
void	rra(t_decks *decks);
void	rrb(t_decks *decks);

void	pb(t_decks *decks);
void 	pa(t_decks *decks);

void	ss(t_decks *decks);
void	rr(t_decks *decks);
void	rrr(t_decks *decks);

t_card	*sort3(t_card *a);

#endif
