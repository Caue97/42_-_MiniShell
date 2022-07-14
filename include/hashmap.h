/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:06:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/07/13 15:17:36 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "minishell.h"

/*
** Structs definitions
*/

typedef struct s_hashlist {
	char				*key;
	char				*value;
	int					att;
	struct s_hashlist	*next;
}	t_hashlist;

typedef struct s_hashtable {
	t_hashlist	**list;
	size_t		size;
	size_t		count;
}	t_hashtable;

/*
** Environment variables list
*/

char		*get_key(char *variable);
char		*get_value(char *variable);

/*
** Hashmap initialization
*/

t_hashtable	*init_hashtable(void);
void		populate_hashmap(char **variables);
void		delete_hashmap(void);

/*
** Hashmap functions
*/

int			hash(char *key, size_t size);

/*
** Hashmap variable management
*/

void		hash_insert(char *key, char *value, int att);
void		hash_substitute(char *key, char *value);
void		hash_remove(char *key);
void		hash_export(char *key, int new_att);
int			key_location(char *key);
char		*key_search(char *key);

#endif