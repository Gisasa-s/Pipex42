#include "ft_pipex.h"



char	*ft_strdup(char const *str)
{
	char	*cpy;
	int		i;
	i = 0;
	if (!str)
		return (NULL);
	cpy = malloc(sizeof(*cpy) * (ft_strlen(str) + 1));
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int a;

	i = 0;
	a = 0;
	while ((unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0'
			&& i < n && a == 0)
	{
		a += (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (a == 0 && i < n)
		a = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (a);
}
static int	pos_word(char *s, char c, unsigned int order)
{
	int				is_word;
	unsigned int	cnt;
	unsigned int	pos;

	is_word = 0;
	cnt = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (is_word == 0 && s[pos] != c)
		{
			cnt++;
			if (cnt == order + 1)
				break ;
			is_word = 1;
		}
		else if (is_word == 1 && s[pos] == c)
			is_word = 0;
		pos++;
	}
	return (pos);
}

static int	count_words(char *s, char c)
{
	int				is_word;
	unsigned int	cnt;

	cnt = 0;
	is_word = 0;
	while (*s != '\0')
	{
		if (is_word == 0 && *s != c)
		{
			cnt++;
			is_word = 1;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (cnt);
}

static char	*assign_word(char *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	nb;
	unsigned int	i;
	char			**str;
	char			*ptr;

	if (!s)
		return (0);
	ptr = (char *)s;
	nb = count_words(ptr, c);
	str = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < nb)
	{
		str[i] = assign_word(ptr + pos_word(ptr, c, i), c);
		i++;
	}
	str[i] = 0;
	return (str);
}