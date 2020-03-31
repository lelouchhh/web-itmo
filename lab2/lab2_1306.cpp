#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, i;
    long long a, x, y;
    scanf("%d", &n);
    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > sortedstack;
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &a);
        sortedstack.push(a);
        if (sortedstack.size() > n / 2 + 1)
            sortedstack.pop();
    }
    if (n % 2)
        printf("%d\n", sortedstack.top());
    else
    {
        x = sortedstack.top();
        sortedstack.pop();
        y = sortedstack.top();
        if ((x + y) % 2 == 0)
            printf("%lld\n", (x + y) / 2);
        else
            printf("%.1lf\n", (x + y) * 1.0 / 2);
    }
    return 0;
}
