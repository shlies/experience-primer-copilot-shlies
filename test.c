
/*给定n个不同的整数数字（1~9，从小到大依次输入），请编程求出其所能组成的所有n位整数，并按从小到大的顺序依次输出，每行一个整数。要求用递归实现。

如，先输入3，再依次从小到大输入1，2，3三个整数数字，其所有可能组成的3位整数，从小到大依次输出为：

123

132

213

231

312

321

*/

#include <stdio.h>
#include <string.h>

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); // backtrack
       }
   }
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    char str[] = "12345";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}