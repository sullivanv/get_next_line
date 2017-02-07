/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <suvitiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:28:38 by suvitiel          #+#    #+#             */
/*   Updated: 2017/02/07 18:56:57 by suvitiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**  Ecrivez une fonction qui retourne une ligne lue depuis un file descriptor.
**  On appelle “ligne” une suite de caractères terminée par un ’\n’ (code ascii 0x0a)
**  ou bien par End Of File (EOF).
*/

static int ft_has_newline(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}

static int ft_read(const int fd, char **line)
{
    char buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;

	tmp = NULL;
	while (ret = read(fd, buf, BUFF_SIZE) > 0)
	{
		buf[ret] = NULL;
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		tmp = NULL;
		if (ft_has_newline(*line) == 1)
			break ;
	}
	return (ret);
}

int get_next_line(const int fd, char **line)
{
    static char *tmp;
	int ret;
	
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ret = ft_read(fd, line);
	if (ret < 0)
		return (-1);
	return (0);
}

/* TODO : rm main */
#include <stdio.h>
int main()
{
    char *line;
	
    line = NULL;
    while (get_next_line(0, &line) > 0)
    {
        printf("%s", line);
        free(line);
        line = NULL;
    }
    printf("%s", line);
    free(line);
    return (0);
}
