#include<iostream>
#include<stack>
#include<algorithm>

#define pb(x) push_back(x)

using namespace std;
long long cnt[2][300001] = { 0 }; //0:( 1:) 불가능은 체크 안함
char msg[300000];
stack<char> chk;
int main() {
	long long cntC = 0;
	long long res = 0;
	int tmp = 0;
	cin >> msg;
	while (chk.size())
		chk.pop();
	for (int j = 0; msg[j] != '\0'; ++j) {
		if (msg[j] == '(')
			chk.push('(');
		else {
			if (chk.size())
				chk.pop();
			else
				++tmp;
		}
	}
	res = tmp + chk.size();
	cout << res;
}