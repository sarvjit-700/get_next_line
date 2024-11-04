/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:36:51 by ssukhija          #+#    #+#             */
/*   Updated: 2024/11/02 13:36:51 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_find_newline(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			printf("newline found \n");  //print
			return (1);
		}
		i++;
	}
	return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_append(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = (char *) malloc((i + j + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_read(int fd, char *txt)
{
	char	*buff;
	int		num_chars;
	int		i;

	i = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	num_chars = 1;
	while (num_chars != 0 && (!ft_find_newline(txt)))
	{
		printf("In while loop\n");  // print
		num_chars = read(fd, buff, BUFFER_SIZE);
		if (num_chars == -1)
		{
			free(buff);
			free(txt);
			return (NULL);
		}
		buff[num_chars] = '\0';
		i++;
		txt = ft_append(txt, buff);
		printf("so far num_chars = %d, buff = %s\n", num_chars, buff); //print
	}
	return (txt);
}



char	*ft_keep(char *txt, int flag)
{
	int	i;
	char	*keep;

	i = 0;
	if (txt == NULL)
		return (0);
	while (txt[i] != '\0')
	{
		if (txt[i] == '\n' && flag == 0)
		{
			printf("newline found - returning 1 \n");  //print
			return (1);
		}
		if (txt[i] == '\n' && flag == 1)
		{
			keep = malloc(i * sizeof(char));
			if (keep == NULL)
				return NULL;
			keep[i] = '\0' // replacing \n with '\0'
			i--;  //to go back from \n which is now '\0'
			while (i > 0)
			{	
				keep[i] = txt[i]
				i--;
			}
			return (keep));
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char		*txt;
	char	*keep;
	int		flag;
	
	flag = 0;
	printf("Buffer size = %d\n", BUFFER_SIZE); // print
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = ft_read(fd, txt);
	if (txt == NULL)
		return (NULL);
	printf("this is stored in txt = %s\n", txt);  //print
	flag = 1;
	printf("going to ft_keep with %s\n", txt); //print
	keep = ft_keep(txt, flag);
	printf("keep = %s and txt = %s\n", keep, txt)

	return (txt);
}
