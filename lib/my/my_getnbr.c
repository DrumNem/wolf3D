/*
** my_getnbr.c for  in /home/perra_t/rendu/Piscine_C_J07/lib/my
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Oct  8 12:48:52 2014 tiphaine perra
** Last update Mon Oct 20 19:52:23 2014 tiphaine perra
*/
int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	sgn;
  int	lim;

  i = 0;
  nbr = 0;
  sgn = 1;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sgn = sgn * -1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr  + (str[i] - '0');
      i = i + 1;
    }
  return (nbr * (sgn));
}
