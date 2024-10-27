/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:23:56 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/27 16:59:14 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_decks	*decks;

	decks = create_decks(argc, argv);
	if (!decks)
		return (-1);
	deckslen(decks); show_decks(decks);

	pb(decks); printf("pb\n"); deckslen(decks); show_decks(decks);
	pb(decks); printf("pb\n"); deckslen(decks); show_decks(decks);
	
	target_node_a(decks); show_decks(decks);

	push_cost_a_to_b(decks); show_decks(decks);

	free_decks(decks);
	return (0);
}


/*	
	decks->deck_a = sort3(decks->deck_a);
	
	show_decks(decks);

	free_decks(decks);
	return (0);
}
*/


/*
	int	i;
	for (i=0; i<7 ; i++)
	{
	pb(decks); printf("pb\n"); show_decks(decks);
	}

	sa(decks); printf("sa\n"); show_decks(decks);
	sb(decks); printf("sb\n"); show_decks(decks);
	ss(decks); printf("ss\n"); show_decks(decks);

	ra(decks); printf("ra\n"); show_decks(decks);
	rb(decks); printf("rb\n"); show_decks(decks);
	rr(decks); printf("rr\n"); show_decks(decks);

	rra(decks); printf("rra\n"); show_decks(decks);
	rrb(decks); printf("rrb\n"); show_decks(decks);
	rrr(decks); printf("rrr\n"); show_decks(decks);

	for (i=0; i<3 ; i++)
	{
	pa(decks); printf("pa\n"); show_decks(decks);
	}

	sa(decks); printf("sa\n"); show_decks(decks);
	sb(decks); printf("sb\n"); show_decks(decks);
	ss(decks); printf("ss\n"); show_decks(decks);

	ra(decks); printf("ra\n"); show_decks(decks);
	rb(decks); printf("rb\n"); show_decks(decks);
	rr(decks); printf("rr\n"); show_decks(decks);

	rra(decks); printf("rra\n"); show_decks(decks);
	rrb(decks); printf("rrb\n"); show_decks(decks);
	rrr(decks); printf("rrr\n"); show_decks(decks);

	for (i=0; i<4 ; i++)
	{
	pa(decks); printf("pa\n"); show_decks(decks);
	}

	sa(decks); printf("sa\n"); show_decks(decks);
	sb(decks); printf("sb\n"); show_decks(decks);
	ss(decks); printf("ss\n"); show_decks(decks);

	ra(decks); printf("ra\n"); show_decks(decks);
	rb(decks); printf("rb\n"); show_decks(decks);
	rr(decks); printf("rr\n"); show_decks(decks);

	rra(decks); printf("rra\n"); show_decks(decks);
	rrb(decks); printf("rrb\n"); show_decks(decks);
	rrr(decks); printf("rrr\n"); show_decks(decks);

	for (i=0; i<3 ; i++)
	{
	pa(decks); printf("pa\n"); show_decks(decks);
	}

	rrr(decks); printf("rrr\n"); show_decks(decks);
	rrr(decks); printf("rrr\n"); show_decks(decks);

	for (i=0; i<3 ; i++)
	{
		pb(decks); printf("pb\n"); show_decks(decks);
	}
	rrr(decks); printf("rrr\n"); show_decks(decks);
	rrr(decks); printf("rrr\n"); show_decks(decks);
	rrr(decks); printf("rrr\n"); show_decks(decks);

	free_decks(decks);
	return (0);
}
*/
