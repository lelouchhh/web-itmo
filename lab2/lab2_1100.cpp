#include <iostream>
using namespace std;

struct dude
{
	int id;
	int m;
};

int main()
{
	dude a[150001];
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i].id >> a[i].m;
	for (j = 100; j >= 0; j--)
		for (i = 0; i < n; i++)
			if (a[i].m == j)
				cout << a[i].id << " " << a[i].m << endl;
}