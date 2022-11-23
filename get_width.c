#include "main.h"
/**
 * get_width - size to print
 * @format: the structure of the input
 * @i: argument to be printed
 * @list: list of arguments
 * Return: width
*/
int get_width(const char *format, int *i, va_list list)
{
	int now;
	int Count = 0;

	for (now = *i + 1; format[now] != '\0'; now++)
	{
		if (is_digit(format[now]))
		{
			Count *= 10;
			Count += format[now] - '0';
		}
		else if (format[now] == '*')
		{
			now++;
			Count = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = now - 1;

	return (Count);
}
