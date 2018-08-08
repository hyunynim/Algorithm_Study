#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char msg[543210];
int cnt[34];
int len = 1;
bool chk() {
	string str1, str2;
	str1 = str2 = msg;
	reverse(str2.begin(), str2.end());
	
	return str1 == str2;
}

int main() {
	scanf("%s", msg);
	for (int i = 0; msg[i] != '\0'; ++i) {
		cnt[msg[i] - 'A']++;
		++len;
	}
	int res = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i])
			++res;
	}
	if (res == 1)
		printf("-1");
	else {
		if (chk())
			printf("%d", len - 2);
		else
			printf("%d", len - 1);
	}
}