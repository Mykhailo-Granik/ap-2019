#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{

	vector<int> stack;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		int res = -1;
		while (!stack.empty()) {
			int top = stack.back();
			if (top < value) {
				res = top;
				break;
			}
			stack.pop_back();
		}
		cout << res << endl;
		stack.push_back(value);
	}

}
