#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main()
{

	freopen("dijkstra.in", "r", stdin);
	freopen("dijkstra.out", "w", stdout);
	int n, s, f;
	cin >>n >> s >> f;
	s--;
	f--;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	vector<int> d(n, INF);
	d[s] = 0;
	vector<int> used(n);

	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (used[j] == 0) {
				if (v == -1) {
					v = j;
				} else {
					if (d[j] < d[v]) {
						v = j;
					}
				}
			}
		}
		if (d[v] == INF) {
			break;
		}
		used[v] = 1;
		for (int j = 0; j < n; ++j) {
			if (a[v][j] >= 0) {
				if (d[v] + a[v][j] < d[j]) {
					d[j] = d[v] + a[v][j];
				}
			}
		}

	}
	if (d[f] == INF) {
		cout << -1 << endl;
	} else {
		cout << d[f] << endl;
	}

}
