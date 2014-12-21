/*
** my_map.h for  in /home/perra_t/rendu/MUL_2014_wolf3d
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Dec 10 14:25:07 2014 tiphaine perra
** Last update Sun Dec 21 15:26:23 2014 tiphaine perra
*/

#ifndef MY_MAP_
#define MY_MAP_
#define PI 3.14159265359
#define WIN_X   800
#define WIN_Y   600
#define MAP_X   12
#define MAP_Y   10
#define WIN_X   800
#define WIN_Y   600
#define SPD     0.15

extern int      map[MAP_X][MAP_Y];

typedef struct s_list
{
  float		x;
  float		y;
  float		speed;
  float		agl;
  float		d;
  float         mx;
  float         my;
  float         fx;
  float         fy;
  int           x2;
  int		**map;
}		t_list;

typedef struct s_window
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  int		height;
  int		width;
}		t_wi;

typedef struct s_all
{
  t_list	*pos;
  t_wi		*wi;
}		t_all;

#endif
