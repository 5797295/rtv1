/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:57:27 by jukim             #+#    #+#             */
/*   Updated: 2018/06/15 21:50:55 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "../lib/Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN 800

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*ball_ptr;
	void		*floor_ptr;
	int			*ball_data;
	int			*floor_data;
	int			bpp;
	int			size_line;
	int			endian;
	double		light[3];
}				t_env;

#endif
