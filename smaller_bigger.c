/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_bigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:34:32 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/06 16:34:49 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*find_smaller(t_card *a)
{
	t_card	*smaller;

	smaller = a;
	while (a)
	{
		if (a->nbr < smaller->nbr)
			smaller = a;
		a = a->next;
	}
	return (smaller);
}

t_card	*find_bigger(t_card *a)
{
	t_card	*bigger;

	bigger = a;
	while (a->next != 0)
	{
		a = a->next;
		if (a->nbr > bigger->nbr)
			bigger = a;
	}
	return (bigger);
}
