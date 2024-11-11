/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_rb_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:16:09 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 15:13:52 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_decks *decks)
{
	t_card	*b;

	b = decks->deck_b;
	b = swap(b);
	decks->deck_b = b;
	write(1,"sb\n",3);
}

void	rb(t_decks *decks, bool speak)
{
	t_card	*b;

	b = decks->deck_b;
	b = rotate(b);
	decks->deck_b = b;
	if (speak)
		write(1,"rb\n",3);
}

void	rrb(t_decks *decks, bool speak)
{
	t_card	*b;

	b = decks->deck_b;
	b = reverse_rotate(b);
	decks->deck_b = b;
	if (speak)
		write(1,"rrb\n",4);
}
