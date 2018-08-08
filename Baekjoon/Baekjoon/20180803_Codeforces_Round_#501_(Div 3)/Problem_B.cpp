#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<iostream>

using namespace std;
typedef long long ll;

void swap(int & a, int & b) {
	int c = a;
	a = b;
	b = c;
}


int main() {
	int n;
	string s1, s2;
	cin >> n >> s2 >> s1;
	string s3 = s1, s4 = s2;
	sort(s3.begin(), s3.end());
	sort(s4.begin(), s4.end());
	if (s3 != s4) {
		printf("-1");
		return 0;
	}
	vector<int> a;
	for (int i = 0; i < s1.size(); ++i) {
		int ind = s1.find(s2[i]);
		a.push_back(ind);
		s1.erase(ind, 1);
		s1.insert(s1.begin() + ind, '#');
	}

	vector<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				ans.push_back(j);
			}
		}
	}

	printf("%d\n", ans.size());
	for (int i : ans)
		printf("%d ", i + 1);
}