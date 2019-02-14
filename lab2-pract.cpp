#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<pair<int,int>>a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j + 1 < n; ++j)
		{
			if (a[j].second < a[j + 1].second)
			{
				swap(a[j], a[j + 1]);
			} else if ((a[j].second == a[j + 1].second) && (a[j].first > a[j + 1].first))
			{
				swap(a[j], a[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i].first << " " << a[i].second << endl;
	}


}
