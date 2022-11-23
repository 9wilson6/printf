#include "main.h"

/**
 * handle_write_char - handles char input
 * @c: the input tobe printed
 * @flags: to handle unique cases
 * @width: the size of input
 * @precision: the accuracy requred
 * @buffer: buffer
 * @size: ..
 * Return: int
*/
int handle_write_char(char c, char buffer[],
					  int flags, int width, int precision, int size)
{
	int cnt = 0;
	char hold = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		hold = '0';

	buffer[cnt++] = c;
	buffer[cnt] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (cnt = 0; cnt < width - 1; cnt++)
			buffer[BUFF_SIZE - cnt - 2] = hold;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - cnt - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - cnt - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - print number
 * @is_negative: check if negative
 * @ind: types
 * @buffer: buffer
 * @width: width
 * @precision: accuracy
 * @size: size
 * @flags: change flags
 * Return: int
*/

int write_number(int is_negative, int ind, char buffer[],
				 int flags, int width, int precision, int size)
{
	int Size = BUFF_SIZE - ind - 1;
	char hold = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		hold = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
					  Size, hold, extra_ch));
}

/**
 * write_num - write number
 * @ind: types
 * @buffer: buffer
 * @width: width
 * @prec: accuracy
 * @extra_c: extra char
 * @flags: change conditions
 * @Size: size
 * @hold: length
 * Return: int
*/
int write_num(int ind, char buffer[],
			  int flags, int width, int prec,
			  int Size, char hold, char extra_c)
{
	int cnt, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = hold = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < Size)
		hold = ' ';
	while (prec > Size)
		buffer[--ind] = '0', Size++;
	if (extra_c != 0)
		Size++;
	if (width > Size)
	{
		for (cnt = 1; cnt < width - Size + 1; cnt++)
			buffer[cnt] = hold;
		buffer[cnt] = '\0';
		if (flags & F_MINUS && hold == ' ') /* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], Size) + write(1, &buffer[1], cnt - 1));
		}
		else if (!(flags & F_MINUS) && hold == ' ') /* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], cnt - 1) + write(1, &buffer[ind], Size));
		}
		else if (!(flags & F_MINUS) && hold == '0') /* extra char to left of hold */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], cnt - padd_start) +
					write(1, &buffer[ind], Size - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], Size));
}

/**
 * write_unsgn - write unsigned
 * @is_negative: check if negative
 * @ind: types
 * @buffer: buffer
 * @width: width
 * @precision: accuracy
 * @size: size
 * @flags: change state
 * Return: int
*/
int write_unsgnd(int is_negative, int ind,
				 char buffer[],
				 int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position cnt */
	int Size = BUFF_SIZE - ind - 1, cnt = 0;
	char hold = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < Size)
		hold = ' ';

	while (precision > Size)
	{
		buffer[--ind] = '0';
		Size++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		hold = '0';

	if (width > Size)
	{
		for (cnt = 0; cnt < width - Size; cnt++)
			buffer[cnt] = hold;

		buffer[cnt] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>hold]*/
		{
			return (write(1, &buffer[ind], Size) + write(1, &buffer[0], cnt));
		}
		else /* Asign extra char to left of padding [hold>buffer]*/
		{
			return (write(1, &buffer[0], cnt) + write(1, &buffer[ind], Size));
		}
	}

	return (write(1, &buffer[ind], Size));
}
/**
 * write_pointer - pointer write
 * @ind: types
 * @buffer: buffer
 * @width: width
 * @flags: check conditions
 * @Size: size
 * @hold: length
 * @extra_c: extra xtics
 * @padd_start: starting point
 * Return: int
*/
int write_pointer(char buffer[], int ind, int Size,
				  int width, int flags, char hold, char extra_c, int padd_start)
{
	int cnt;

	if (width > Size)
	{
		for (cnt = 3; cnt < width - Size + 3; cnt++)
			buffer[cnt] = hold;
		buffer[cnt] = '\0';
		if (flags & F_MINUS && hold == ' ') /* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], Size) + write(1, &buffer[3], cnt - 3));
		}
		else if (!(flags & F_MINUS) &&
		hold == ' ') /* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], cnt - 3) + write(1, &buffer[ind], Size));
		}
		else if (!(flags & F_MINUS) && hold == '0') /* extra char to left of hold */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], cnt - padd_start) +
					write(1, &buffer[ind], Size - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
