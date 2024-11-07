/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:18:18 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/07 10:36:55 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_decks *decks)
{
	sa(decks);
	sb(decks);
	write(1, "ss\n", 3);
}

void	rr(t_decks *decks)
{
	ra(decks);
	rb(decks);
	write(1, "rr\n", 3);
}

void	rrr(t_decks *decks)
{
	rra(decks);
	rrb(decks);
	write(1, "rrr\n", 4);
}
