#include<cstdio>
#include<string>
#include<stack>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		char msg[12345];
		stack<string> st;
		string strTmp;
		fgets(msg, 12344, stdin);
		strTmp = msg;
		strTmp.erase(strTmp.find("\n"));
		while (strTmp.find(" ") != string::npos) {
			st.push(strTmp.substr(0, strTmp.find(" ")).c_str());
			strTmp.erase(0, strTmp.find(" ") + 1);
		}
		st.push(strTmp);
		printf("Case #%d: ", i + 1);
		while (st.size()) {
			printf("%s ", st.top().c_str());
			st.pop();
		}
		printf("\n");
	}
}