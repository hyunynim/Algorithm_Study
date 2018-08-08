#include<iostream>
#include<stack>
#include<string>

using namespace std;

string str;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;

	int cnt = 0;
	int ans = 0;
	int open = 0;
	int tmp[123] = { 0 };
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(') {
			s.push(cnt ? cnt - 1 : 0);
			s.push(str[i - 1] - '0');
			cnt = 0;
			++open;
		}
		else if (str[i] == ')') {
			if (cnt) {
				tmp[open] += s.top() * cnt;
				cnt = 0;
				s.pop();
				--open;
			}
			else {
				tmp[open] += s.top();
				s.pop();
				tmp[open] *= s.top();
				s.pop();
				--open;
			}
		}
		else
			++cnt;
	}
	printf("%d", ans + s.top());
}