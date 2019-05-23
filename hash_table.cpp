#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

const int M = 2000000;

// [0...M - 1]
int hash_function(string s)
{

	int p = 1;
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		int c = (s[i] - 'a' + 1);
		res += p * c;
		res %= M;

		p *= 27;
		p %= M;
	}
	return res;
}

char operation[2];
char word[11];
vector<vector<string>> hash_table;

bool find_word(string s) {
	int hash_of_word = hash_function(s);
	for (int i = 0; i < hash_table[hash_of_word].size(); ++i) {
		if (hash_table[hash_of_word][i] == s) {
			return true;
		}
	}
	return false;
}

void add_word(string s) {
	int hash_of_word = hash_function(s);
	hash_table[hash_of_word].push_back(s);
}

int main()
{

	hash_table.resize(M);
	while (true) {
		scanf("%s", operation);
		if (operation[0] == '#') {
			break;
		}
		if (operation[0] == '?') {
			scanf("%s", word);
			if (find_word((string)word)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			scanf("%s", word);
			add_word((string)word);
		}
	}
}
