#include <iostream>

using namespace std;
int ARR[20][10000];
int N, K;

int merge(int a[], int lo, int hi) {
	if (lo >= hi) return 0;
	int mid = lo + (hi - lo) / 2, mrg = 0;
	mrg += merge(a, lo, mid);
	mrg += merge(a, mid + 1, hi);
	int* b = new int[mid - lo + 1];
	int* c = new int[hi - mid];
	for (int i = 0; i < mid - lo + 1; i++)
		b[i] = a[lo + i];
	for (int i = 0; i < hi - mid; i++)
		c[i] = a[i + mid + 1];
	int Ib = 0, Ic = 0, Ia = 0;
	while (Ia < hi - lo + 1) {
		if (Ib < mid - lo + 1 && Ic < hi - mid) {
			if (b[Ib] > c[Ic])
				a[lo + Ia++] = c[Ic++],
				mrg += mid - lo + 1 - Ib;
			else
				a[lo + Ia++] = b[Ib++];
		}
		else if (Ib < mid - lo + 1) {
			a[lo + Ia++] = b[Ib++];
		}
		else if (Ic < hi - mid) {
			a[lo + Ia++] = c[Ic++];
		}
	}
	delete[]b;
	delete[]c;
	return mrg;
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ARR[i][j];
		}
	}
	int res = merge(ARR[0], 0, N - 1);
	int iter = 0;
	for (int i = 0; i < K; i++) {
		int mrg = merge(ARR[i], 0, N - 1);
		if (mrg > res)
			res = mrg, iter = i;
	}
	cout << iter + 1 << endl;
	return 0;
}