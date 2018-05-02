#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int cnt['z' - 'a' + 1] = { 0 };
	char name[31];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		cnt[name[0] - 'a']++;
	}
	int res = 0;
	for (int i = 0; i < 'z' - 'a' + 1; ++i) {
		if (cnt[i] >= 5) {
			printf("%c", i + 'a');
			res++;
		}
	}
	if (res == 0)
		printf("PREDAJA");
}