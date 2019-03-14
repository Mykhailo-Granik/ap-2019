#include <iostream>
#include <vector>

using namespace std;

int siftUp(vector<int>& heap, int v) {
	while ((v > 1) && (heap[v] > heap[v / 2])) {
		swap(heap[v], heap[v / 2]);
		v /= 2;
	}
	return v;
}

int siftDown(vector<int>& heap, int v) {
	while (v * 2 < heap.size()) {
		int maxIndex = v * 2;
		if ((v * 2 + 1 < heap.size()) && (heap[v * 2 + 1] > heap[v * 2])) {
			maxIndex = v * 2 + 1;
		}
		if (heap[maxIndex] > heap[v]) {
			swap(heap[v], heap[maxIndex]);
			v = maxIndex;
		} else {
			break;
		}
	}
	return v;
}

int main() {
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int v, x;
		cin >> v >> x;
		a[v] -= x;
		cout << siftDown(a, v) << endl;
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i + 1] << " ";
	}
	cout << endl;
	
}
