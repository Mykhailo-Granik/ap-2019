#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> g;

const int INF = 1000000000;

int main()
{

	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	int start;
	cin >> start;
	start--;
	queue<int> q;
	q.push(start);
	vector<int> d(n, INF);
	d[start] = 0;
	while (q.size() > 0) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;

}
