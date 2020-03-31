#include <iostream>
using namespace std;
int index[1000];
int value[100000];
unsigned short old[100000];
char porp[10];
int n, stk, val;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> porp;
		if (porp[1] == 'U')
		{
			cin >> stk >> val;
			stk--;
			value[i] = val;
			if (index[stk] > 65535)
			{
				old[i] = index[stk] - 65535;
				value[i] = -value[i];
			}
			else
				old[i] = index[stk];
			index[stk] = i;
		}
		else
		{
			cin >> stk;
			stk--;
			printf("%d\n", abs(value[index[stk]]));
			if (value[index[stk]] < 0)
				index[stk] = old[index[stk]] + 65535;
			else
				index[stk] = old[index[stk]];
		}
	}

	return 0;
}