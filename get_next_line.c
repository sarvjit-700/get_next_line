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
			//printf("found new line\n");
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_read(int fd, char *txt)
{
	char	*buff;
	int		num_chars;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	num_chars = 1;
	while ((num_chars = read(fd, buff, BUFFER_SIZE)) >0)
	{
		if (num_chars == -1)
		{
			free(buff);
			free(txt);
			return (NULL);
		}
		buff[num_chars] = '\0';
		txt = ft_append(txt, buff);
	//	printf("txt = %s, buff = %s, num_chars = %d\n", txt, buff, num_chars);
		if (txt == NULL || ft_find_newline(txt) >= 0)
			break;
	}
	free(buff);
	return (txt);
}

char	*ft_keep(char *str)
{
	int	x;
	int	i;
	char	*keep;

	i = 0;
	x = ft_find_newline(str);
	//printf("HERE x= %d and strlen = %ld\n", x, ft_strlen(str));
	if (x == -1 && (ft_strlen(str) == 0))
	{
		//x = ft_strlen(str);
		return (NULL);
	}
	if (x == -1)
		x = ft_strlen(str);
	keep = malloc((x + 2)* sizeof(char));
	if (keep == NULL)
		return NULL;

	while (i <= x)
	{	
		keep[i] = str[i];
		i++;
	}
	keep[i] = '\0';
//	printf("HERE i= %d, should be 1 more than x\n", i);
	return (keep);
}

char	*ft_rest(char *str)
{
	int	x,i,r;
	char	*rest;

	x = ft_find_newline(str);
	if (x == -1)
	{
	//	printf("do something here in REST...............");
		free(str);
		return (NULL);
	}
	//if (x == 0)
	//{
	//	printf(" NOW X = 0\n");
	//	return (NULL);
	//}
	i = 0; 
	r = 0;  // how many chars left
	while (str[x] != '\0' && (x != 0))
	{
		x++;
		r++;
	}
//	printf("HERE in Rest r= %d and x = %d\n", r, x);
	rest = malloc((r+1)* sizeof(char));
	if (rest == NULL)
		return NULL;

	while (i < r)
	{	
		rest[i] = str[x-r+1+i];
		i++;
	}
	rest[i] = '\0';
	free(str);
	printf("rest = %s\n", rest);
	return (rest);
}


char	*get_next_line(int fd)
{
	static char		*txt;
	char	*keep;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = ft_read(fd, txt);
	if (txt == NULL)
	{
		keep = NULL;
		return (keep);
	}
	keep = ft_keep(txt);
//	printf("going to REST keep = %s and txt = %s\n", keep, txt); //print
	txt = ft_rest(txt);
//	printf("after REST keep = %s and txt = %s\n", keep, txt); //print
	return (keep);
}
// should i make the condition if txt or buff is /n and strlen is 1 then print /n and move on