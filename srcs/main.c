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

double dot(double *x, double *y)
{
	double d;
   
	d = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
//	printf("1 = %f	2 = %f	3 = %f\n", x[0] * y[0], x[1] * y[1], x[2] * y[2]);
//	printf("%f\n", d);
	return d > 0 ? -d : 0;
}

void	normalize(double *v)
{
	double len;

	len = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] /= len;
	v[1] /= len;
	v[2] /= len;
}

int		main(void)
{
	t_env	e;
	int		radius;
	double	x;
	double	y;
	double	z;
	double	b;
	double	k;
	double	a;
	double	r;
	double	vec[3];
	int		i;
	int		y0;
	float	c;

	ft_bzero(&e, sizeof(t_env));
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIN, WIN, "RTv1");
	e.ball_ptr = mlx_new_image(e.mlx_ptr, WIN, WIN);
	e.ball_data = (int*)mlx_get_data_addr(e.ball_ptr, &e.bpp, &e.size_line,
			&e.endian);
	mlx_hook(e.win_ptr, 2, 2, rtv1_key, &e);
	mlx_hook(e.win_ptr, 17, 0, rtv1_exit, &e);
	radius = 0;
	i = -1;
	k = 0;
	y = 0;
	x = 0;
	z = 0;
	c = 0;
	a = 0.1;
	y0 = 0;
	e.light[0] = 30;
	e.light[1] = 30;
	e.light[2] = -50;
	normalize(e.light);
	while (++i < WIN * WIN)
	{
/*		if (i % WIN == 0)
		{
			x = 0;
			y++;
		}
		if (5 * x + 2.5 * y + 2.5 * z*/
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
		r = (x - WIN / 2) * (x - WIN / 2) + (y - WIN / 2) * (y - WIN / 2);
		if (r <= 150 * 150)
		{
			z = sqrt(150 * 150 - (x - WIN / 2) * (x - WIN / 2) - (y - WIN / 2) * (y - WIN / 2));
			vec[0] = x;
			vec[1] = y;
			vec[2] = z;
			b = dot(e.light, vec);
			e.ball_data[i] = rgb((int)(b - 50), 0, 0);
		}
		x++;
	}
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.ball_ptr, 0, 0);
	mlx_loop(e.mlx_ptr);
	return (0);
}
