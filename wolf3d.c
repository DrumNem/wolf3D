/*
** wolf3d.c for  in /home/perra_t/rendu/MUL_2014_wolf3d
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Dec 10 14:40:28 2014 tiphaine perra
** Last update Fri Dec 19 17:56:01 2014 tiphaine perra
*/

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_map.h"
#define	WIN_X	800
#define	WIN_Y	600

int		map[8][8]=
  {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
  };

void		my_pixel_put_to_image(int x, int y, t_wi *wi, int color)
{
  int		bpp;
  int		size_line;
  int		endian;
  int		*data;
  int		i;

  data = (int *)mlx_get_data_addr(wi->img_ptr, &bpp, &size_line, &endian);
  if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
    {
      i = WIN_X * y + x;
      data[i] = color;
    }
}

int		gere_expose(t_wi *wi)
{
  mlx_put_image_to_window(wi->mlx_ptr, wi->win_ptr, wi->img_ptr, 0, 0);
  return (1);
}

void		when_wall(t_wi *wi, t_list *po, float x, float y)
{
  float		a;
  float		z;
  float		start_y;
  float		end_y;

  a = po->x;
  z = po->y;
  while (a >= 0 && a < 8 && z >= 0 && z < 8 && map[(int)a][(int)z] != 1)
    {
      a += x / 1000;
      z += y / 1000;
    }
  po->d = sqrt(pow(po->x - a, 2) + pow(po->y - z, 2));
  wi->height = WIN_Y / po->d;
  start_y = WIN_Y / 2 - wi->height / 2;
  end_y = start_y + wi->height;
  while (start_y <= end_y)
    my_pixel_put_to_image(po->x2, start_y++, wi, 0x00FFFFFF);
}

void		eyes_vect(t_wi *wi, t_list *pos)
{
  float		x;
  float		y;

  pos->x2 = 0;
  while (pos->x2++ <= WIN_X)
    {
      pos->mx = 1;
      pos->my = 1.f * (WIN_X / 2 - pos->x2) / WIN_X;
      x = pos->mx * cos(pos->agl) - pos->my * sin(pos->agl);
      y = pos->mx * sin(pos->agl) + pos->my * cos(pos->agl);
      when_wall(wi, pos, x, y);
    }
  mlx_put_image_to_window(wi->mlx_ptr, wi->win_ptr, wi->img_ptr, 0, 0);
}

int		main()
{
  t_list	*pos;
  t_wi		*wi;

  if ((pos = malloc(sizeof(t_list))) == NULL)
    return (0);
  if ((wi = malloc(sizeof(t_wi))) == NULL)
    return (0);
  wi->mlx_ptr = mlx_init();
  if (wi->mlx_ptr == NULL)
    return (0);
 pos->agl= 35 * (PI / 180);
 pos->x = 1.5;
 pos->y = 1.5;
 pos->fx = pos->x;
 pos->fy = pos->y;
 wi->win_ptr = mlx_new_window(wi->mlx_ptr, WIN_X, WIN_Y, "Wofl3D");
 wi->img_ptr = mlx_new_image(wi->mlx_ptr, WIN_X, WIN_Y);
 eyes_vect(wi, pos);
 mlx_expose_hook(wi->win_ptr, &gere_expose, wi);
 mlx_loop(wi->mlx_ptr);
 return (0);
}
