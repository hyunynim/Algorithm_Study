#include <stdio.h>
#include <stack>

using namespace std;
int main() {
	int x, sum = 0, len = 64;
	stack <int> stick;
	scanf("%d", &x);

	while (len > x)
		len /= 2;
	sum += len;
	stick.push(len);
	while (1){
		if (sum == x)
			break;
		if (sum + len / 2 == x) {
			stick.push(len / 2);
			break;
		}

		else if (sum + len / 2 < x) {
			len /= 2;
			sum += len;
			stick.push(len);
		}
		else if (sum + len / 2 > x) 
			len /= 2;
	}
	printf("%d", stick.size());
}