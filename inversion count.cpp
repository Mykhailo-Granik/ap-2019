#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

long long res;
void mergeSort(vector<int> &a) {
	if (a.size() <= 1) {
		return;
	}
	int m = (a.size() - 1) / 2;
	vector<int> b, c;
	for (int i = 0; i < a.size(); ++i) {
		if (i <= m) {
			b.push_back(a[i]);
		} else {
			c.push_back(a[i]);
		}
	}
	mergeSort(b);
	mergeSort(c);
	int pointer1 = 0;
	int pointer2 = 0;
	for (int i = 0; i < a.size(); ++i) {
		if ((pointer1 < b.size()) && ((pointer2 == c.size()) || (b[pointer1] <= c[pointer2]))) {
			a[i] = b[pointer1];
			pointer1++;
		} else {
			a[i] = c[pointer2];
			pointer2++;
			res += (b.size() - pointer1);
		}
	}
}

int main()
{

	int t;
	cin >> t;
	for (int testNumber = 0; testNumber < t; ++testNumber) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		res = 0;
		mergeSort(a);
		printf("%lld\n", res);
	}

}
