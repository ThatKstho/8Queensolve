/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8queen2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:55:01 by ohachim           #+#    #+#             */
/*   Updated: 2018/11/17 14:55:11 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int ft_nqueen(char **board, int size)
{
	int x;
	int y;
	int queen;

	queen = 0;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (board[x][y] == '1')
				queen++;
			y++;
		}
		x++;
	}
	if (queen == size)
		return (1);
	return (0);
}

int ft_checkv(char **board, int y)
{
	int x;

	x = 0;
	while (x < 8)
	{
		if (board[x][y] == '1')
			return (0);
		x++;
	}
	return (1);
}

int ft_checkdir(char **board, int x, int y)
{
	int d_x;
	int d_y;
	int size;

	size = 8;
	if (x + y >= size)
	{
		d_y = 7;
		d_x = (x + y) - (size - 1);
	}
	else
	{
		d_y = x + y;
		d_x = 0;
	}
	while (d_y >= 0 && d_x < size)
	{
		if (board[d_x][d_y] == '1')
			return (0);
		d_y--;
		d_x++;
	}
	return (1);
}

int ft_checkdil(char **board, int x, int y)
{
	int d_x;
	int d_y;
	int size = 8;

	if (x - y >= 0)
	{
		d_x = x - y;
		d_y = 0;
	}
	else
	{
		d_x = 0;
		d_y = -(x - y);
	}
	while (d_x < size && d_y < size)
	{
		if (board[d_x][d_y] == '1')
			return (0);
		d_x++;
		d_y++;
	}
	return (1);
}

int ft_checkh(char *str)
{
	int cn;

	cn = 0;
	while (cn < 8)
	{
		if (str[cn] == '1')
			return (0);
		cn++;
	}
	return (1);
}

int ft_checkers(char **board, int x, int y)
{
	if (ft_checkh(board[x]) && ft_checkdil(board, x, y) && ft_checkv(board, y) && ft_checkdir(board, x, y))
		return (1);
	return (0);
}

int ft_sqrt(unsigned int n)
{
	unsigned int sqr;

	sqr = 1;
	while (sqr <= n / 2)
	{
		if ((sqr * sqr) == n)
			return (sqr);
		sqr++;
	}
	return (0);
}

char **ft_setboard(char **board, unsigned int bsize)
{
	unsigned int sqr;
	unsigned int y;
	unsigned int x;

	x = 0;
	sqr = ft_sqrt(bsize);
	board = (char **)malloc(sizeof(char *) * (sqr + 1));
	board[sqr] = 0;
	while (x < sqr)
	{
		board[x] = (char *)malloc(sqr + 1);
		y = 0;
		while (y < sqr)
		{
			board[x][y] = '0';
			y++;
		}
		board[x][y] = '\0';
		x++;
	}
	return (board);
}

int ft_setqueens(char **board, unsigned int size, int x, int y)
{
	static int solutions;
	int e;

	e = 0;
	while (y < (int)size)
	{
		if (ft_checkers(board, x, y))
		{
			board[x][y] = '1';
			if (x + 1 < (int)size)
			{
				ft_setqueens(board, size, x + 1, 0);
			}
			if (ft_nqueen(board, size))
			{
				sleep(1);
				system("clear");
				solutions++;
				ft_putnbr(solutions);
				ft_putstr("\n");
				while (board[e])
				{
					ft_putstr(board[e]);
					ft_putchar('\n');
					e++;
				}
				ft_putstr("\n\n");
			}
		}
		board[x][y] = '0';
		y++;
	}
	return (solutions);
}

int main(void)
{
	char **board;

	board = NULL;
	board = ft_setboard(board, 64);
	ft_putnbr(ft_setqueens(board, 8, 0, 0));
}
