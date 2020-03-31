
#include <iostream>
#include<cstdio>

int q[26000];
int result[26000];
int low = 0, high = 0;
int num = 0;
int max = 0;


int main()
{
    int m, a;
    scanf("%d", &m);
    while (scanf("%d", &a) && a != -1)
    {
        q[high++] = a;
        if (a >= q[max])
            max = high - 1;
        if (high - low == m)
        {
            result[num++] = q[max];
            low++;
            if (max < low)
            {
                max = low;
                for (int i = low + 1; i < high; i++)
                    if (q[i] >= q[max])
                        max = i;
            }
        }
    }
    for (int i = 0; i < num; i++)
        printf("%d\n", result[i]);
    return 0;
}