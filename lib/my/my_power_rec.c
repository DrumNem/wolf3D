/*
** my_power_rec.c for  in /home/perra_t/rendu/Piscine_C_J07/lib/my
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Oct  8 13:05:00 2014 tiphaine perra
** Last update Wed Oct  8 13:06:13 2014 tiphaine perra
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  if (power == 1)
    return (nb);
  if (power < 0)
    return (0);
  while (power != 1)
    {
      power = power - 1;
      return (nb * my_power_rec(nb, power));
    }
}
