#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void		ft_exit(int test, char *s)
{
	if (!test)
		return ;
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

static int	ft_strlen(char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (!s || write(fd, s, ft_strlen(s)) < 0)
		return ;
}

char	*ft_strjoin(char *s, char *t)
{
	char	*res;
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(s) + ft_strlen(t);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
	{
		if (*s)
		{
			res[i] = *s;
			s++;
		}
		else if (*t)
		{
			res[i] = *t;
			t++;
		}
		else
			res[i] = '\0';
	}
	return (res);
}

int	ft_uatoi(char **nbr)
{
	int	res;

	res = 0;
	while (**nbr && ISNBR(**nbr))
	{
		res = **nbr - '0' + res * 10;
		(*nbr)++;
	}
	return (res);
}
