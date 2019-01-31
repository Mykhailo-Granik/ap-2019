#include <iostream>


using namespace std;

int a[1000];


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;
	for (int i = 0; i < n; ++i)
	{
		if (x == a[i])
		{
			cout << i + 1 << endl;
		}
	}
	return 0;
}
