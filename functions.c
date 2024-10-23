/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:30:58 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 11:23:03 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*swap(t_card *deck)
{
	t_card	*first;
	t_card	*second;
	t_card	*third;

	if (deck == NULL || deck->next == NULL)
		return (deck);
	first = deck;
	second = deck->next;
	if (second->next == NULL)
	{
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		first->next = NULL;
		return (second);
	}
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	return (second);
}

t_card	*rotate(t_card *deck)
{
	t_card	*first;
	t_card	*second;
	t_card	*last;

	if (deck == NULL || deck->next == NULL)
		return (deck);
	first = deck;
	second = deck->next;
	if (second->next == NULL)
	{
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		first->next = NULL;
		return (second);
	}
	last = second->next;
	while (last->next != NULL)
		last = last->next;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (second);
}
