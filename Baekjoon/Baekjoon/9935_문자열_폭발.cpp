#include<cstdio>
#include<string>
#include<stack>
using namespace std;
int main() {
	string str = "", bomb, tmp = "", rv;
	stack<char> st;
	char msg[1000012];
	scanf("%s", msg);
	for (int i = 0; msg[i] != '\0'; ++i)
		st.push(msg[i]);
	scanf("%s", msg);
	bomb = msg;
	rv = bomb;
	reverse(rv.begin(), rv.end());

	int len = bomb.length();
	int tmpLen = 0;
	
	int iTmp = 0;
	while (st.size()) {
		if (st.top() == bomb.back()) {
			int cnt = 0;
			while (st.top() == rv[cnt]) {
				tmp += st.top();
				st.pop();
				++cnt;
			}
			if (tmp != rv) {
				str += tmp;
				iTmp = cnt;
			}
			tmp = "";
		}
		else {
			iTmp = 0;
			str += st.top();
			st.pop();
		}
	}
}

/*comment*/
//런타임 에러가 해결이 안됨
//ㅈㅈ overflow나 무슨 문제 있는듯