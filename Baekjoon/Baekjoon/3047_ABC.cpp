#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);

	char msg[5];
	scanf("%s", msg);
	int i = 0;
	while (msg[i] != '\0') {
		printf("%d ", a[msg[i] - 'A']);
		++i;
	}	
}