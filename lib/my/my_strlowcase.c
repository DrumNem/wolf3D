/*
** my_strlowcase.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_08
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 19:31:21 2014 tiphaine perra
** Last update Tue Oct  7 19:44:24 2014 tiphaine perra
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'z')
	str[i] = str[i] + ('a' - 'A');
      i = i + 1;
    }
  return (str);
}
