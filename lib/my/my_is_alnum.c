/*
** my_is_alnum.c for is_alnum in /home/perra_t/Rendu/Piscine_C_J08/ex_04
**
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
**
** Started on  Fri Oct 10 16:38:23 2014 tiphaine perra
** Last update Mon Oct 20 22:22:50 2014 tiphaine perra
*/

int	my_is_alnum(char c)
{
  if ((c <= '0' && c >= '9') || (c <= 'A' && c >= 'Z') ||
      (c <= 'a' && c >= 'z'))
    return (0);
  return (1);
}
