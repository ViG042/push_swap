/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:18:18 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 19:21:51 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_decks *decks)
{
	sa(decks);
	sb(decks);
}

void	rr(t_decks *decks)
{
	ra(decks);
	rb(decks);
}

void	rrr(t_decks *decks)
{
	rra(decks);
	rrb(decks);
}
