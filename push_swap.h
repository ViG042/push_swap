/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:37 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 11:39:59 by vgodoy           ###   ########.fr       */
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

void	free_deck(t_card *card);
t_card	*create_deck(int argc, char **argv);
t_card	*swap(t_card *deck);
t_card	*rotate(t_card *deck);
void	putnbr(long nb);

#endif
