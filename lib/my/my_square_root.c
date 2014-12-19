/*
** my_square_root.c for  in /home/perra_t/rendu/Piscine_C_J07/lib/my
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Oct  8 13:06:47 2014 tiphaine perra
** Last update Wed Oct  8 13:19:16 2014 tiphaine perra
*/

int	my_square_root(int nb)
{
  int	 i;

  i = 2;
  if (nb < 1)
    return (0);
  if (nb == 1)
    return (1);
  while ((i * i) < nb)
    i = i + 1;
  if (i * i != nb)
    return (0);
  return (i);
}
