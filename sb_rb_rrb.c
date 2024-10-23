/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_rb_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:16:09 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 19:17:24 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_decks *decks)
{
	t_card	*b;

	b = decks->deck_b;
	b = swap(b);
	decks->deck_b = b;
}

void	rb(t_decks *decks)
{
	t_card	*b;

	b = decks->deck_b;
	b = rotate(b);
	decks->deck_b = b;
}

void	rrb(t_decks *decks)
{
	t_card	*b;

	b = decks->deck_b;
	b = reverse_rotate(b);
	decks->deck_b = b;
}
