#include "bsq.h"
#include <unistd.h>

static void	ft_putchar(char c)
{
	if (write(1, &c, 1) < 0)
		return ;
}

static void	print_map(t_data *m, int *solve)
{
	int i, j;
	i = j = -1;

	while (++i < m->size[1])
	{
		j = -1;
		while (++j < m->size[0])
		{
			if (i >= solve[0] && i < solve[0] + solve[2]
				&& j >= solve[1] && j < solve[1] + solve[2])
				ft_putchar(m->symbols[2]);
			else if (m->map[i][j])
				ft_putchar(m->symbols[1]);
			else
				ft_putchar(m->symbols[0]);
		}
		ft_putchar('\n');
	}
}

static int	area_square(t_data *m, int i, int j, int res)
{
	int	n;

	n = -1;
	while (++n <= res)
	{
		if (m->map[i + res][j + n] || m->map[i + n][j + res])
			return(1);
	}
	return (0);
}

static int	count_square(t_data *m, int i, int j)
{
	int	res;

	res = 1;
	if (m->map[i][j])
		return (0);
	while (j + res < m->size[0] && i + res < m->size[1]
		&& !area_square(m, i, j, res))
		res++;
	return (res);
}

void	calculus(t_data *m)
{
	int	i;
	int	j;
	int	tmp;
	int	max[3];

	i = -1;
	max[0] = max[1] = max[2] = 0;
	while (++i < m->size[1])
	{
		j = -1;
		while (++j < m->size[0])
		{
			if ((tmp = count_square(m, i, j)) > max[2])
			{
				max[0] = i;
				max[1] = j;
				max[2] = tmp;
			}
		}
	}
	print_map(m, max);
}
