/*
** my_strcat.c for  in /home/perra_t/rendu/Piscine_C_J07/ex_01
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Wed Oct  8 09:13:41 2014 tiphaine perra
** Last update Wed Oct  8 15:53:17 2014 tiphaine perra
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
