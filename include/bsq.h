#ifndef BSQ_H
#define BSQ_H

#define BUFF_SIZE 1023
#define ISNBR(n) (n >= '0' && n <= '9')
#define ISVALID(n) (n == m->symbols[0] || n == m->symbols[1])
#define EMPTY 0
#define FULL 1

# include <stdlib.h>

#include <stdio.h>

typedef struct	s_data
{
	int	**map;
	int	size[2];
	char	symbols[3];
}		t_data;

/*
**PARSE
*/
void	parse(char *s, t_data *m);

/*
**CALCULUS
*/
void	calculus(t_data *m);

/*
**LIBFT
*/
void	ft_putstr_fd(char *s, int fd);
void	ft_exit(int test, char *s);
char	*ft_strjoin(char *s, char *t);
int	ft_uatoi(char **nbr);

#endif
