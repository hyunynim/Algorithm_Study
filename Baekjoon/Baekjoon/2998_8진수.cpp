#include<cstdio>
#include<stack>
#include<string.h>

using namespace std;

void B2O(char * chk) {
	if (strcmp(chk, "000") == 0)
		printf("0");
	else if (strcmp(chk, "001") == 0)
		printf("1");
	else if (strcmp(chk, "010") == 0)
		printf("2");
	else if (strcmp(chk, "011") == 0)
		printf("3");
	else if (strcmp(chk, "100") == 0)
		printf("4");
	else if (strcmp(chk, "101") == 0)
		printf("5");
	else if (strcmp(chk, "110") == 0)
		printf("6");
	else if (strcmp(chk, "111") == 0)
		printf("7");
}

int main() {
	char msg[200];
	scanf("%s", msg);
	char chk[4] = { 0,0,0,0 };
	if (strlen(msg) % 3 == 0) {
		for (int i = 0; i < strlen(msg); ++i) {
			chk[i % 3] = msg[i];
			if (i % 3 == 2)
				B2O(chk);
		}
	}
	else {
		stack<char> tmp;
		for (int i = strlen(msg) - 1; i >= 0; --i) 
			tmp.push(msg[i]);
		for (int i = 0; i < 3 - strlen(msg) % 3; ++i)
			tmp.push('0');
		while (tmp.size()) {
			for (int i = 0; i < 3; ++i) {
				chk[i] = tmp.top();
				tmp.pop();
			}
			B2O(chk);
		}
	}
}