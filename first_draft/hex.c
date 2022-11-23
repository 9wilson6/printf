#include <stdio.h>
#include <stdlib.h>

 void reverse(char s[], int len)
 {
     int i, j;
     char c;

     for (i = 0, j = len - 1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
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
int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	char s[24];
	char str[24];
	int y = atoi(argv[1]);
	int u = 0xc8;
	hex(y, s);
	hex(u,str);
	printf("\n\t %s \n",str);
	printf("\t\t\n%x\n",-32);
	printf("\n%x\n", y);
	printf("string %s\n", s);
	return 0;
}
