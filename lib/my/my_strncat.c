/*
** my_strncat.c for  in /home/perra_t/rendu/Piscine_C_J07/ex_01
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Oct  8 10:38:46 2014 tiphaine perra
** Last update Wed Oct  8 14:27:14 2014 tiphaine perra
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;

  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (j < nb && src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i]= ('\0');
  return (dest);
}
