#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<string>

using namespace std;

typedef long long ll;

int alpha[2][26];

int main() {
	int n;
	string str[2];
	cin >> n >> str[0] >> str[1];
	for (int i = 0; i < n; ++i) {
		for(int j = 0; j<2; ++j)
			alpha[j][str[j][i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		printf("%c %d %d\n", i + 'a', alpha[0][i], alpha[1][i]);
	}
}