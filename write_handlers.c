#include "main.h"

/**
<<<<<<< HEAD
 *   handle_write_char - Prints a string
 *   @c: char types.
 *   @buffer: Buffer array to handle print
 *   @flags:  Calculates active flags.
 *   @width: get width.
 *   @precision: precision specifier
 *   @size: Size specifier
 *   Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';
	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
=======
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
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
<<<<<<< HEAD
		for (i = 0; i < width - 1; i++)
			buffer[BUFFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - i - 1], width -1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + write(1, &buffer[0], 1));
	}
=======
		for (cnt = 0; cnt < width - 1; cnt++)
			buffer[BUFF_SIZE - cnt - 2] = hold;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - cnt - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - cnt - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
	return (write(1, &buffer[0], 1));
}

/**
<<<<<<< HEAD
 *   write_number - Prints a string
 *   @is_negative: Lista of arguments
 *   @ind: char types.
 *   @buffer: Buffer array to handle print
 *   @flags:  Calculates active flags
 *   @width: get width.
 *   @precision: precision specifier
 *   @size: Size specifier
 *   Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;
	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
=======
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
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

<<<<<<< HEAD
	return (write_num(ind, buffer, flags, width, precision, length, padd, extra_ch));
}


/**
 *    write_num - Write a number using a bufffer
 *    @ind: Index at which the number starts on the buffer
 *    @buffer: Buffer
 *    @flags: Flags
 *    @width: width
 *    @prec: Precision specifier
 *    @length: Number length
 *    @padd: Pading char
 *    @extra_c: Extra char
 *    Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],int flags, int width, int prec,int length, char padd, char extra_c)
{
	int i, padd_start = 1;
=======
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
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
<<<<<<< HEAD
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;

	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == '')
		{
			if (extra_c)
				buffer[--ind] = extrac_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i -1));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[ind], length - (1 - padd_start)));
=======
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
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
<<<<<<< HEAD
	return (write(1, &buffer[ind], length));
	
}


/**
 *    write_unsgnd - Writes an unsigned number
 *    @is_negative: Number indicating if the num is negative
 *    @ind: Index at which the number starts in the buffer
 *    @buffer: Array of chars
 *    @flags: Flags specifiers
 *    @width: Width specifier
 *    @precision: Precision specifier
 *    @size: Size specifier
 *    Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind, char buffer[],int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';
=======
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

>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
<<<<<<< HEAD
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}

	}
	return (write(1, &buffer[ind], length));

}


/**
 *     write_pointer - Write a memory address
 *     @buffer: Arrays of chars
 *     @ind: Index at which the number starts in the buffer
 *     @length: Length of number
 *     @width: Wwidth specifier
 *     @flags: Flags specifier
 *     @padd: Char representing the padding
 *     @extra_c: Char representing extra char
 *     @padd_start: Index at which padding should start
 *     Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	int (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
=======
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
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
<<<<<<< HEAD
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--paid_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[paid_start], i - padd_start) + write(1, &buffer[ind], length - (1 - padd_start) - 2));
=======
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
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
<<<<<<< HEAD
	return (write(1, &buffer[ind], BUFF_SIZE  - ind - 1));
}












=======
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
>>>>>>> 1f0d3a2f1ba5a8f1a2a6fa801e26b82891b64308
