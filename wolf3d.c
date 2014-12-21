/*
** wolf3d.c for  in /home/perra_t/rendu/MUL_2014_wolf3d
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Dec 10 14:40:28 2014 tiphaine perra
** Last update Sun Dec 21 16:22:27 2014 tiphaine perra
*/

#include <mlx.h>
#include <math.h>
#include "my_map.h"

int		map[MAP_X][MAP_Y]=
  {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 1, 2, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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

void		when_wall(t_wi *wi, t_list *po, float x, float y)
{
  float		a;
  float		z;
  float		start_y;
  float		end_y;

  a = po->x;
  z = po->y;
  while (a >= 0 && a < MAP_X && z >= 0 && z < MAP_Y && map[(int)a][(int)z] == 0)
    {
      a += x / 1000;
      z += y / 1000;
    }
  po->d = sqrt(pow(po->x - a, 2) + pow(po->y - z, 2)) /
    sqrt(pow(x, 2) + pow(y, 2));
  if (po->d <= 1.f)
    po->d = 1.f;
  wi->height = WIN_Y / po->d;
  start_y = WIN_Y / 2 - wi->height / 2;
  end_y = start_y + wi->height;
  while (start_y <= end_y)
    if (map[(int)a][(int)z] == 1)
      my_pixel_put_to_image(po->x2, start_y++, wi, 0x6F964F);
    else
      my_pixel_put_to_image(po->x2, start_y++, wi, 0x00F9FF);
}

void		eyes_vect(t_wi *wi, t_list *pos)
{
  float		x;
  float		y;

  color_win(wi);
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
