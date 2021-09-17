#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome
 *
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev;
	unsigned long copy = n;

	rev = 0;

	while (copy != 0)
	{
		rev += copy % 10;
		copy /= 10;
		if (copy != 0)
			rev *= 10;
	}
	if (rev != n)
		return (0);
	return (1);
}
