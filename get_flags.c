#include "main.h"

/**
 * get_flags - Calculates no of flags active
 * @format: Formatted string to print the arguments in
 * @i: take a parameter
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, currentIndex;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (currentIndex = *i + 1; format[currentIndex] != '\0'; currentIndex++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		if (format[currentIndex] == FLAGS_CH[j])
		{
			flags |= FLAGS_ARR[j];
			break;
		}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = currentIndex - 1;

	return (flags);
}
