#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack <char> braket;
	char msg[51];
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%s", msg);
		int j = 0;
		int chkok = 1;
		while (msg[j] != '\0') {
			if (msg[j] == '(')
				braket.push('(');
			else {
				if (braket.size() == 0) {
					printf("NO\n");
					chkok = 0;
					break;
				}
				else
					braket.pop();
			}
			j++;
		}
		if (braket.size() != 0) {
			printf("NO\n");
			while (braket.size() != 0)
				braket.pop();
		}
		else if(chkok == 1)
			printf("YES\n");
	}
}