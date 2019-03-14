#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{

	stack<int> additionStack, removalStack;
	// + value
	// -
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string operation;
		cin >> operation;
		if (operation == "+")
		{
			int value;
			cin >> value;
			additionStack.push(value);
		}
		else {
			if (removalStack.empty()) {
				while (additionStack.size() > 0) {
					int value = additionStack.top();
					additionStack.pop();
					removalStack.push(value);
				}
			}
			if (removalStack.size() > 0) {
				cout << removalStack.top() << endl;
				removalStack.pop();
			} else {
				cout << "EMPTY" << endl;
			}
		}
	}

}
