/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:54:14 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 10:38:40 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h> //printf

static void		print_tiny()
{
	t_data	*tmp;
	int		total;
	int		find;

	find = 0;
	tmp = pages.tiny;
	while (tmp != NULL)
	{
		if (find == 0 && tmp->is_free == 0)
		{
			printf("TINY:\n");
			find = 1;
		}
		if (tmp->is_free == 0)
			printf("%p - %p : %zu bytes \n", tmp->ptr, tmp->ptr + tmp->size - 1, tmp->size );
		tmp = tmp->next;
	}
}

static void		print_medium()
{
	t_data	*tmp;
	int		total;
	int		find;

	find = 0;
	tmp = pages.medium;
	while (tmp != NULL)
	{
		if (find == 0 && tmp->is_free == 0)
		{
			printf("MEDIUM:\n");
			find = 1;
		}
		if (tmp->is_free == 0)
			printf("%p - %p : %zu bytes \n", tmp->ptr, tmp->ptr + tmp->size - 1, tmp->size );
		tmp = tmp->next;
	}
}

static void		print_big()
{
	t_data	*tmp;
	int		total;
	int		find;

	find = 0;
	tmp = pages.big;
	while (tmp != NULL)
	{
		if (find == 0 && tmp->is_free == 0)
		{
			printf("BIG:\n");
			find = 1;
		}
		if (tmp->is_free == 0)
			printf("%p - %p : %zu bytes \n", tmp->ptr, tmp->ptr + tmp->size - 1, tmp->size );
		tmp = tmp->next;
	}
}

void			show_alloc_mem()
{
	print_tiny();
	print_medium();
	print_big();
}
