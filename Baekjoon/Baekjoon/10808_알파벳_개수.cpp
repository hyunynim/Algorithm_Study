#include <iostream>

int main() {
	int cnt[200] = { 0 };
	char msg[200];
	scanf("%s", msg);
	int i = 0;
	while (msg[i] != '\0') 
		cnt[msg[i++]]++;
	for (int i = 'a'; i <= 'z'; ++i)
		printf("%d ", cnt[i]);
}