#include <iostream>
using namespace std;
int n;
int arr[100010], result[100010];
int lvl(int x)
{
    int sum = 0;
    for (int i = x; i; i -= i & (-i))
    {
        sum += arr[i];
        //cout << "i is  " << i << endl;
        //cout << "a[i] is " << a[i] << endl;
    }
    //cout << "sum is " << sum << endl;
    return sum;
}
void plusone(int x)
{
    for (int i = x; i <= 32001; i += i & (-i))
    {
        //cout << i << endl;
        arr[i] += 1;
        //cout << i << endl;
    }
}
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        x++;
        result[lvl(x)]++;
        plusone(x);
    }
    for (i = 0; i <= n-1; i++)printf("%d\n", result[i]);
    return 0;
}