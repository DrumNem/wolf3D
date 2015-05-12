/*
** main.c for  in /home/perra_t/rendu/MUL_2014_wolf3d/include
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Fri Dec 19 18:01:22 2014 tiphaine perra
** Last update Tue May 12 17:07:48 2015 tiphaine perra
*/

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "my_map.h"

void		color_win(t_wi *wi)
{
  int		x;
  int		y;

  x = 0;
  while (x <= WIN_X)
    {
      y = 0;
      while (y <= WIN_Y)
	{
	  if (y <= WIN_Y / 2)
	    my_pixel_put_to_image(x, y, wi, 0x87CEFA);
	  if (y >= WIN_Y / 2 && y <= WIN_Y)
	    my_pixel_put_to_image(x, y, wi, 0x3A9D23);
	  y++;
	}
      x++;
    }
}

//gestion des touches directionnelles, et [echap]

int		gere_key2(int keycode, t_all *all)
{
  if (keycode == 65361)
    {
      all->pos->agl += 0.2;
      eyes_vect(all->wi, all->pos);
    }
  if (keycode == 65363)
    {
      all->pos->agl -= 0.2;
      eyes_vect(all->wi, all->pos);
    }
  if (keycode == 65362 && map[(int)(all->pos->x + cos(all->pos->agl) * SPD)]
      [(int)(all->pos->y + sin(all->pos->agl) * SPD)] == 2)
    {
      my_printf("Tadaaaaaaaaaam !! :3 \n");
      exit(1);
    }
  return (0);
}

int		gere_key(int keycode, t_all *all)
{
  if (keycode == 65362 &&
      map[(int)(all->pos->x + cos(all->pos->agl) * SPD)]
      [(int)(all->pos->y + sin(all->pos->agl) * SPD)] == 0)
    {
      all->pos->y += sin(all->pos->agl) * SPD;
      all->pos->x += cos(all->pos->agl) * SPD;
      eyes_vect(all->wi, all->pos);
    }
  if (keycode == 65364 &&
      map[(int)(all->pos->x - cos(all->pos->agl) * SPD)]
      [(int)(all->pos->y - sin(all->pos->agl) * SPD)] == 0)
    {
      all->pos->y -= sin(all->pos->agl) * SPD;
      all->pos->x -= cos(all->pos->agl) * SPD;
      eyes_vect(all->wi, all->pos);
    }
  if (keycode == 65307)
    exit(1);
  gere_key2(keycode, all);
  return (0);
}

int             gere_expose(t_wi *wi)
{
  mlx_put_image_to_window(wi->mlx_ptr, wi->win_ptr, wi->img_ptr, 0, 0);
  return (1);
}

int		main()
{
  t_list	*pos;
  t_wi          *wi;
  t_all		*all;

  if ((all = malloc(sizeof(t_all))) == NULL ||
      (pos = malloc(sizeof(t_list))) == NULL ||
      (wi = malloc(sizeof(t_wi))) == NULL ||
      (wi->mlx_ptr = mlx_init()) == NULL)
    return (0);
  all->pos = pos;
  all->wi = wi;
  pos->agl= 35 * (PI / 180);
  pos->x = 2.30;
  pos->y = 2.30;
  pos->fx = pos->x;
  pos->fy = pos->y;
  wi->win_ptr = mlx_new_window(wi->mlx_ptr, WIN_X, WIN_Y, "Wofl3D");
  wi->img_ptr = mlx_new_image(wi->mlx_ptr, WIN_X, WIN_Y);
  eyes_vect(wi, pos);
  mlx_expose_hook(wi->win_ptr, &gere_expose, wi);
  mlx_key_hook(all->wi->win_ptr, gere_key, all);
  mlx_loop(wi->mlx_ptr);
  return (0);
}
