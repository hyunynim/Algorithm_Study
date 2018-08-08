#include<cstdio>
#include<string>

using namespace std;

int main() {
	char msg[123456];
	scanf("%s", msg);
	string str = msg;
	long long it[3] = { str.find("pi"), str.find("ka"), str.find("chu") };
	while (it[0] != -1 || it[1] != -1 || it[2] != -1) {
		it[0] = str.find("pi");
		if (it[0] != string::npos) {
			str.erase(it[0], 2);
			str.insert(str.begin() + it[0], '#');
		}
		it[1] = str.find("ka");
		if (it[1] != string::npos) {
			str.erase(it[1], 2);
			str.insert(str.begin() + it[1], '#');
		}
		it[2] = str.find("chu");
		if (it[2] != string::npos) {
			str.erase(it[2], 3);
			str.insert(str.begin() + it[2], '#');
		}
	}
	for (auto i = str.begin(); i != str.end(); ++i) {
		if (*i != '#') {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}