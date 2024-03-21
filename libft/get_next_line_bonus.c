/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:04:38 by sbalasho          #+#    #+#             */
/*   Updated: 2023/03/09 13:04:45 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*get_line(char *stash, int n_pos)
{
	char	*line;
	int		len;

	if (!stash[0])
		return (NULL);
	len = ft_new_strlen(stash);
	if (n_pos >= 0)
	{
		line = ft_new_substr(stash, 0, n_pos + 1);
		return (line);
	}
	else
	{
		line = malloc(ft_new_strlen(stash) * sizeof(char));
		ft_new_strlcpy(line, stash, len + 1);
		return (line);
	}
}

char	*get_tail(char *stash, int n_pos)
{
	char	*tail;
	int		len;

	if (!stash[0] || n_pos < 0 || stash[n_pos + 1] == '\0')
	{
		free (stash);
		return (NULL);
	}
	len = ft_new_strlen(stash);
	if (n_pos >= 0 && (n_pos + 1) < len)
	{
		tail = ft_new_substr(stash, n_pos + 1, len - (n_pos +1));
		free (stash);
		return (tail);
	}
	else
		return (NULL);
}

char	*join_and_free(char *stash, char *buf)
{
	char	*joined;

	joined = ft_new_strjoin(stash, buf);
	free (stash);
	return (joined);
}

char	*read_untill_line(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_count;

	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(stash);
			return (NULL);
		}
		buf[read_count] = '\0';
		stash = join_and_free(stash, buf);
		if (is_a_line(buf) >= 0)
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;
	int			n_pos;

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_untill_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	n_pos = is_a_line(stash[fd]);
	line = get_line(stash[fd], n_pos);
	stash[fd] = get_tail(stash[fd], n_pos);
	return (line);
}
