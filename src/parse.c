#include "bsq.h"

static void	ft_init_map(t_data *m)
{
	int	i;

	i = -1;
	ft_exit((m->map = (int **)malloc(sizeof(int *) * m->size[1])) == NULL
		, "malloc error");
	while (++i < m->size[1])
		ft_exit((m->map[i] = (int *)malloc(sizeof(int) * m->size[0])) == NULL
			, "malloc error");
}

static int	check_map(t_data *m, char **s, int *i, int *j)
{
	ft_exit(((**s == '\n' && *j != m->size[0]) || (**s != '\n' && *j == m->size[0]))
		, "map error");
	if (**s == '\n')
	{
		(*i)++;
		(*s)++;
		*j = 0;
	}
	if (*i >= m->size[1] || !(**s) || **s == '\n')
		return (1);
	ft_exit(!(ISVALID(**s)), "map error");
	return (0);
}

static void	convert_map(char *s, t_data *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_map(m);
	while (*s)
	{
		if (check_map(m, &s, &i, &j))
			return ;
		if (*s == m->symbols[0])
			m->map[i][j] = EMPTY;
		else if (*s == m->symbols[1])
			m->map[i][j] = FULL;
		j++;
		s++;
	}
}

void		parse(char *s, t_data *m)
{
	m->size[0] = 0;
	ft_exit(!ISNBR(s[0]), "map error");
	m->size[1] = ft_uatoi(&s);
	ft_exit(!s[0] || !s[1] || !s[2] || s[3] != '\n', "map error");
	m->symbols[0] = s[0];
	m->symbols[1] = s[1];
	m->symbols[2] = s[2];
	s += 4;
	while (s[m->size[0]] && s[m->size[0]] != '\n')
		m->size[0]++;
	convert_map(s, m);
}
