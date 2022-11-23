#include <stdio.h>
			#include <stdarg.h>

/**
 * state
 * 0: regular
 * 1.escape		
 */

void reverse(char s[], i			nt len)
{
	int i, j;
	char c;

	for (i = 0, j = len - 1; i < j; i++, j--		)
	{	
		c = s[i];
					s[i] = s[j];
		s[j] = c;
	}	
}	

void int	_str(int holder, char *str)
{	
		int i, y;
	int j = 0;
	y = hold	er;
	if (holder < 0)	
		y = -y;
	if (holder == 0)	
	{	
			str[j] = 0 + '0';
		j++;
	}	
	while (y	)
	{	
			i = y % 10;
		if (i + 	'0' < 48 && i + '0' > 57)
			return;
		y = y / 10;	
		str[j] = (char)(	48 + i);
		j++;	
	}	
	if (holder < 0)
	{
		str[j] = '-';
		j++;
	}
	str[j] = '\0';
	reverse(str, j);
}

void hex(int u, char *s)
{
    
	if (u < 0)
        return;
    	//s[0] = '0';
	//s[1] = 'x';
	int j = 0;
	char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	while (u)
    
	{
        
		int y = u % 16;

		s[j] = hex[y];
		u = u / 16;
		j++;
    
	}
	s[j] = 'x';
	j++;
	s[j] = '0';
	j++;
	s[j] = '\0';
	reverse(s,j);
}

void vprintk(const char *fmt, va_list args)
{
	int state = 0;
	while (*fmt)
	{
		if (state == 0)
		{
			if (*fmt == '%')
			{
				state = 1;
			}
			else
			{
				putchar(*fmt);
			}
		}
		else if (state == 1)
		{
			switch (*fmt)
			{
			case 'c':
				char ch = va_arg(args, int);
				putchar(ch);
				break;
			case 's':
				const char *s = va_arg(args, char *);
				while (*s)
				{
					putchar(*s);
					s++;
				}
				break;
			case 'd':
				int h = va_arg(args, int);
				char st[24];
				int_str(h, st);
				int k = 0;
				while (st[k])
				{
					putchar(st[k]);
					k++;
				}

				break;
			case 'x':
				int hx = va_arg(args, int);
				hex(hx,st);
				k = 0;
				while (st[k])
				{
					putchar(st[k]);
					k++;
				}
				
				break;
			case 'p':
				void *n = va_arg(args, void*);
				char bf[32];
				int_str((*(int*)n),bf);
				for (int f =0; bf[f]; f++)
					putchar(bf[f]);
				break;
			}
			state = 0;
		}

		fmt++;
	}
}

void printk(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vprintk(fmt, args);

	va_end(args);
}
int main(void)
{
	void *p = (void *)main;

	printk(" norm hello, world\n");
	printk("int hello, world %d H\n", -100000);
	printk("char  hello, world, %c H\n", 'h');
	printk("string hello, world %s H\n", "tom");
	printk("pointer hello, world, %p H\n", p);
	printk("pointer hello, world, %x H\n", 0xc8);
}
