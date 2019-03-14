#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{

	stack<int> dataStack, minStack;
	// + value
	// -
	// get
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string operation;
		cin >> operation;
		if (operation == "+") {
			int value;
			cin >> value;
			dataStack.push(value);
			if ((minStack.size() > 0) && (minStack.top() < value)) {
				minStack.push(minStack.top());
			}
			else {
				minStack.push(value);
			}
		} else if (operation == "-") {
			minStack.pop();
			dataStack.pop();
		}
		else {
			if (minStack.empty()) {
				cout << "EMPTY" << endl;
			} else {
				cout << minStack.top();
			}
		}
	}

}

