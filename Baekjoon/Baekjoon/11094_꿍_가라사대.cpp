#include<cstdio>
#include<string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		char msg[12345];
		fgets(msg, 12344, stdin);
		string strTmp = msg;
		if (strTmp.find("Simon says") != string::npos) {
			strTmp.erase(0, strTmp.find("Simon says"));
			strTmp.erase(0, 10);
			printf("%s", strTmp.c_str());
		}
	}
}