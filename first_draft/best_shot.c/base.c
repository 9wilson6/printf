#include "main.h"
void reverse(char s[], int len)
{
    int i, j;
    char c;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void base(int input, int base, int *len, char *output)
{
    int i, y, hold, flag = 0;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    hold = base;

    if (input < 0)
    {
        input = -input;
        flag = 1;
    }
    if (hold == 17)
    {
        base = 16;
    }
    i = 0;
    while (input)
    {
        y = input % base;
        input = input / base;
        // printf("\t\n %d\n", y);
        if (hold == 17)
        {
            if (y > 9)
            {
                output[i] = (char)((int)arr[y] - 32);
            }
            else
            {
                output[i] = arr[y];
            }
        }
        else
        {
            output[i] = arr[y];
        }
        i++;
    }
    if (base == 10 && flag == 1)
    {
        output[i] = '-';
        i++;
    }
    // if (base == 16)
    // {
    //     output[i] = 'x';
    //     i++;
    //     output[i] = '0';
    //     i++;
    // }
    output[i] = '\0';
    *len = i;
    reverse(output, i);
}
// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//         return 1;
//     int num = atoi(argv[1]);
//     int bs = atoi(argv[2]);
//     if (bs > 17)
//         bs = 16;

//     char str[12];
//     int len;
//     base(num, bs, &len, str);
//     printf("\t\t\n%d \n", num);
//     printf("\n %s \t %d \n ", str, len);
// }