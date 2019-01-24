#include <libc.h>

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