#include "a_cstring.h"

char *a_strcpy(char *des, const char *src)
{
	if (!des || !src)
		return nullptr;

	char *address = des;

	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';

	return address;
}

size_t a_strlen(const char *src)
{
	if (!src)
		return 0;

	size_t l = 0;

	while (*src != '\0')
	{
		++l;
		++src;
	}

	return l;
}

char *a_strcat(char *des, const char *src)
{
	if (!des)
		return nullptr;
	if (!src)
		return des;

	char *address = des;
	while (*des != '\0')
	{
		des++;
	}

	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';

	return address;
}

int a_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return -2;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 < *s2)
		{
			return -1;
		}
		else if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s1 > *s2)
		{
			return 1;
		}
	}

	if (*s1 == '\0' && *s2 != '\0')
	{
		return -1;
	}
	else if (*s1 == '\0' && *s2 == '\0')
	{
		return 0;
	}
	else if (*s1 != '\0' && *s2 == '\0')
	{
		return 1;
	}
}

size_t a_strnlen_s(const char *src, const size_t max_size)
{
	if (!src)
		return 0;
	size_t len = 0;

	while (*src != '\0' && len < max_size)
	{
		src++;
		len++;
	}
	return len;
}
