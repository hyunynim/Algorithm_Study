#include<iostream>
#include<stack>
#include<algorithm>

#define pb(x) push_back(x)

using namespace std;
long long cnt[2][300001] = { 0 }; //0:( 1:) 불가능은 체크 안함
char msg[300000];
stack<char> chk;
int main() {
	int n;
	long long cntC = 0;
	long long res = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int stat = 0;
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
		if (chk.empty()) {
			if (tmp)
				++cnt[1][tmp];
			else
				++cntC;
		}
		else {
			if (tmp)
				continue;
			cnt[0][chk.size()]++;
		}
	}
	for (int i = 1; i < 300001; ++i) {
		if (cnt[0][i])
			res += cnt[0][i] * cnt[1][i];
	}
	res += cntC * cntC;
	cout << res;
}

/*comment*/
//남는 괄호가 )( 형태로 이루어져 있으면 셀필요 없음
//남는괄호가 한방향 ((( 또는 ))) 등이면 해당 개수끼리 짝맞춰서 곱해주면될듯
//)()()( 이런 case를 생각 안함
//tmp == 300000 일 경우 배열에 들어가질 못할 것 같음. 배열 사이즈 조정
//뭐가 틀린지 잘 모르겠음
//곱하기에서 overflow 발생 가능
//해결