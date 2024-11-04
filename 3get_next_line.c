#include "get_next_line.h"
#include <stdio.h>

char	*ft_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save(char *save)
{
	int		i;
	int		pos;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	pos = 0;
	while (save[i])
		str[pos++] = save[i++];
	str[pos] = '\0';
	free(save);
	return (str);
}

char	*ft_read_save(int fd, char *save)
{
	char	*buff;
	int		num_bytes;
	int		i;

	i = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	num_bytes = 1;
	printf("Buffer size = %d\n", BUFFER_SIZE); //print
	while (!ft_strchr(save, '\n') && num_bytes != 0)
	{
		num_bytes = read(fd, buff, BUFFER_SIZE);
		printf("i is %d and num_bytes %d and save = %s\n", i, num_bytes, save);
		i++;  //print
		if (num_bytes == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[num_bytes] = '\0';
		printf("num bytes = %d and sending to join buff = %s\n", num_bytes, buff);  //print
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_save(fd, save);
	printf("here now and save = %s\n", save); //print
	if (!save)
		return (NULL);
	printf("going to ft_line with %s\n", save); //print
	line = ft_line(save);
	printf("going to ft_save save = %s but line = %s\n", save, line); //print
	save = ft_save(save);
	printf("after ft_save save = %s but line = %s\n", save, line); //print
	return (line);
}