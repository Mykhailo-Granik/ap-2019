#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{

	vector<int> queue;
	int n;
	cin >> n;
	int left_bound = 0;
	for (int i = 0; i < n; ++i) {
	    string operation;
	    cin >> operation;
	    if (operation == "+") {
	        int value;
	        cin >> value;
	        queue.push_back(value);
	    }
	    else {
	        if (left_bound != queue.size()) {
    	        cout << queue[left_bound] << endl;
    	        left_bound++;
	        } else {
	            cout << "EMPTY" << endl;
	        }
	    }
	}

}
