#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		char msg[12345];
		queue<string> st;
		string strTmp;
		fgets(msg, 12344, stdin);
		strTmp = msg;
		strTmp.erase(strTmp.find("\n"));
		while (strTmp.find(" ") != string::npos) {
			st.push(strTmp.substr(0, strTmp.find(" ")).c_str());
			strTmp.erase(0, strTmp.find(" ") + 1);
		}
		st.push(strTmp);
		while (st.size()) {
			for (int i = st.front().length() - 1; i >= 0; --i) {
				printf("%c", st.front()[i]);
			}
			printf(" ");
			st.pop();
		}
		printf("\n");
	}
}