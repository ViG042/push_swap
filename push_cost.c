/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:09:18 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/27 17:17:28 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_b_cost(int push_cost, int b_index, int b_decklen)
{
	if (b_index < b_decklen / 2)
		push_cost = push_cost + b_index;
	else
		push_cost = push_cost + (b_decklen - b_index + 1);
	return (push_cost);
}

int	calculate_push_cost_method_a(t_card *a, t_card *b)
{
	int	push_cost;
	int	b_index;

	if (a->index <= a->decklen / 2)
	{
														printf("index <= medianne\n");
		push_cost = a->index;
														printf("   [%d] cost = [%d]\n", a->nbr, push_cost);
		b_index = b->index - push_cost;
		if (b_index < 0)
			b_index = b_index + b->decklen;
														printf("        b_index = [%d]\n", b_index);
		push_cost = add_b_cost(push_cost, b_index, b->decklen);
	}
	else
	{
														printf("index > medianne\n");
		push_cost = a->decklen - a->index + 1;
														printf("   [%d] cost = [%d]\n", a->nbr, push_cost);
		b_index = b->index + push_cost;
		if (b_index >= b->decklen)
			b_index = b_index - b->decklen;
														printf("        b_index = [%d]\n", b_index);
		push_cost = add_b_cost(push_cost, b_index, b->decklen);
	}
														printf("        a + b cost = [%d]\n", push_cost);
	return (push_cost);
}

//int	calculate_push_cost_method_a()
//int	calculate_push_cost_method_a()

void	set_push_cost(t_card *a)
{
	int	push_cost;

	push_cost = calculate_push_cost_method_a(a, a->tgt);
	a->cost = push_cost;
	a->method = 'a';
//	push_cost = calculate_push_cost_method_b();
//	if (push_cost < a->cost)
//	{
//		a->cost = push_cost;
//		a->method = 'b';
//	}
//	push_cost = calculate_push_cost_method_c();
//	if (push_cost < a->cost)
//	{
//		a->cost = push_cost;
//		a->method = 'c';
//	}
}

void	push_cost_a_to_b(t_decks *decks)
{
	t_card	*a;

	a = decks->deck_a;
	while (a)
	{
		set_push_cost(a);
		a = a->next;
	}
}
