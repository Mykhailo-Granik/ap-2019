#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void sift_up(int v, vector<int>& heap) {

    while ((v > 1) && (heap[v / 2] > heap[v])) {
        swap(heap[v], heap[v / 2]);
        v /= 2;
    }

}

void sift_down(int v, vector<int>& heap) {

    int n = heap.size() - 1;
    while (v * 2 <= n) {
        int minIndex = v * 2;
        if ((v * 2 + 1 <= n) && heap[v * 2 + 1] < heap[v * 2]) {
            minIndex = v * 2 + 1;
        }
        if (heap[v] > heap[minIndex]) {
            swap(heap[v], heap[minIndex]);
            v = minIndex;
        }
        else {
            break;
        }
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> heap(n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &heap[i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        sift_up(i, heap);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", heap[1]);
        swap(heap[1], heap[heap.size() - 1]);
        heap.pop_back();
        sift_down(1, heap);
    }
    cout << endl;


}
