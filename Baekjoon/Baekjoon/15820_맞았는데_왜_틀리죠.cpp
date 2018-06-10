#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int s1, s2;
	int t, a;
	scanf("%d %d", &s1, &s2);
	for (int i = 0; i < s1; ++i) {
		scanf("%d %d", &t, &a);
		if (t != a) {
			printf("Wrong Answer");
			return 0;
		}
	}
	for (int i = 0; i < s2; ++i) {
		scanf("%d %d", &t, &a);
		if (t != a) {
			printf("Why Wrong!!!");
			return 0;
		}
	}
	printf("Accepted");
}