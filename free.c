/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 10:40:33 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 10:51:48 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

void	ft_free(void *ptr)
{
	t_data		*tmp;

	tmp = pages.tiny;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 1;
			return ;
		}
	}
	tmp = pages.medium;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 1;
			return ;
		}
	}
	tmp = pages.big;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 1;
			return ;
		}
	}
}