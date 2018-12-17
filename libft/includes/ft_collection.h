/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collection.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:57:15 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 11:14:07 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLLECTION_H
# define FT_COLLECTION_H

typedef struct	s_arlist
{
	size_t		length;
	t_list		*list;
}				t_arlist;

int				al_index_of(t_arlist *al, void *content, size_t content_size);
void			*al_get(t_arlist *al, int i);
int				al_add(t_arlist *al, void *content, size_t content_size);
void			*al_remove(t_arlist *al, int i);
void			al_del(t_arlist **al);

#endif
