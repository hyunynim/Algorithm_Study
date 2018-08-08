#include<cstdio>
#include<string>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 0; TC < t; ++TC) {
		char msg[1234];
		string str;
		scanf("%s", msg);
		str = msg;
		auto it = str.find("()");
		while (it != string::npos) {
			str.erase(it, 2);
			it = str.find("()");
		}
		if (str.length())
			printf("NO\n");
		else
			printf("YES\n");
	}
}