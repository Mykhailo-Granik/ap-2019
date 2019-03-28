#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

const int INF = 2000000000;

struct MinStack {

	stack<int> regularStack, minStack;

	void push(int v) {
		regularStack.push(v);
		int minValue = v;
		if ((minStack.size() > 0) && (minStack.top() < minValue)) {
			minValue = minStack.top();
		}
		minStack.push(minValue);
	}

	int pop() {
		if (regularStack.size() > 0) {
			int res = regularStack.top();
			regularStack.pop();
			minStack.pop();
			return res;
		}
		return INF;
	}

	int getMin() {
		if (regularStack.size() > 0) {
			return minStack.top();
		}
		return INF;
	}

	int size() {
		return regularStack.size();
	}

	int top() {
		if (regularStack.size() > 0) {
			return regularStack.top();
		}
		return INF;
	}

};

struct MinQueue {

	MinStack *insertionStack;
	MinStack *removalStack;

	MinQueue() {
		insertionStack = new MinStack();
		removalStack = new MinStack();
	}

	void push(int v) {
		insertionStack->push(v);
	}

	int pop() {
		if (removalStack->size() == 0) {
			while (insertionStack->size() > 0) {
				int top = insertionStack->pop();
				removalStack->push(top);
			}
		}
		if (removalStack->size() == 0) {
			return INF;
		}
		return removalStack->pop();
	}

	int getMin() {
		return min(insertionStack->getMin(), removalStack->getMin());
	}

	int size() {
		return insertionStack->size() + removalStack->size();
	}

};

int main()
{
	MinQueue minQueue;
	minQueue.push(2);
	minQueue.push(3);
	cout << minQueue.getMin() << endl;
	minQueue.pop();
	cout << minQueue.getMin() << endl;

}
