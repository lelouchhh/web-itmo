
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int id, value;
} nod[80000];
bool cmp(node a, node b)
{
    return a.value < b.value || (a.value == b.value && a.id < b.id);
}
void find(int l, int r, int x, int n)
{
    int low = 0, top = n - 1;
    while (low <= top)
    {
        int mid = (low + top) / 2;
        if (nod[mid].value == x && nod[mid].id >= l && nod[mid].id <= r)
        {
            cout << "1";
            return;
        }
        else if (nod[mid].value < x || (nod[mid].value == x && nod[mid].id < l))
            low = mid + 1;
        else
            top = mid - 1;
    }
    cout << "0";
    return;
}
int main()
{
    int i, n, m, l, r, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> nod[i].value;
        nod[i].id = i + 1;
    }
    sort(nod, nod + n, cmp);
    cin >> m;
    while (m--)
    {
        cin >> l >> r >> x;
        find(l, r, x, n);
    }
    cout << endl;

}