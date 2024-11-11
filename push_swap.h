/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:37 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 17:26:20 by vgodoy           ###   ########.fr       */
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
	int				decklen;
	int				cost;
	struct s_card	*tgt;
	struct s_card	*next;
	struct s_card	*prev;
}	t_card;

typedef	struct	s_decks
{
	t_card	*deck_a;
	t_card	*deck_b;
}	t_decks;

t_decks		*create_decks(int argc, char **argv);
bool		test_repetitions(t_card *a);
long long	ft_atol(char *str);

void		show_decks(t_decks	*decks);

void		free_decks(t_decks	*decks);
void		free_deck(t_card *actual_card);

t_card		*swap(t_card *deck);
t_card		*rotate(t_card *deck);
t_card		*reverse_rotate(t_card *deck);

void		sa(t_decks *decks);
void		sb(t_decks *decks);
void		ra(t_decks *decks, bool speak);
void		rb(t_decks *decks, bool speak);
void		rra(t_decks *decks, bool speak);
void		rrb(t_decks *decks, bool speak);

void		pb(t_decks *decks);
void 		pa(t_decks *decks);

void		ss(t_decks *decks);
void		rr(t_decks *decks);
void		rrr(t_decks *decks);

bool		sorted(t_card *a);
void		sort3a(t_decks *decks);
void		sort_under_3(t_decks *decks);

t_card		*find_bigger(t_card *a);
t_card		*find_smaller(t_card *a);

void		deckslen(t_decks *decks);
int			how_long(t_card *a);

void		target_node_a(t_decks	*decks);
int			calculate_cost(t_card *a, t_card *a_tgt);
void		push_cost_a_to_b(t_decks *decks);
void		push_a_to_b(t_decks *decks);

void		target_node_b(t_decks	*decks);
int			calculate_cost2(t_card *b, t_card *b_tgt);
void		push_cost_b_to_a(t_decks *decks);
void		push_b_to_a(t_decks *decks);

void		move_a2(t_decks *decks, t_card *better_choice);

bool		same_side_of_their_median(t_card *better_choice);
int			opti_push_cost(t_card *card);
void		opti_move(t_decks *decks, t_card *better_choice);
#endif
