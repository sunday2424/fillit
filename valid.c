#include "fillit.h"

int		valid_input()
{
	read(fd,)
}

void	save_if_valid(int alp)
{
	if (alp < 0 || alp >= 26)
		print_error();
}

int		count_blocks(char **map)
{
	int x;
	int y;
	int d;
	int s;

	y = 0;
	d = 0;
	s = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (map[y][x] == '.')
				d++;
			else if (map[y][x] == '#')
				s++;
			else if (map[y][x] != '\n')
				print_error();
			x++;
		}
		y++;
	}
	return ((d == 12 && s == 4) ? 1 : 0);
}