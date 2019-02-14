#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int value;
	cin >> value;
	int l = 0, r = n - 1;
	int res = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == value)
		{
			res = m;
			r = m - 1;
		}
		else if (a[m] > value)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << res << endl;


}
