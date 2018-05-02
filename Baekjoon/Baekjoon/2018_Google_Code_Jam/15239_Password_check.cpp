#include <iostream>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		char password[100];
		scanf("%d %s", &n, password);
		if (n < 12) {
			printf("invalid");
		}
		else {
			int j = 0;
			int invalid = 1;
			int chk[4] = { 0 };

			while (password[j] != '\0') {
				if ('a' <= password[j] && password[j] <= 'z') {
					chk[0]++;
				}
				else if ('A' <= password[j] && password[j] <= 'Z') {
					chk[1]++;
				}
				else if ('0' <= password[j] && password[j] <= '9') {
					chk[2]++;
				}
				else
					chk[3]++;
				++j;
			}
			for (int j = 0; j < 4; ++j) {
				if (chk[j] == 0) {
					invalid = 0;
					break;
				}
			}
			if (invalid)
				printf("valid");
			else
				printf("invalid");
		}
		printf("\n");
	}
}