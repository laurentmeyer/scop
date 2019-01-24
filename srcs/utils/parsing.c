#include <libc.h>

// size_t		ft_countwords(char const *s, char c)
// {
// 	if (c == '\0')
// 		return ((*s == '\0') ? 0 : 1);
// 	while (*s == c)
// 		s++;
// 	if (*s == '\0')
// 		return (0);
// 	while (*s != c && *s != '\0')
// 		s++;
// 	return (1 + ft_countwords(s, c));
// }

int		first_word_is(char *s, char *word)
{
	size_t	i;

	i = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	while (s[i] != 0 && s[i] != ' ' && s[i] != '\t')
		i++;
	return (strncmp(s, word, i) == 0);
}

// char		**ft_strsplit(char const *s, char c)
// {
// 	char	**arr;
// 	int		i;
// 	int		j;
// 	int		w;

// 	w = ft_countwords(s, c);
// 	if ((arr = (char **)malloc((w + 1) * sizeof(char *))))
// 	{
// 		i = 0;
// 		while (i < w)
// 		{
// 			while (*s == c)
// 				++s;
// 			j = 0;
// 			while (*(s + j) != '\0' && *(s + j) != c)
// 				++j;
// 			if ((arr[i] = ft_strnew(j)))
// 				ft_strncpy(arr[i++], s, j);
// 			s += j;
// 		}
// 		arr[i] = 0;
// 	}
// 	return (arr);
// }

// void	ft_free_strsplit(char ***to_free)
// {
// 	char	**as;
// 	int		i;

// 	i = 0;
// 	while (*(as = *to_free + i++))
// 		ft_strdel(as);
// 	free(*to_free);
// }