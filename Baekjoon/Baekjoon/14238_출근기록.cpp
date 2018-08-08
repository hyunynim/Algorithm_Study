#include<iostream>
#include<string>
#include<vector>
using namespace std;

int cnt[3];
int len;
bool chk(string & str) {
	for (int i = 2; i < str.size(); ++i) {
		if (str[i] == 'C' && str[i - 2] == 'C' || str[i-1] == 'C')
			return 0;
		if (str[i] == 'B' && str[i - 1] == 'B')
			return 0;
	}
	return 1;
}

int main() {
	string str;
	cin >> str;
	len = str.size();
	for (int i = 0; i < str.size(); ++i) {
		cnt[str[i] - 'A']++;
	}
	vector<char> ans(len);

	for (int i = 0; i < len; i += 3) {
		if (cnt[2] == 0)
			break;
		ans[i] = 'C'; --cnt[2];
	}
	for (int i = 1; i < len; i += 3) {
		if (cnt[0] && cnt[1]) {
			ans[i] = 'B'; ans[i + 1] = 'A';
			--cnt[0]; --cnt[1];
		}
		else if (cnt[1]) {
			ans[i] = 'B';
			--cnt[1];
		}
		if (cnt[1] == 0)
			break;
	}
	
	for (auto i : ans) 
		cout << i;
	
}