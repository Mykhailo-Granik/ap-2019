#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1000000000;

int main()
{

	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
	int n, m, start, finish;
	cin >> n >> m >> start >> finish;
	start--;
	finish--;

	vector<vector<int>> g, w;
	g.resize(n); w.resize(n);
	for (int i = 0; i < m; ++i) {
		int v1, v2, weight;
		scanf("%d%d%d",&v1,&v2,&weight);
		v1--;
		v2--;
		g[v1].push_back(v2); w[v1].push_back(weight);
		g[v2].push_back(v1); w[v2].push_back(weight);
	}

	vector<int> d(n, INF);
	d[start] = 0;
	set<pair<int,int>> s; // first - d[v], second - v
	s.insert(make_pair(d[start], start));
	vector<int> parent(n, -1);
	while (s.size() > 0) {
		int v = s.begin()->second;
		s.erase(s.begin());
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			int weight = w[v][i];
			if (d[v] + weight < d[to]) {
				s.erase(make_pair(d[to], to));
				d[to] = d[v] + weight;
				parent[to] = v;
				s.insert(make_pair(d[to], to));
			}
		}
	}
	if (d[finish] == INF) {
		cout << -1 << endl;
	} else {
		cout << d[finish] << endl;
		vector<int> path;
		int v = finish;
		while (v != start) {
			path.push_back(v);
			v = parent[v];
		}
		path.push_back(start);
		for (int i = path.size() - 1; i >= 0; --i) {
			printf("%d ", path[i] + 1);
		}
		cout << endl;
	}

}
