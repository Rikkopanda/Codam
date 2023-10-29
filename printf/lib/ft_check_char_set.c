
#include "libft.h"

int check_char_set(char chr, char *set)
{
	int cnt;

	cnt = 0;
	while(*set != '\0')
	{
		if(*set == chr)
			cnt++;
		set++;
	}
	return (cnt);
}
// checks whole set if chr matches
