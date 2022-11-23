#include "main.h"

<<<<<<< HEAD
/**
 *  is_printable - Evaluates if a char is printable
 *  @c: Char to be evaluated.
 *  Return: 1 if c is printable, 0 otherwise
 */
=======

/**
 *is_printable - check if it is printable
 *@c: Char input
 *Return: int
 */

>>>>>>> fbf0252cb6423d9eb5437a64a8d5ec273bdfcc4d
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
<<<<<<< HEAD
	return (0);
}

/**
 *  append_hexa_code - Append ascci in hexadecimal code to buffer
 *  @buffer: Array of chars.
 *  @i: Index at which to start appending.
 *  @ascii_code: ASSCI CODE.
 *  Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);

}

/**
 *   is_digit - Verifies if a char is a digit
 *   @c: Char to be evaluated
 *   Return: 1 if c is a digit, 0 otherwise
 */
=======

	return (0);
}
/**
 * append_hexa_code - append str
 * @buffer: string buffer
 * @i: Index
 * @ascii_code: asci code
 * Return: int
 *
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 *is_digit - check if digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
*/
>>>>>>> fbf0252cb6423d9eb5437a64a8d5ec273bdfcc4d
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
<<<<<<< HEAD
	return (0);
}

/**
 *   convert_size_number - Casts a number to the specified size
 *   @num: Number to be casted.
 *   @size: Number indicating the type to be casted.
 *   Return: Casted value of num
 */
=======

	return (0);
}
/**
 * convert_size_number - Convertds int to size
 * @num: Number input
 * @size: Number type to convert
 *
 * Return: Casted value of num
*/

>>>>>>> fbf0252cb6423d9eb5437a64a8d5ec273bdfcc4d
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
<<<<<<< HEAD
=======

>>>>>>> fbf0252cb6423d9eb5437a64a8d5ec273bdfcc4d
	return ((int)num);
}

/**
<<<<<<< HEAD
 *   convert_size_unsgnd - Casts a number to the specified size
 *   @num: Number to be casted
 *   @size: Number indicating the type to be casted
 *   Return: Casted value of num
 */
=======
 * convert_size_unsgnd - signed size
 * @num: input number
 * @size: type to be casted
 *
 * Return: Casted value of num
*/

>>>>>>> fbf0252cb6423d9eb5437a64a8d5ec273bdfcc4d
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
<<<<<<< HEAD
	return ((unsigned int)num);
}





































=======

	return ((unsigned int)num);
}
>>>>>>> fbf0252cb6423d9eb5437a64a8d5ec273bdfcc4d
