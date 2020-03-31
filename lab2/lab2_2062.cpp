#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int search_arr[100017];

struct line
{
    int left;
    int right;
    int num;
} x[100017];


int arr_index = 0, i = 1;
int search(int q)
{
    while (q >= x[i].left)
    {
        search_arr[++arr_index] = i;
        i++;
        if (i > n)
            break;
    }
    while (q > x[search_arr[arr_index]].right)
    {
        arr_index--;
        if (arr_index < 1)
            break;
    }
    return x[search_arr[arr_index]].num;
}
int main()
{
    cin >> n;
    int result[100017];
    int first, second;
    int min = 100017, max = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> first >> second;
        if (first < min)
        {
            min = first;
        }
        if (second > max)
        {
            max = second;
        }
        x[i].left = first, x[i].right = second;
        x[i].num = i;
    }
    int t, q[100017];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        q[i] = t;
    }
    for (int i = 1; i <= m; i++)
    {
        if (q[i] < min || q[i] > max)
        {
            result[i] = -1;
            continue;
        }
        result[i] = search(q[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}