/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:24:45 by ssukhija          #+#    #+#             */
/*   Updated: 2024/11/02 13:24:45 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 10
// # endif

// # include <fcntl.h>
// # include <stdlib.h>
// # include <unistd.h>

// typedef struct s_list
// {
// 	char	*str_buf;
// 	struct	s_list	*next;
// 		t_list;
// }

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

/* auxiliary functions */
// char	*ft_strchr(char *str, int c);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(char *str);


//mine
size_t			ft_strlen(const char *s);
char	*ft_append(char *s1, char *s2);
int		ft_find_newline(const char *str);
char	*ft_keep(char *txt, int flag);

/* main function */
char	*get_next_line(int fd);

#endif