/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:18:18 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 15:20:47 by vgodoy           ###   ########.fr       */
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
	ra(decks, 0);
	rb(decks, 0);
	write(1, "rr\n", 3);
}

void	rrr(t_decks *decks)
{
	rra(decks, 0);
	rrb(decks, 0);
	write(1, "rrr\n", 4);
}
