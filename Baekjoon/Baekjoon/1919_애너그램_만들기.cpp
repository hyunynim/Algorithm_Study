#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;
char msg[2][1234];
int cnt[2][30];

int main() {
	scanf("%s %s", msg[0], msg[1]);
	for (int i = 0; msg[0][i] != '\0'; ++i) 
		cnt[0][msg[0][i] - 'a']++;
	for (int i = 0; msg[1][i] != '\0'; ++i)
		cnt[1][msg[1][i] - 'a']++;
	int ans = 0;
	for (int i = 0; i < 30; ++i)
		ans += min(cnt[0][i], cnt[1][i]);
	printf("%d", strlen(msg[0]) + strlen(msg[1]) - (2*ans));
}