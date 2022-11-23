#include "main.h"

/**
 * state
 * 0: regular
 * 1.escape
 */



void vprintk(const char *fmt, va_list args)
{
	int state = 0;
	while (*fmt)
	{
		
		int len;
		if (state == 0)
		{
			if (*fmt == '%')
			{
				state = 1;
			}
			else
			{
				write(1,fmt,1);
			}
		}
		else if (state == 1)
		{
			switch (*fmt)
			{
			case 'c':
				char ch = va_arg(args, int);
				write(1,&ch,1);
				break;
			case 's':
				const char *s = va_arg(args, char *);
				while (*s)
				{
					write(1,s,1);
					s++;
				}
				// write(1,s,1);
				break;
			case 'd':
				int h = va_arg(args, int);
				char st[24];
				base(h, 10,&len,st);;
				// write(1,st,5);
				// int k = 0;
				// while (st[k])
				// {
				// 	write(1,st,1);
				// 	k++;
				// }
				write(1,st,len);

				break;
			case 'x':
				int hx = va_arg(args, int);
				base(hx, 16, &len,st);
				// k = 0;
				// while (st[k])
				// {
				// 	write(1,st,1);
				// 	k++;
				// }
				write(1,st,len);
				
				break;
			case 'p':
				// void *n = va_arg(args, void*);
				// char bf[32];
				//int_str((*(int*)n),bf);
				
				// for (int f =0; bf[f]; f++)
				// 	putchar(bf[f]);
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
	printk("int hello, world %d H\n", 100000);
	printk("char  hello, world, %c H\n", 'h');
	printk("string hello, world %s H\n", "tom holland");
	printk("pointer hello, world, %p H\n", p);
	printk("pointer hello, world, %x H\n", 0xc8);
}
