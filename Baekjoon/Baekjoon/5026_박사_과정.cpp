#include<cstdio>
#include<string>
using namespace std;

int String2Int(string str) {
	int res = 0;
	for (int i = 0; i < str.length(); ++i) {
		res = res * 10 + str.at(i) - '0';
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[12345];
		string str;
		scanf("%s", msg);
		str = msg;
		if (str.find("+") == string::npos)
			printf("skipped\n");
		else {
			printf("%d\n", String2Int(str.substr(0, str.find("+"))) + String2Int(str.substr(str.find("+") + 1, str.length())));
		}
	}
}