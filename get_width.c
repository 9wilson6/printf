#include "main.h"
<<<<<<< HEAD
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
=======

/**
 *    get_width - Calculates the width for printing
 *    @format: Formatted string in which to print the arguments.
 *    @i: List of arguments to be printed.
 *    @list: list of arguments.
 *    Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
>>>>>>> b9cd16371fc643f89de947773177c1f437af4182
			break;
		}
		else
			break;
	}
<<<<<<< HEAD

	*i = now - 1;

	return (Count);
=======
	*i = curr_i - 1;

	return (width);
>>>>>>> b9cd16371fc643f89de947773177c1f437af4182
}
