#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char stack[200020]; //stack


int main()
{
    int top = 0;
    while (scanf("%c", &stack[top]) != EOF)
    {
        if (stack[top] == '\n')
            break;
        if (top > 0 && stack[top - 1] == stack[top])
            top--;
        else
            top++;
    }
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
    return 0;
}