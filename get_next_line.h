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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
// # include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *new_str, char *s1, char *s2);
char	*ft_append(char *s1, char *s2);

char	*get_next_line(int fd);

#endif