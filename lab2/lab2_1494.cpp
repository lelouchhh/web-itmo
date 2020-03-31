#include <iostream>
#include <queue>
using namespace std;
int n, m, k, t, now;
bool flag;
priority_queue<int>a;
int main()
{
    int i, j;
    now = 1;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &j);
        while (now <= j)
        {
            a.push(now);
            now++;
            cout << now << endl;
        }
        if (a.top() != j)
        {
            flag = true;
        }
        else a.pop();
    }
    if (flag) cout << "Cheater" << endl;
    else cout << "Not a proof" << endl;
    return 0;
}