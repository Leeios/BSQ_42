#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>

static char	*ft_read(char *filename)
{
	int	fd;
	char	*s;
	char	buf[BUFF_SIZE + 1];
	int	r;

	s = "";
	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Error opening file");
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	return (s);
}


int		main(int ac, char **av)
{
	t_data	m;
	char	*s;

	ft_exit(ac != 2, "usage : ./bsq filename");
	s = ft_read(av[1]);
	parse(s, &m);
	calculus(&m);
	return (0);
}
