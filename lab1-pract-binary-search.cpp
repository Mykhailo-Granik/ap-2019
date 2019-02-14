#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int value;
		cin >> value;
		int l = 0, r = n - 1;
		int bestIndex = n - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (a[m] > value)
			{
				bestIndex = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		if ((bestIndex > 0) && (abs(a[bestIndex - 1] - value) <= abs(a[bestIndex] - value)))
		{
			bestIndex--;
		}
		cout << a[bestIndex] << endl;
	}

}
