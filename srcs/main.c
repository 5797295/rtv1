/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 20:32:12 by jukim             #+#    #+#             */
/*   Updated: 2018/06/16 15:56:36 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		rtv1_exit(t_env *e)
{
	if (e->ball_ptr)
		mlx_destroy_image(e->mlx_ptr, e->ball_ptr);
//	if (e->floor_ptr)
//		mlx_destroy_image(e->mlx_ptr, e->floor_ptr);
	if (e->win_ptr)
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(0);
}

int		rtv1_key(int key, t_env *e)
{
	if (key == 53)
		rtv1_exit(e);
	return (0);
}

int		main(void)
{
	t_env	e;
	int		radius;
	int		x;
	int		y;
	int		i;
	int		y0;
	float	c;

	ft_bzero(&e, sizeof(t_env));
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIN, WIN, "RTv1");
	e.ball_ptr = mlx_new_image(e.mlx_ptr, WIN, WIN);
	e.ball_data = (int*)mlx_get_data_addr(e.ball_ptr, &e.bpp, &e.size_line,
			&e.endian);
//	e.floor_ptr = mlx_new_image(e.mlx_ptr, WIN, WIN);
//	e.floor_data = (int*)mlx_get_data_addr(e.floor_ptr, &e.bpp, &e.size_line,
//			&e.endian);
	mlx_hook(e.win_ptr, 2, 2, rtv1_key, &e);
	mlx_hook(e.win_ptr, 17, 0, rtv1_exit, &e);
	radius = 0;
	i = -1;
	y = 0;
	x = 0;
	c = 0;
	y0 = 0;
	while (++i < WIN * WIN)
	{
		if (i >= WIN * WIN / 2)
		{
			e.ball_data[i] = rgb((int)(c), (int)(c), 0);
			if ((i + 1) % WIN == 0)
				c += 0.63;
		}
	}
	i = -1;
	c = 0;
	while (++i < WIN * WIN)
	{
		if (i % WIN == 0)
		{
			x = 0;
			y++;
		}
		if (sqrt((x - WIN / 2) * (x - WIN / 2) +
					(y - WIN / 2) * (y - WIN / 2)) <= 150)
		{
			if (c == 0)
				y0 = y;
//			e.ball_data[i] = rgb((int)(255 - c), 0, 0);
			e.ball_data[i] = rgb((int)(255 - c), 0, c);
//			printf("c = %f	y0 = %d	y = %d\n", c, y0, y);
			c = (float)((y - y0 + 1) * 0.85);
		}
		x++;
	}
//	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.floor_ptr, 0, 0);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.ball_ptr, 0, 0);
	mlx_loop(e.mlx_ptr);
	return (0);
}
